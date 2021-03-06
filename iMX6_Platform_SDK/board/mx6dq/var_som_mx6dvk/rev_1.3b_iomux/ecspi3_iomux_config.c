/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
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
 */

// File: ecspi3_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.4.0.4
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "registers/regsiomuxc.h"

// Function to configure IOMUXC for ecspi3 module.
void ecspi3_iomux_config(void)
{
    // Config ecspi3.ECSPI3_MISO to pad DISP0_DATA02(P23)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA02_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA02(0x020E0178)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_DISP0_DATA02
    //     ALT1 (1) - Select instance: ipu2 signal: IPU2_DISP0_DATA02
    //     ALT2 (2) - Select instance: ecspi3 signal: ECSPI3_MISO
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO23
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA02_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA02_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA02_MUX_MODE_V(ALT2));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02(0x020E048C)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02_SRE_V(SLOW));

    // Config ecspi3.ECSPI3_MOSI to pad DISP0_DATA01(P22)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA01_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA01(0x020E0174)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_DISP0_DATA01
    //     ALT1 (1) - Select instance: ipu2 signal: IPU2_DISP0_DATA01
    //     ALT2 (2) - Select instance: ecspi3 signal: ECSPI3_MOSI
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO22
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA01_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA01_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA01_MUX_MODE_V(ALT2));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01(0x020E0488)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01_SRE_V(SLOW));

    // Config ecspi3.ECSPI3_SCLK to pad DISP0_DATA00(P24)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA00_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA00(0x020E0170)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_DISP0_DATA00
    //     ALT1 (1) - Select instance: ipu2 signal: IPU2_DISP0_DATA00
    //     ALT2 (2) - Select instance: ecspi3 signal: ECSPI3_SCLK
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO21
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA00_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA00_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA00_MUX_MODE_V(ALT2));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00(0x020E0484)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00_SRE_V(SLOW));

    // Config ecspi3.ECSPI3_SS0 to pad DISP0_DATA03(P21)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA03_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA03(0x020E017C)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_DISP0_DATA03
    //     ALT1 (1) - Select instance: ipu2 signal: IPU2_DISP0_DATA03
    //     ALT2 (2) - Select instance: ecspi3 signal: ECSPI3_SS0
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO24
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA03_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA03_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA03_MUX_MODE_V(ALT2));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03(0x020E0490)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03_SRE_V(SLOW));
}
