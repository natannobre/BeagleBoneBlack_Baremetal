/** ============================================================================
 *   \file  soc_AM33XX.h
 *
 *   \brief This file contains the peripheral information for AM33XX SoC
 *
 *  ============================================================================
 */

/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


#ifndef _SOC_AM33XX_H_
#define _SOC_AM33XX_H_

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************\
 * Registers Definition
\*************************************************************************/
#define INTC_REVISION 							(0x0)
#define INTC_SYSCONFIG 							(0x10)
#define INTC_SYSSTATUS 							(0x14)
#define INTC_SIR_IRQ 							(0x40)
#define INTC_SIR_FIQ 							(0x44)
#define INTC_CONTROL 							(0x48)
#define INTC_PROTECTION 						(0x4c)
#define INTC_IDLE  								(0x50)
#define INTC_IRQ_PRIORITY 						(0x60)
#define INTC_FIQ_PRIORITY 						(0x64)
#define INTC_THRESHOLD 							(0x68)
#define INTC_SICR  								(0x6c)
#define INTC_SCR(n) 							(0x70 + ((n) * 0x04))
#define INTC_ITR(n) 							(0x80 + ((n) * 0x20))
#define INTC_MIR(n) 							(0x84 + ((n) * 0x20))
#define INTC_MIR_CLEAR(n) 						(0x88 + ((n) * 0x20))
#define INTC_MIR_SET(n) 						(0x8c + ((n) * 0x20))
#define INTC_ISR_SET(n) 						(0x90 + ((n) * 0x20))
#define INTC_ISR_CLEAR(n) 						(0x94 + ((n) * 0x20))
#define INTC_PENDING_IRQ(n) 					(0x98 + ((n) * 0x20))
#define INTC_PENDING_FIQ(n) 					(0x9c + ((n) * 0x20))
#define INTC_ILR(n)  							(0x100 + ((n) * 0x04))

/* REVISION */
#define INTC_REVISION_REV    					(0x000000FFu)
#define INTC_REVISION_REV_SHIFT  				(0x00000000u)

/* SYSCONFIG */
#define INTC_SYSCONFIG_SOFTRESET    			(0x00000002u)
#define INTC_SYSCONFIG_SOFTRESET_SHIFT  		(0x00000001u)

#define INTC_SYSCONFIG_AUTOIDLE    				(0x00000001u)
#define INTC_SYSCONFIG_AUTOIDLE_SHIFT  			(0x00000000u)

/* SYSSTATUS */
#define INTC_SYSSTATUS_RESETDONE    			(0x00000001u)
#define INTC_SYSSTATUS_RESETDONE_SHIFT  		(0x00000000u)

/* THRESHOLD */
#define INTC_THRESHOLD_PRIORITYTHRESHOLD    	(0x000000FFu)
#define INTC_THRESHOLD_PRIORITYTHRESHOLD_SHIFT  (0x00000000u)

/* ILR */
#define INTC_ILR_PRIORITY    				 	(0x000001FCu)
#define INTC_ILR_PRIORITY_SHIFT  			 	(0x00000002u)


/** Cache Line size in ARM Cortex-A8.                                         */
#define SOC_CACHELINE_SIZE_MAX               (64)

/** @brief Base address of AINTC memory mapped registers                      */
#define SOC_AINTC_REGS                       (0x48200000)

/** @brief Base addresses of UART memory mapped registers                     */
#define SOC_UART_0_REGS                      (0x44E09000)
#define SOC_UART_1_REGS                      (0x48022000)
#define SOC_UART_2_REGS                      (0x48024000)
#define SOC_UART_3_REGS                      (0x481A6000)
#define SOC_UART_4_REGS                      (0x481A8000)
#define SOC_UART_5_REGS                      (0x481AA000)

/** @brief Base addresses of USB memory mapped registers                     */
#define SOC_USB_0_BASE                       (0x47401400)
#define SOC_USB_1_BASE                       (0x47401C00)
/** @brief Base addresses of SPI memory mapped registers                      */
#define SOC_SPI_0_REGS                       (0x48030000)
#define SOC_SPI_1_REGS                       (0x481A0000)

