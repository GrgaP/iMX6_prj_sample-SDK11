#include "uses.h"
#include "stdlib.h"

void main(void) {
  uint8_t m_bank = 1, m_pin = 2;
	if (gpio_set_gpio(m_bank, m_pin) == INVALID_PARAMETER)
	{
	  printf("gpio_set_gpio failed");
	  break;
	}
	if (gpio_set_direction(m_bank, m_pin, GPIO_GDIR_OUTPUT) == INVALID_PARAMETER)
	{
	  printf("gpio_set_direction failed");
	  break;
	} 
	
	if (gpio_set_level(m_bank, m_pin, GPIO_HIGH_LEVEL))
	{
	  printf("gpio_set_level failed");
	  break;
	}
	return ;
}
