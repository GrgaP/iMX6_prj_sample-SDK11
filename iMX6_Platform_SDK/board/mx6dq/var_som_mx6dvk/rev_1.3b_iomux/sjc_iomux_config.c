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

// File: sjc_iomux_config.c

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

// Function to configure IOMUXC for sjc module.
void sjc_iomux_config(void)
{
    // Config sjc.JTAG_MOD to pad JTAG_MOD(H6)
    // HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD_WR(0x0000B060);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD(0x020E067C)
    //   HYS [16] - Hysteresis Enable Field Reset: DISABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 50MHZ
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 60_OHM
    //               NOTE: Read Only Field
    //               The value of this field is fixed and cannot be changed.
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
    //             NOTE: Read Only Field
    //             The value of this field is fixed and cannot be changed.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD_HYS_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD_PKE_V(ENABLED));

    // Config sjc.JTAG_TCK to pad JTAG_TCK(H5)
    // HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK_WR(0x00007060);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK(0x020E0688)
    //   HYS [16] - Hysteresis Enable Field Reset: DISABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 47K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 50MHZ
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 60_OHM
    //               NOTE: Read Only Field
    //               The value of this field is fixed and cannot be changed.
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
    //             NOTE: Read Only Field
    //             The value of this field is fixed and cannot be changed.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK_HYS_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK_PUS_V(47K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK_PKE_V(ENABLED));

    // Config sjc.JTAG_TDI to pad JTAG_TDI(G5)
    // HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI_WR(0x00007060);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI(0x020E0684)
    //   HYS [16] - Hysteresis Enable Field Reset: DISABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 47K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 50MHZ
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 60_OHM
    //               NOTE: Read Only Field
    //               The value of this field is fixed and cannot be changed.
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
    //             NOTE: Read Only Field
    //             The value of this field is fixed and cannot be changed.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI_HYS_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI_PUS_V(47K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI_PKE_V(ENABLED));

    // Config sjc.JTAG_TDO to pad JTAG_TDO(G6)
    // HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TDO_WR(0x000090B1);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_JTAG_TDO(0x020E068C)
    //   HYS [16] - Hysteresis Enable Field Reset: DISABLED
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: KEEP
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //               NOTE: Read Only Field
    //               The value of this field is fixed and cannot be changed.
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: FAST
    //             Slew rate control.
    //             NOTE: Read Only Field
    //             The value of this field is fixed and cannot be changed.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TDO_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TDO_PKE_V(ENABLED));

    // Config sjc.JTAG_TMS to pad JTAG_TMS(C3)
    // HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS_WR(0x00007060);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS(0x020E0678)
    //   HYS [16] - Hysteresis Enable Field Reset: DISABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 47K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 50MHZ
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 60_OHM
    //               NOTE: Read Only Field
    //               The value of this field is fixed and cannot be changed.
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
    //             NOTE: Read Only Field
    //             The value of this field is fixed and cannot be changed.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS_HYS_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS_PUS_V(47K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS_PKE_V(ENABLED));

    // Config sjc.JTAG_TRSTB to pad JTAG_TRSTB(C2)
    // HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB_WR(0x00007060);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB(0x020E0680)
    //   HYS [16] - Hysteresis Enable Field Reset: DISABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 47K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //              NOTE: Read Only Field
    //              The value of this field is fixed and cannot be changed.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 50MHZ
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 60_OHM
    //               NOTE: Read Only Field
    //               The value of this field is fixed and cannot be changed.
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
    //             NOTE: Read Only Field
    //             The value of this field is fixed and cannot be changed.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB_HYS_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB_PUS_V(47K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB_PKE_V(ENABLED));
}
