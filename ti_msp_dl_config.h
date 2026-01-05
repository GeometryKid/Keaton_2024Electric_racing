/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_Motor */
#define PWM_Motor_INST                                                     TIMG0
#define PWM_Motor_INST_IRQHandler                               TIMG0_IRQHandler
#define PWM_Motor_INST_INT_IRQN                                 (TIMG0_INT_IRQn)
#define PWM_Motor_INST_CLK_FREQ                                         32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Motor_C0_PORT                                             GPIOA
#define GPIO_PWM_Motor_C0_PIN                                     DL_GPIO_PIN_12
#define GPIO_PWM_Motor_C0_IOMUX                                  (IOMUX_PINCM34)
#define GPIO_PWM_Motor_C0_IOMUX_FUNC                 IOMUX_PINCM34_PF_TIMG0_CCP0
#define GPIO_PWM_Motor_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_Motor_C1_PORT                                             GPIOA
#define GPIO_PWM_Motor_C1_PIN                                     DL_GPIO_PIN_13
#define GPIO_PWM_Motor_C1_IOMUX                                  (IOMUX_PINCM35)
#define GPIO_PWM_Motor_C1_IOMUX_FUNC                 IOMUX_PINCM35_PF_TIMG0_CCP1
#define GPIO_PWM_Motor_C1_IDX                                DL_TIMER_CC_1_INDEX




/* Defines for QEI_0 */
#define QEI_0_INST                                                         TIMG8
#define QEI_0_INST_IRQHandler                                   TIMG8_IRQHandler
#define QEI_0_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
/* Pin configuration defines for QEI_0 PHA Pin */
#define GPIO_QEI_0_PHA_PORT                                                GPIOA
#define GPIO_QEI_0_PHA_PIN                                        DL_GPIO_PIN_21
#define GPIO_QEI_0_PHA_IOMUX                                     (IOMUX_PINCM46)
#define GPIO_QEI_0_PHA_IOMUX_FUNC                    IOMUX_PINCM46_PF_TIMG8_CCP0
/* Pin configuration defines for QEI_0 PHB Pin */
#define GPIO_QEI_0_PHB_PORT                                                GPIOA
#define GPIO_QEI_0_PHB_PIN                                         DL_GPIO_PIN_2
#define GPIO_QEI_0_PHB_IOMUX                                      (IOMUX_PINCM7)
#define GPIO_QEI_0_PHB_IOMUX_FUNC                     IOMUX_PINCM7_PF_TIMG8_CCP1


/* Defines for TIMER_Sensor */
#define TIMER_Sensor_INST                                                (TIMG6)
#define TIMER_Sensor_INST_IRQHandler                            TIMG6_IRQHandler
#define TIMER_Sensor_INST_INT_IRQN                              (TIMG6_INT_IRQn)
#define TIMER_Sensor_INST_LOAD_VALUE                                     (2184U)



/* Defines for UART_JY61P */
#define UART_JY61P_INST                                                    UART0
#define UART_JY61P_INST_IRQHandler                              UART0_IRQHandler
#define UART_JY61P_INST_INT_IRQN                                  UART0_INT_IRQn
#define GPIO_UART_JY61P_RX_PORT                                            GPIOA
#define GPIO_UART_JY61P_TX_PORT                                            GPIOA
#define GPIO_UART_JY61P_RX_PIN                                    DL_GPIO_PIN_31
#define GPIO_UART_JY61P_TX_PIN                                    DL_GPIO_PIN_28
#define GPIO_UART_JY61P_IOMUX_RX                                  (IOMUX_PINCM6)
#define GPIO_UART_JY61P_IOMUX_TX                                  (IOMUX_PINCM3)
#define GPIO_UART_JY61P_IOMUX_RX_FUNC                   IOMUX_PINCM6_PF_UART0_RX
#define GPIO_UART_JY61P_IOMUX_TX_FUNC                   IOMUX_PINCM3_PF_UART0_TX
#define UART_JY61P_BAUD_RATE                                              (9600)
#define UART_JY61P_IBRD_32_MHZ_9600_BAUD                                   (208)
#define UART_JY61P_FBRD_32_MHZ_9600_BAUD                                    (21)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOB
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_9
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_4
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM20)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM17)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM20_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM17_PF_UART1_TX
#define UART_1_BAUD_RATE                                                  (9600)
#define UART_1_IBRD_4_MHZ_9600_BAUD                                         (26)
#define UART_1_FBRD_4_MHZ_9600_BAUD                                          (3)





/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOB)