/** @brief Base addresses of GPIO memory mapped registers                     */
#define SOC_GPIO_0_REGS                      (0x44E07000)
#define SOC_GPIO_1_REGS                      (0x4804C000)
#define SOC_GPIO_2_REGS                      (0x481AC000)
#define SOC_GPIO_3_REGS                      (0x481AE000)

/** @brief Base addresses of DMTIMER memory mapped registers                  */
#define SOC_DMTIMER_0_REGS                   (0x44E05000)
#define SOC_DMTIMER_1_REGS                   (0x44E31000)
#define SOC_DMTIMER_2_REGS                   (0x48040000)
#define SOC_DMTIMER_3_REGS                   (0x48042000)
#define SOC_DMTIMER_4_REGS                   (0x48044000)
#define SOC_DMTIMER_5_REGS                   (0x48046000)
#define SOC_DMTIMER_6_REGS                   (0x48048000)
#define SOC_DMTIMER_7_REGS                   (0x4804A000)

/** @brief Base address of MMC memory mapped registers                        */
#define SOC_MMCHS_0_REGS                     (0x48060000)
#define SOC_MMCHS_1_REGS                     (0x481D8000)
#define SOC_MMCHS_2_REGS                     (0x47810000)

/** @brief Base address of GPMC memory mapped registers                       */
#define SOC_GPMC_0_REGS                      (0x50000000)

/** @brief Base address of GPMC memory mapped registers                       */
#define SOC_ELM_0_REGS                       (0x48080000)

/** @brief Base address of I2C memory mapped registers                        */
#define SOC_I2C_0_REGS                       (0x44E0B000)
#define SOC_I2C_1_REGS                       (0x4802A000)
#define SOC_I2C_2_REGS                       (0x4819C000)

/** @brief Base address of WDT memory mapped registers                        */
#define SOC_WDT_1_REGS0_REGS                       (0x44E33000)
#define SOC_WDT_1_REGS                       (0x44E35000)

/** @brief Base address of WDT memory mapped registers                        */
#define SOC_CPSW_SS_REGS                     (0x4A100000)
#define SOC_CPSW_MDIO_REGS                   (0x4A101000)
#define SOC_CPSW_WR_REGS                     (0x4A101200)
#define SOC_CPSW_CPDMA_REGS                  (0x4A100800)
#define SOC_CPSW_ALE_REGS                    (0x4A100D00)
#define SOC_CPSW_STAT_REGS                   (0x4A100900)
#define SOC_CPSW_PORT_0_REGS                 (0x4A100100)
#define SOC_CPSW_PORT_1_REGS                 (0x4A100200)
#define SOC_CPSW_SLIVER_1_REGS               (0x4A100D80)
#define SOC_CPSW_PORT_2_REGS                 (0x4A100300)
#define SOC_CPSW_SLIVER_2_REGS               (0x4A100DC0)
#define SOC_CPSW_CPPI_RAM_REGS               (0x4A102000)

/** @brief Base address of McASP memory mapped registers                      */
#define SOC_MCASP_0_CTRL_REGS                (0x48038000)
#define SOC_MCASP_0_FIFO_REGS                (SOC_MCASP_0_CTRL_REGS + 0x1000)
#define SOC_MCASP_0_DATA_REGS                (0x46000000)
#define SOC_MCASP_1_CTRL_REGS                (0x4803C000)
#define SOC_MCASP_1_FIFO_REGS                (SOC_MCASP_1_CTRL_REGS + 0x1000)
#define SOC_MCASP_1_DATA_REGS                (0x46400000)

/** @brief Base address of EMIF memory mapped registers                       */
#define SOC_EMIF_0_REGS                      (0x4C000000)

/** @brief Base addresses of RTC memory mapped registers                      */
#define SOC_RTC_0_REGS                       (0x44E3E000)

