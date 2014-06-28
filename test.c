#define INVALID_PARAMETER (-1)
#define SUCCESS (0)

int gpio_set_gpio(int32_t port, int32_t pin)
{
    // Validate port and pin before indexing into the map arrays.
    if (port < 1 || port > HW_GPIO_INSTANCE_COUNT || pin < 0 || pin > 31)
    {
        //debug_printf("Invalid GPIO port or pin number.\n");
        return INVALID_PARAMETER;
    }

    // Look up mux register address.
    uint32_t addr = k_gpio_mux_registers[port - 1][pin];
    if (!addr)
    {
        return INVALID_PARAMETER;
    }

    volatile uint32_t * reg = (volatile uint32_t *)addr;

    // Switch mux to ALT5, which is always GPIO mode. We're just using this register's
    // BM_ and BF_ macros because they are convenient, and is present on all three mx6.
    *reg = (*reg & ~BM_IOMUXC_SW_MUX_CTL_PAD_KEY_COL0_MUX_MODE)
         | BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL0_MUX_MODE_V(ALT5);

    return SUCCESS;
}

int32_t gpio_set_direction(int32_t port, int32_t pin, int32_t dir)
{
    uint32_t oldVal = 0, newVal = 0;

    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        //debug_printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
            port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        //debug_printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    oldVal = HW_GPIO_GDIR_RD(port);

    if (dir == GPIO_GDIR_INPUT)
        newVal = oldVal & (~(1 << pin));
    else
        newVal = oldVal | (1 << pin);

    HW_GPIO_GDIR_WR(port, newVal);

    return 0; //SUCCESS;
}

int32_t gpio_set_level(int32_t port, int32_t pin, uint32_t level)
{
    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        //debug_printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
        //    port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        //debug_printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    uint32_t mask = 1 << pin;

    int32_t dir = HW_GPIO_GDIR_RD(port) & mask ? GPIO_GDIR_OUTPUT : GPIO_GDIR_INPUT;

    if (dir != GPIO_GDIR_OUTPUT)
    {
        //printf("GPIO_PORT%d_%d is not configured to be output!\n", port, pin);
        return -1;
    }

    uint32_t value = HW_GPIO_DR_RD(port);   // read current value

    if (level == GPIO_LOW_LEVEL)            // fix it up
      value &= ~mask;
    else if ( level == GPIO_HIGH_LEVEL)
      value |= mask;

    HW_GPIO_DR_WR(port, value);             // write new value

    return 0; //SUCCESS;
}

int main(int argc, char * argv[]) {
	uint8_t m_bank = 1, m_pin = 2;
	if (gpio_set_gpio(m_bank, m_pin) == INVALID_PARAMETER)
	{
		//printf("gpio_set_gpio failed");
		return 0x1210;
	}
	if (gpio_set_direction(m_bank, m_pin, GPIO_GDIR_OUTPUT) == INVALID_PARAMETER)
	{
		//printf("gpio_set_direction failed");
		return 0x1211;
	}

	if (gpio_set_level(m_bank, m_pin, GPIO_HIGH_LEVEL))
	{
		//printf("gpio_set_level failed");
		return 0x1214;
	}
	return 0x1212;
}