/* Defines for K1: GPIOB.21 with pinCMx 49 on package pin 20 */
// pins affected by this interrupt request:["K1"]
#define KEY_INT_IRQN                                            (GPIOB_INT_IRQn)
#define KEY_INT_IIDX                            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define KEY_K1_IIDX                                         (DL_GPIO_IIDX_DIO21)
#define KEY_K1_PIN                                              (DL_GPIO_PIN_21)
#define KEY_K1_IOMUX                                             (IOMUX_PINCM49)
/* Defines for K2: GPIOB.23 with pinCMx 51 on package pin 22 */
#define KEY_K2_PIN                                              (DL_GPIO_PIN_23)
#define KEY_K2_IOMUX                                             (IOMUX_PINCM51)
/* Defines for K3: GPIOB.24 with pinCMx 52 on package pin 23 */
#define KEY_K3_PIN                                              (DL_GPIO_PIN_24)
#define KEY_K3_IOMUX                                             (IOMUX_PINCM52)
/* Port definition for Pin Group Motor */
#define Motor_PORT                                                       (GPIOA)

/* Defines for AIN1: GPIOA.14 with pinCMx 36 on package pin 7 */
#define Motor_AIN1_PIN                                          (DL_GPIO_PIN_14)
#define Motor_AIN1_IOMUX                                         (IOMUX_PINCM36)
/* Defines for AIN2: GPIOA.16 with pinCMx 38 on package pin 9 */
#define Motor_AIN2_PIN                                          (DL_GPIO_PIN_16)
#define Motor_AIN2_IOMUX                                         (IOMUX_PINCM38)
/* Defines for BIN1: GPIOA.15 with pinCMx 37 on package pin 8 */
#define Motor_BIN1_PIN                                          (DL_GPIO_PIN_15)
#define Motor_BIN1_IOMUX                                         (IOMUX_PINCM37)
/* Defines for BIN2: GPIOA.17 with pinCMx 39 on package pin 10 */
#define Motor_BIN2_PIN                                          (DL_GPIO_PIN_17)
#define Motor_BIN2_IOMUX                                         (IOMUX_PINCM39)
/* Port definition for Pin Group GPIO_EncoderA */
#define GPIO_EncoderA_PORT                                               (GPIOA)

/* Defines for PIN_8: GPIOA.8 with pinCMx 19 on package pin 54 */
// pins affected by this interrupt request:["PIN_8","PIN_7"]
#define GPIO_EncoderA_INT_IRQN                                  (GPIOA_INT_IRQn)
#define GPIO_EncoderA_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_EncoderA_PIN_8_IIDX                             (DL_GPIO_IIDX_DIO8)
#define GPIO_EncoderA_PIN_8_PIN                                  (DL_GPIO_PIN_8)
#define GPIO_EncoderA_PIN_8_IOMUX                                (IOMUX_PINCM19)
/* Defines for PIN_7: GPIOA.7 with pinCMx 14 on package pin 49 */
#define GPIO_EncoderA_PIN_7_IIDX                             (DL_GPIO_IIDX_DIO7)
#define GPIO_EncoderA_PIN_7_PIN                                  (DL_GPIO_PIN_7)
#define GPIO_EncoderA_PIN_7_IOMUX                                (IOMUX_PINCM14)
/* Port definition for Pin Group sensor */
#define sensor_PORT                                                      (GPIOA)

/* Defines for PIN_3: GPIOA.3 with pinCMx 8 on package pin 43 */
#define sensor_PIN_3_PIN                                         (DL_GPIO_PIN_3)
#define sensor_PIN_3_IOMUX                                        (IOMUX_PINCM8)
/* Defines for PIN_4: GPIOA.4 with pinCMx 9 on package pin 44 */
#define sensor_PIN_4_PIN                                         (DL_GPIO_PIN_4)
#define sensor_PIN_4_IOMUX                                        (IOMUX_PINCM9)
/* Defines for PIN_5: GPIOA.5 with pinCMx 10 on package pin 45 */
#define sensor_PIN_5_PIN                                         (DL_GPIO_PIN_5)
#define sensor_PIN_5_IOMUX                                       (IOMUX_PINCM10)
/* Defines for PIN_6: GPIOA.6 with pinCMx 11 on package pin 46 */
#define sensor_PIN_6_PIN                                         (DL_GPIO_PIN_6)
#define sensor_PIN_6_IOMUX                                       (IOMUX_PINCM11)
/* Defines for BSL: GPIOA.18 with pinCMx 40 on package pin 11 */
#define sensor_BSL_PIN                                          (DL_GPIO_PIN_18)
#define sensor_BSL_IOMUX                                         (IOMUX_PINCM40)
/* Port definition for Pin Group OLED */
#define OLED_PORT                                                        (GPIOA)

/* Defines for SCL: GPIOA.0 with pinCMx 1 on package pin 33 */
#define OLED_SCL_PIN                                             (DL_GPIO_PIN_0)
#define OLED_SCL_IOMUX                                            (IOMUX_PINCM1)
/* Defines for SDA: GPIOA.1 with pinCMx 2 on package pin 34 */
#define OLED_SDA_PIN                                             (DL_GPIO_PIN_1)
#define OLED_SDA_IOMUX                                            (IOMUX_PINCM2)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_Motor_init(void);
void SYSCFG_DL_QEI_0_init(void);
void SYSCFG_DL_TIMER_Sensor_init(void);
void SYSCFG_DL_UART_JY61P_init(void);
void SYSCFG_DL_UART_1_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