/** @brief Base addresses of PRCM memory mapped registers                     */
#define SOC_PRCM_REGS                        (0x44E00000)
#define SOC_CM_PER_REGS                      (SOC_PRCM_REGS + 0)
#define SOC_CM_WKUP_REGS                     (SOC_PRCM_REGS + 0x400)
#define SOC_CM_DPLL_REGS                     (SOC_PRCM_REGS + 0x500)
#define SOC_CM_MPU_REGS                      (SOC_PRCM_REGS + 0x600)
#define SOC_CM_DEVICE_REGS                   (SOC_PRCM_REGS + 0x700)
#define SOC_CM_RTC_REGS                      (SOC_PRCM_REGS + 0x800)
#define SOC_CM_GFX_REGS                      (SOC_PRCM_REGS + 0x900)
#define SOC_CM_CEFUSE_REGS                   (SOC_PRCM_REGS + 0xA00)
#define SOC_OCP_SOCKET_RAM_REGS              (SOC_PRCM_REGS + 0xB00)
#define SOC_PRM_PER_REGS                     (SOC_PRCM_REGS + 0xC00)
#define SOC_PRM_WKUP_REGS                    (SOC_PRCM_REGS + 0xD00)
#define SOC_PRM_MPU_REGS                     (SOC_PRCM_REGS + 0xE00)
#define SOC_PRM_DEVICE_REGS                  (SOC_PRCM_REGS + 0xF00)
#define SOC_PRM_RTC_REGS                     (SOC_PRCM_REGS + 0x1000)
#define SOC_PRM_GFX_REGS                     (SOC_PRCM_REGS + 0x1100)
#define SOC_PRM_CEFUSE_REGS                  (SOC_PRCM_REGS + 0x1200)

/** @brief Base address of control module memory mapped registers             */
#define SOC_CONTROL_REGS                     (0x44E10000)


/** @brief Base address of Channel controller  memory mapped registers        */
#define SOC_EDMA30CC_0_REGS                  (0x49000000)

/** @brief Base address of DCAN module memory mapped registers                */
#define SOC_DCAN_0_REGS                      (0x481CC000) 
#define SOC_DCAN_1_REGS                      (0x481D0000) 

/******************************************************************************\
*  Parameterizable Configuration:- These are fed directly from the RTL
*  parameters for the given SOC
\******************************************************************************/
#define TPCC_MUX(n)                         0xF90 + ((n) * 4)


#define SOC_LCDC_0_REGS                     0x4830E000

#define SOC_ADC_TSC_0_REGS                  0x44E0D000

/** @brief Base addresses of PWMSS memory mapped registers.                   */

#define SOC_PWMSS0_REGS                     (0x48300000)
#define SOC_PWMSS1_REGS                     (0x48302000)
#define SOC_PWMSS2_REGS                     (0x48304000)

#define SOC_ECAP_REGS                       (0x00000100)
#define SOC_EQEP_REGS                       (0x00000180)
#define SOC_EPWM_REGS                       (0x00000200)

#define SOC_ECAP_0_REGS                     (SOC_PWMSS0_REGS + SOC_ECAP_REGS)
#define SOC_ECAP_1_REGS                     (SOC_PWMSS1_REGS + SOC_ECAP_REGS)
#define SOC_ECAP_2_REGS                     (SOC_PWMSS2_REGS + SOC_ECAP_REGS)

#define SOC_EQEP_0_REGS                     (SOC_PWMSS0_REGS + SOC_EQEP_REGS)
#define SOC_EQEP_1_REGS                     (SOC_PWMSS1_REGS + SOC_EQEP_REGS)
#define SOC_EQEP_2_REGS                     (SOC_PWMSS2_REGS + SOC_EQEP_REGS) 

#define SOC_EPWM_0_REGS                     (SOC_PWMSS0_REGS + SOC_EPWM_REGS)
#define SOC_EPWM_1_REGS                     (SOC_PWMSS1_REGS + SOC_EPWM_REGS)
#define SOC_EPWM_2_REGS                     (SOC_PWMSS2_REGS + SOC_EPWM_REGS)


#define SOC_EPWM_MODULE_FREQ                 100 
 
#ifdef __cplusplus
}
#endif

#endif  /* _SOC_AM33XX_H_ */
