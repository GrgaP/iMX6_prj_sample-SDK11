/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Modified by Leon George <l.george@fu-berlin.de>
 */

#include "kernel_internal.h"

#include "sdk.h"
#include "imx_uart.h"
#include "gic.h"
#include "ccm_pll.h"
#include "board.h"
//#include "board_io_expanders.h"
#include "platform_init.h"
#include "periph_conf.h"
#include "cortex_a9.h"
#include "mmu.h"
#include "registers/regsarmglobaltimer.h"


uint32_t g_microsecondTimerMultiple;

//! Init the ARM global timer to a microsecond-frequency clock.
void time_init_global_timer(void)
{
    // The ARM private peripheral clock is half the CPU clock.
    uint32_t periphClock = get_main_clock(CPU_CLK) / 2;
    uint32_t prescaler = (periphClock / 1000000) - 1;

    // Divide down the prescaler until it fits into 8 bits. We add up the number of ticks
    // it takes to equal a microsecond interval.
    g_microsecondTimerMultiple = 1;
    while (prescaler > 0xff)
    {
        prescaler /= 2;
        ++g_microsecondTimerMultiple;
    }

    // Make sure the timer is off.
    HW_ARMGLOBALTIMER_CONTROL.B.TIMER_ENABLE = 0;

    // Clear counter.
    HW_ARMGLOBALTIMER_COUNTERn_WR(0, 0);
    HW_ARMGLOBALTIMER_COUNTERn_WR(1, 0);

    // Set prescaler and clear other flags.
    HW_ARMGLOBALTIMER_CONTROL_WR(BF_ARMGLOBALTIMER_CONTROL_PRESCALER(prescaler));

    // Now turn on the timer.
    HW_ARMGLOBALTIMER_CONTROL.B.TIMER_ENABLE = 1;
}

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void platform_init(void)
{
    enable_neon_fpu();
    disable_strict_align_check();
    mmu_init();

    // Map some SDRAM for DMA
		// TODO how is this relevant for the riotboard?
#if defined(BOARD_EVB)
    mmu_map_l1_range(0x30000000, 0x30000000, 0x70000000, kNoncacheable, kShareable, kRWAccess);
#elif defined(BOARD_SMART_DEVICE)
    mmu_map_l1_range(0x20000000, 0x20000000, 0x30000000, kNoncacheable, kShareable, kRWAccess);
#endif

    // Enable interrupts. Until this point, the startup code has left interrupts disabled.
    gic_init();
		enableIRQ();

    // Initialize clock sources, dividers, ...
    ccm_init();


		time_init_global_timer();

    // Initialize the debug/console UART
    uart_init(STDIO_UART, 115200, PARITY_NONE, STOPBITS_ONE, EIGHTBITS, FLOWCTRL_OFF);

    // flush UART RX FIFO
    uint8_t c;
    do {
        c = uart_getchar(STDIO_UART);
    } while (c != NONE_CHAR);

    // Some init for the board
		// TODO right now boards can't use this
    //board_ioexpander_init();

		board_init();

		kernel_init();
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
