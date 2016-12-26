/*
 * STM32 capabilities definitions.
 *
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STM32_CAPABILITIES_H_
#define STM32_CAPABILITIES_H_

#include <stdint.h>

/*
 * This file defines the members used in the structure used to describe
 * the capabilities of the STM32 MCUs.
 *
 * STM32 MCUs are grouped by families and sub-families.
 */

#define TYPE_STM32_PREFIX       "stm32:"
#define TYPE_STM32F1_PREFIX     "stm32f1:"
#define TYPE_STM32F1CL_PREFIX   "stm32f1cl:"

#define DEVICE_PATH_STM32 "/machine/mcu/stm32/"

/*
 * The family is the main differentiator for STM32 MCUs.
 */
typedef enum {
    STM32_FAMILY_UNKNOWN,
    STM32_FAMILY_F0,
    STM32_FAMILY_F1,
    STM32_FAMILY_F2,
    STM32_FAMILY_F3,
    STM32_FAMILY_F4,
    STM32_FAMILY_F7,
    STM32_FAMILY_H7,
    STM32_FAMILY_L0,
    STM32_FAMILY_L1,
    STM32_FAMILY_L4,
} stm32_family_t;

#define STM32_MAX_GPIO  (8)
#define STM32_MAX_USART (6)

typedef enum {
    STM32F051XX_WWDG_IRQn = 0, /*!< Window WatchDog Interrupt                               */
    STM32F051XX_PVD_IRQn = 1, /*!< PVD Interrupt through EXTI Lines 16                             */
    STM32F051XX_RTC_IRQn = 2, /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
    STM32F051XX_FLASH_IRQn = 3, /*!< FLASH global Interrupt                                          */
    STM32F051XX_RCC_IRQn = 4, /*!< RCC global Interrupt                                            */
    STM32F051XX_EXTI0_1_IRQn = 5, /*!< EXTI Line 0 and 1 Interrupt                                     */
    STM32F051XX_EXTI2_3_IRQn = 6, /*!< EXTI Line 2 and 3 Interrupt                                     */
    STM32F051XX_EXTI4_15_IRQn = 7, /*!< EXTI Line 4 to 15 Interrupt                                     */
    STM32F051XX_TSC_IRQn = 8, /*!< Touch Sensing Controller Interrupts                             */
    STM32F051XX_DMA1_Channel1_IRQn = 9, /*!< DMA1 Channel 1 Interrupt                                        */
    STM32F051XX_DMA1_Channel2_3_IRQn = 10, /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
    STM32F051XX_DMA1_Channel4_5_IRQn = 11, /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
    STM32F051XX_ADC1_COMP_IRQn = 12, /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
    STM32F051XX_TIM1_BRK_UP_TRG_COM_IRQn = 13, /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
    STM32F051XX_TIM1_CC_IRQn = 14, /*!< TIM1 Capture Compare Interrupt                                  */
    STM32F051XX_TIM2_IRQn = 15, /*!< TIM2 global Interrupt                                           */
    STM32F051XX_TIM3_IRQn = 16, /*!< TIM3 global Interrupt                                           */
    STM32F051XX_TIM6_DAC_IRQn = 17, /*!< TIM6 global and DAC channel underrun error Interrupt            */
    STM32F051XX_TIM14_IRQn = 19, /*!< TIM14 global Interrupt                                          */
    STM32F051XX_TIM15_IRQn = 20, /*!< TIM15 global Interrupt                                          */
    STM32F051XX_TIM16_IRQn = 21, /*!< TIM16 global Interrupt                                          */
    STM32F051XX_TIM17_IRQn = 22, /*!< TIM17 global Interrupt                                          */
    STM32F051XX_I2C1_IRQn = 23, /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
    STM32F051XX_I2C2_IRQn = 24, /*!< I2C2 Event Interrupt                                            */
    STM32F051XX_SPI1_IRQn = 25, /*!< SPI1 global Interrupt                                           */
    STM32F051XX_SPI2_IRQn = 26, /*!< SPI2 global Interrupt                                           */
    STM32F051XX_USART1_IRQn = 27, /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
    STM32F051XX_USART2_IRQn = 28, /*!< USART2 global Interrupt                                         */
    STM32F051XX_CEC_CAN_IRQn = 30 /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
} STM32F051XX_IRQn_Type;

typedef enum {
    STM32F10X_MD_WWDG_IRQn = 0, /*!< Window WatchDog Interrupt                            */
    STM32F10X_MD_PVD_IRQn = 1, /*!< PVD through EXTI Line detection Interrupt            */
    STM32F10X_MD_TAMPER_IRQn = 2, /*!< Tamper Interrupt                                     */
    STM32F10X_MD_RTC_IRQn = 3, /*!< RTC global Interrupt                                 */
    STM32F10X_MD_FLASH_IRQn = 4, /*!< FLASH global Interrupt                               */
    STM32F10X_MD_RCC_IRQn = 5, /*!< RCC global Interrupt                                 */
    STM32F10X_MD_EXTI0_IRQn = 6, /*!< EXTI Line0 Interrupt                                 */
    STM32F10X_MD_EXTI1_IRQn = 7, /*!< EXTI Line1 Interrupt                                 */
    STM32F10X_MD_EXTI2_IRQn = 8, /*!< EXTI Line2 Interrupt                                 */
    STM32F10X_MD_EXTI3_IRQn = 9, /*!< EXTI Line3 Interrupt                                 */
    STM32F10X_MD_EXTI4_IRQn = 10, /*!< EXTI Line4 Interrupt                                 */
    STM32F10X_MD_DMA1_Channel1_IRQn = 11, /*!< DMA1 Channel 1 global Interrupt                      */
    STM32F10X_MD_DMA1_Channel2_IRQn = 12, /*!< DMA1 Channel 2 global Interrupt                      */
    STM32F10X_MD_DMA1_Channel3_IRQn = 13, /*!< DMA1 Channel 3 global Interrupt                      */
    STM32F10X_MD_DMA1_Channel4_IRQn = 14, /*!< DMA1 Channel 4 global Interrupt                      */
    STM32F10X_MD_DMA1_Channel5_IRQn = 15, /*!< DMA1 Channel 5 global Interrupt                      */
    STM32F10X_MD_DMA1_Channel6_IRQn = 16, /*!< DMA1 Channel 6 global Interrupt                      */
    STM32F10X_MD_DMA1_Channel7_IRQn = 17, /*!< DMA1 Channel 7 global Interrupt                      */
    STM32F10X_MD_ADC1_2_IRQn = 18, /*!< ADC1 and ADC2 global Interrupt                       */
    STM32F10X_MD_USB_HP_CAN1_TX_IRQn = 19, /*!< USB Device High Priority or CAN1 TX Interrupts       */
    STM32F10X_MD_USB_LP_CAN1_RX0_IRQn = 20, /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
    STM32F10X_MD_CAN1_RX1_IRQn = 21, /*!< CAN1 RX1 Interrupt                                   */
    STM32F10X_MD_CAN1_SCE_IRQn = 22, /*!< CAN1 SCE Interrupt                                   */
    STM32F10X_MD_EXTI9_5_IRQn = 23, /*!< External Line[9:5] Interrupts                        */
    STM32F10X_MD_TIM1_BRK_IRQn = 24, /*!< TIM1 Break Interrupt                                 */
    STM32F10X_MD_TIM1_UP_IRQn = 25, /*!< TIM1 Update Interrupt                                */
    STM32F10X_MD_TIM1_TRG_COM_IRQn = 26, /*!< TIM1 Trigger and Commutation Interrupt               */
    STM32F10X_MD_TIM1_CC_IRQn = 27, /*!< TIM1 Capture Compare Interrupt                       */
    STM32F10X_MD_TIM2_IRQn = 28, /*!< TIM2 global Interrupt                                */
    STM32F10X_MD_TIM3_IRQn = 29, /*!< TIM3 global Interrupt                                */
    STM32F10X_MD_TIM4_IRQn = 30, /*!< TIM4 global Interrupt                                */
    STM32F10X_MD_I2C1_EV_IRQn = 31, /*!< I2C1 Event Interrupt                                 */
    STM32F10X_MD_I2C1_ER_IRQn = 32, /*!< I2C1 Error Interrupt                                 */
    STM32F10X_MD_I2C2_EV_IRQn = 33, /*!< I2C2 Event Interrupt                                 */
    STM32F10X_MD_I2C2_ER_IRQn = 34, /*!< I2C2 Error Interrupt                                 */
    STM32F10X_MD_SPI1_IRQn = 35, /*!< SPI1 global Interrupt                                */
    STM32F10X_MD_SPI2_IRQn = 36, /*!< SPI2 global Interrupt                                */
    STM32F10X_MD_USART1_IRQn = 37, /*!< USART1 global Interrupt                              */
    STM32F10X_MD_USART2_IRQn = 38, /*!< USART2 global Interrupt                              */
    STM32F10X_MD_USART3_IRQn = 39, /*!< USART3 global Interrupt                              */
    STM32F10X_MD_EXTI15_10_IRQn = 40, /*!< External Line[15:10] Interrupts                      */
    STM32F10X_MD_RTCAlarm_IRQn = 41, /*!< RTC Alarm through EXTI Line Interrupt                */
    STM32F10X_MD_USBWakeUp_IRQn = 42 /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
} STM32F10X_MD_IRQn_Type;

typedef enum {
    STM32F10X_CL_WWDG_IRQn = 0, /*!< Window WatchDog Interrupt                            */
    STM32F10X_CL_PVD_IRQn = 1, /*!< PVD through EXTI Line detection Interrupt            */
    STM32F10X_CL_TAMPER_IRQn = 2, /*!< Tamper Interrupt                                     */
    STM32F10X_CL_RTC_IRQn = 3, /*!< RTC global Interrupt                                 */
    STM32F10X_CL_FLASH_IRQn = 4, /*!< FLASH global Interrupt                               */
    STM32F10X_CL_RCC_IRQn = 5, /*!< RCC global Interrupt                                 */
    STM32F10X_CL_EXTI0_IRQn = 6, /*!< EXTI Line0 Interrupt                                 */
    STM32F10X_CL_EXTI1_IRQn = 7, /*!< EXTI Line1 Interrupt                                 */
    STM32F10X_CL_EXTI2_IRQn = 8, /*!< EXTI Line2 Interrupt                                 */
    STM32F10X_CL_EXTI3_IRQn = 9, /*!< EXTI Line3 Interrupt                                 */
    STM32F10X_CL_EXTI4_IRQn = 10, /*!< EXTI Line4 Interrupt                                 */
    STM32F10X_CL_DMA1_Channel1_IRQn = 11, /*!< DMA1 Channel 1 global Interrupt                      */
    STM32F10X_CL_DMA1_Channel2_IRQn = 12, /*!< DMA1 Channel 2 global Interrupt                      */
    STM32F10X_CL_DMA1_Channel3_IRQn = 13, /*!< DMA1 Channel 3 global Interrupt                      */
    STM32F10X_CL_DMA1_Channel4_IRQn = 14, /*!< DMA1 Channel 4 global Interrupt                      */
    STM32F10X_CL_DMA1_Channel5_IRQn = 15, /*!< DMA1 Channel 5 global Interrupt                      */
    STM32F10X_CL_DMA1_Channel6_IRQn = 16, /*!< DMA1 Channel 6 global Interrupt                      */
    STM32F10X_CL_DMA1_Channel7_IRQn = 17, /*!< DMA1 Channel 7 global Interrupt                      */
    STM32F10X_CL_ADC1_2_IRQn = 18, /*!< ADC1 and ADC2 global Interrupt                       */
    STM32F10X_CL_CAN1_TX_IRQn = 19, /*!< USB Device High Priority or CAN1 TX Interrupts       */
    STM32F10X_CL_CAN1_RX0_IRQn = 20, /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
    STM32F10X_CL_CAN1_RX1_IRQn = 21, /*!< CAN1 RX1 Interrupt                                   */
    STM32F10X_CL_CAN1_SCE_IRQn = 22, /*!< CAN1 SCE Interrupt                                   */
    STM32F10X_CL_EXTI9_5_IRQn = 23, /*!< External Line[9:5] Interrupts                        */
    STM32F10X_CL_TIM1_BRK_IRQn = 24, /*!< TIM1 Break Interrupt                                 */
    STM32F10X_CL_TIM1_UP_IRQn = 25, /*!< TIM1 Update Interrupt                                */
    STM32F10X_CL_TIM1_TRG_COM_IRQn = 26, /*!< TIM1 Trigger and Commutation Interrupt               */
    STM32F10X_CL_TIM1_CC_IRQn = 27, /*!< TIM1 Capture Compare Interrupt                       */
    STM32F10X_CL_TIM2_IRQn = 28, /*!< TIM2 global Interrupt                                */
    STM32F10X_CL_TIM3_IRQn = 29, /*!< TIM3 global Interrupt                                */
    STM32F10X_CL_TIM4_IRQn = 30, /*!< TIM4 global Interrupt                                */
    STM32F10X_CL_I2C1_EV_IRQn = 31, /*!< I2C1 Event Interrupt                                 */
    STM32F10X_CL_I2C1_ER_IRQn = 32, /*!< I2C1 Error Interrupt                                 */
    STM32F10X_CL_I2C2_EV_IRQn = 33, /*!< I2C2 Event Interrupt                                 */
    STM32F10X_CL_I2C2_ER_IRQn = 34, /*!< I2C2 Error Interrupt                                 */
    STM32F10X_CL_SPI1_IRQn = 35, /*!< SPI1 global Interrupt                                */
    STM32F10X_CL_SPI2_IRQn = 36, /*!< SPI2 global Interrupt                                */
    STM32F10X_CL_USART1_IRQn = 37, /*!< USART1 global Interrupt                              */
    STM32F10X_CL_USART2_IRQn = 38, /*!< USART2 global Interrupt                              */
    STM32F10X_CL_USART3_IRQn = 39, /*!< USART3 global Interrupt                              */
    STM32F10X_CL_EXTI15_10_IRQn = 40, /*!< External Line[15:10] Interrupts                      */
    STM32F10X_CL_RTCAlarm_IRQn = 41, /*!< RTC Alarm through EXTI Line Interrupt                */
    STM32F10X_CL_OTG_FS_WKUP_IRQn = 42, /*!< USB OTG FS WakeUp from suspend through EXTI Line Interrupt */
    STM32F10X_CL_TIM5_IRQn = 50, /*!< TIM5 global Interrupt                                */
    STM32F10X_CL_SPI3_IRQn = 51, /*!< SPI3 global Interrupt                                */
    STM32F10X_CL_UART4_IRQn = 52, /*!< UART4 global Interrupt                               */
    STM32F10X_CL_UART5_IRQn = 53, /*!< UART5 global Interrupt                               */
    STM32F10X_CL_TIM6_IRQn = 54, /*!< TIM6 global Interrupt                                */
    STM32F10X_CL_TIM7_IRQn = 55, /*!< TIM7 global Interrupt                                */
    STM32F10X_CL_DMA2_Channel1_IRQn = 56, /*!< DMA2 Channel 1 global Interrupt                      */
    STM32F10X_CL_DMA2_Channel2_IRQn = 57, /*!< DMA2 Channel 2 global Interrupt                      */
    STM32F10X_CL_DMA2_Channel3_IRQn = 58, /*!< DMA2 Channel 3 global Interrupt                      */
    STM32F10X_CL_DMA2_Channel4_IRQn = 59, /*!< DMA2 Channel 4 global Interrupt                      */
    STM32F10X_CL_DMA2_Channel5_IRQn = 60, /*!< DMA2 Channel 5 global Interrupt                      */
    STM32F10X_CL_ETH_IRQn = 61, /*!< Ethernet global Interrupt                            */
    STM32F10X_CL_ETH_WKUP_IRQn = 62, /*!< Ethernet Wakeup through EXTI line Interrupt          */
    STM32F10X_CL_CAN2_TX_IRQn = 63, /*!< CAN2 TX Interrupt                                    */
    STM32F10X_CL_CAN2_RX0_IRQn = 64, /*!< CAN2 RX0 Interrupt                                   */
    STM32F10X_CL_CAN2_RX1_IRQn = 65, /*!< CAN2 RX1 Interrupt                                   */
    STM32F10X_CL_CAN2_SCE_IRQn = 66, /*!< CAN2 SCE Interrupt                                   */
    STM32F10X_CL_OTG_FS_IRQn = 67 /*!< USB OTG FS global Interrupt                          */
} STM32F10X_CL_IRQn_Type;

typedef enum {
    STM32F4_01_57_XX_WWDG_IRQn = 0, /*!< Window WatchDog Interrupt                                         */
    STM32F4_01_57_XX_PVD_IRQn = 1, /*!< PVD through EXTI Line detection Interrupt                         */
    STM32F4_01_57_XX_TAMP_STAMP_IRQn = 2, /*!< Tamper and TimeStamp interrupts through the EXTI line             */
    STM32F4_01_57_XX_RTC_WKUP_IRQn = 3, /*!< RTC Wakeup interrupt through the EXTI line                        */
    STM32F4_01_57_XX_FLASH_IRQn = 4, /*!< FLASH global Interrupt                                            */
    STM32F4_01_57_XX_RCC_IRQn = 5, /*!< RCC global Interrupt                                              */
    STM32F4_01_57_XX_EXTI0_IRQn = 6, /*!< EXTI Line0 Interrupt                                              */
    STM32F4_01_57_XX_EXTI1_IRQn = 7, /*!< EXTI Line1 Interrupt                                              */
    STM32F4_01_57_XX_EXTI2_IRQn = 8, /*!< EXTI Line2 Interrupt                                              */
    STM32F4_01_57_XX_EXTI3_IRQn = 9, /*!< EXTI Line3 Interrupt                                              */
    STM32F4_01_57_XX_EXTI4_IRQn = 10, /*!< EXTI Line4 Interrupt                                              */
    STM32F4_01_57_XX_DMA1_Stream0_IRQn = 11, /*!< DMA1 Stream 0 global Interrupt                                    */
    STM32F4_01_57_XX_DMA1_Stream1_IRQn = 12, /*!< DMA1 Stream 1 global Interrupt                                    */
    STM32F4_01_57_XX_DMA1_Stream2_IRQn = 13, /*!< DMA1 Stream 2 global Interrupt                                    */
    STM32F4_01_57_XX_DMA1_Stream3_IRQn = 14, /*!< DMA1 Stream 3 global Interrupt                                    */
    STM32F4_01_57_XX_DMA1_Stream4_IRQn = 15, /*!< DMA1 Stream 4 global Interrupt                                    */
    STM32F4_01_57_XX_DMA1_Stream5_IRQn = 16, /*!< DMA1 Stream 5 global Interrupt                                    */
    STM32F4_01_57_XX_DMA1_Stream6_IRQn = 17, /*!< DMA1 Stream 6 global Interrupt                                    */
    STM32F4_01_57_XX_ADC_IRQn = 18, /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
    STM32F4_01_57_XX_CAN1_TX_IRQn = 19, /*!< CAN1 TX Interrupt                                                 */
    STM32F4_01_57_XX_CAN1_RX0_IRQn = 20, /*!< CAN1 RX0 Interrupt                                                */
    STM32F4_01_57_XX_CAN1_RX1_IRQn = 21, /*!< CAN1 RX1 Interrupt                                                */
    STM32F4_01_57_XX_CAN1_SCE_IRQn = 22, /*!< CAN1 SCE Interrupt                                                */
    STM32F4_01_57_XX_EXTI9_5_IRQn = 23, /*!< External Line[9:5] Interrupts                                     */
    STM32F4_01_57_XX_TIM1_BRK_TIM9_IRQn = 24, /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
    STM32F4_01_57_XX_TIM1_UP_TIM10_IRQn = 25, /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
    STM32F4_01_57_XX_TIM1_TRG_COM_TIM11_IRQn = 26, /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
    STM32F4_01_57_XX_TIM1_CC_IRQn = 27, /*!< TIM1 Capture Compare Interrupt                                    */
    STM32F4_01_57_XX_TIM2_IRQn = 28, /*!< TIM2 global Interrupt                                             */
    STM32F4_01_57_XX_TIM3_IRQn = 29, /*!< TIM3 global Interrupt                                             */
    STM32F4_01_57_XX_TIM4_IRQn = 30, /*!< TIM4 global Interrupt                                             */
    STM32F4_01_57_XX_I2C1_EV_IRQn = 31, /*!< I2C1 Event Interrupt                                              */
    STM32F4_01_57_XX_I2C1_ER_IRQn = 32, /*!< I2C1 Error Interrupt                                              */
    STM32F4_01_57_XX_I2C2_EV_IRQn = 33, /*!< I2C2 Event Interrupt                                              */
    STM32F4_01_57_XX_I2C2_ER_IRQn = 34, /*!< I2C2 Error Interrupt                                              */
    STM32F4_01_57_XX_SPI1_IRQn = 35, /*!< SPI1 global Interrupt                                             */
    STM32F4_01_57_XX_SPI2_IRQn = 36, /*!< SPI2 global Interrupt                                             */
    STM32F4_01_57_XX_USART1_IRQn = 37, /*!< USART1 global Interrupt                                           */
    STM32F4_01_57_XX_USART2_IRQn = 38, /*!< USART2 global Interrupt                                           */
    STM32F4_01_57_XX_USART3_IRQn = 39, /*!< USART3 global Interrupt                                           */
    STM32F4_01_57_XX_EXTI15_10_IRQn = 40, /*!< External Line[15:10] Interrupts                                   */
    STM32F4_01_57_XX_RTC_Alarm_IRQn = 41, /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    STM32F4_01_57_XX_OTG_FS_WKUP_IRQn = 42, /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
    STM32F4_01_57_XX_TIM8_BRK_TIM12_IRQn = 43, /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
    STM32F4_01_57_XX_TIM8_UP_TIM13_IRQn = 44, /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
    STM32F4_01_57_XX_TIM8_TRG_COM_TIM14_IRQn = 45, /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
    STM32F4_01_57_XX_TIM8_CC_IRQn = 46, /*!< TIM8 Capture Compare Interrupt                                    */
    STM32F4_01_57_XX_DMA1_Stream7_IRQn = 47, /*!< DMA1 Stream7 Interrupt                                            */
    STM32F4_01_57_XX_FSMC_IRQn = 48, /*!< FSMC global Interrupt                                             */
    STM32F4_01_57_XX_SDIO_IRQn = 49, /*!< SDIO global Interrupt                                             */
    STM32F4_01_57_XX_TIM5_IRQn = 50, /*!< TIM5 global Interrupt                                             */
    STM32F4_01_57_XX_SPI3_IRQn = 51, /*!< SPI3 global Interrupt                                             */
    STM32F4_01_57_XX_UART4_IRQn = 52, /*!< UART4 global Interrupt                                            */
    STM32F4_01_57_XX_UART5_IRQn = 53, /*!< UART5 global Interrupt                                            */
    STM32F4_01_57_XX_TIM6_DAC_IRQn = 54, /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
    STM32F4_01_57_XX_TIM7_IRQn = 55, /*!< TIM7 global interrupt                                             */
    STM32F4_01_57_XX_DMA2_Stream0_IRQn = 56, /*!< DMA2 Stream 0 global Interrupt                                    */
    STM32F4_01_57_XX_DMA2_Stream1_IRQn = 57, /*!< DMA2 Stream 1 global Interrupt                                    */
    STM32F4_01_57_XX_DMA2_Stream2_IRQn = 58, /*!< DMA2 Stream 2 global Interrupt                                    */
    STM32F4_01_57_XX_DMA2_Stream3_IRQn = 59, /*!< DMA2 Stream 3 global Interrupt                                    */
    STM32F4_01_57_XX_DMA2_Stream4_IRQn = 60, /*!< DMA2 Stream 4 global Interrupt                                    */
    STM32F4_01_57_XX_ETH_IRQn = 61, /*!< Ethernet global Interrupt                                         */
    STM32F4_01_57_XX_ETH_WKUP_IRQn = 62, /*!< Ethernet Wakeup through EXTI line Interrupt                       */
    STM32F4_01_57_XX_CAN2_TX_IRQn = 63, /*!< CAN2 TX Interrupt                                                 */
    STM32F4_01_57_XX_CAN2_RX0_IRQn = 64, /*!< CAN2 RX0 Interrupt                                                */
    STM32F4_01_57_XX_CAN2_RX1_IRQn = 65, /*!< CAN2 RX1 Interrupt                                                */
    STM32F4_01_57_XX_CAN2_SCE_IRQn = 66, /*!< CAN2 SCE Interrupt                                                */
    STM32F4_01_57_XX_OTG_FS_IRQn = 67, /*!< USB OTG FS global Interrupt                                       */
    STM32F4_01_57_XX_DMA2_Stream5_IRQn = 68, /*!< DMA2 Stream 5 global interrupt                                    */
    STM32F4_01_57_XX_DMA2_Stream6_IRQn = 69, /*!< DMA2 Stream 6 global interrupt                                    */
    STM32F4_01_57_XX_DMA2_Stream7_IRQn = 70, /*!< DMA2 Stream 7 global interrupt                                    */
    STM32F4_01_57_XX_USART6_IRQn = 71, /*!< USART6 global interrupt                                           */
    STM32F4_01_57_XX_I2C3_EV_IRQn = 72, /*!< I2C3 event interrupt                                              */
    STM32F4_01_57_XX_I2C3_ER_IRQn = 73, /*!< I2C3 error interrupt                                              */
    STM32F4_01_57_XX_OTG_HS_EP1_OUT_IRQn = 74, /*!< USB OTG HS End Point 1 Out global interrupt                       */
    STM32F4_01_57_XX_OTG_HS_EP1_IN_IRQn = 75, /*!< USB OTG HS End Point 1 In global interrupt                        */
    STM32F4_01_57_XX_OTG_HS_WKUP_IRQn = 76, /*!< USB OTG HS Wakeup through EXTI interrupt                          */
    STM32F4_01_57_XX_OTG_HS_IRQn = 77, /*!< USB OTG HS global interrupt                                       */
    STM32F4_01_57_XX_DCMI_IRQn = 78, /*!< DCMI global interrupt                                             */
    STM32F4_01_57_XX_CRYP_IRQn = 79, /*!< CRYP crypto global interrupt                                      */
    STM32F4_01_57_XX_HASH_RNG_IRQn = 80, /*!< Hash and RNG global interrupt                                     */
    STM32F4_01_57_XX_FPU_IRQn = 81 /*!< FPU global interrupt                                              */
} STM32F4_01_57_XX_IRQn_Type;

typedef enum {
    STM32F4_23_XX_WWDG_IRQn = 0, /*!< Window WatchDog Interrupt                                         */
    STM32F4_23_XX_PVD_IRQn = 1, /*!< PVD through EXTI Line detection Interrupt                         */
    STM32F4_23_XX_TAMP_STAMP_IRQn = 2, /*!< Tamper and TimeStamp interrupts through the EXTI line             */
    STM32F4_23_XX_RTC_WKUP_IRQn = 3, /*!< RTC Wakeup interrupt through the EXTI line                        */
    STM32F4_23_XX_FLASH_IRQn = 4, /*!< FLASH global Interrupt                                            */
    STM32F4_23_XX_RCC_IRQn = 5, /*!< RCC global Interrupt                                              */
    STM32F4_23_XX_EXTI0_IRQn = 6, /*!< EXTI Line0 Interrupt                                              */
    STM32F4_23_XX_EXTI1_IRQn = 7, /*!< EXTI Line1 Interrupt                                              */
    STM32F4_23_XX_EXTI2_IRQn = 8, /*!< EXTI Line2 Interrupt                                              */
    STM32F4_23_XX_EXTI3_IRQn = 9, /*!< EXTI Line3 Interrupt                                              */
    STM32F4_23_XX_EXTI4_IRQn = 10, /*!< EXTI Line4 Interrupt                                              */
    STM32F4_23_XX_DMA1_Stream0_IRQn = 11, /*!< DMA1 Stream 0 global Interrupt                                    */
    STM32F4_23_XX_DMA1_Stream1_IRQn = 12, /*!< DMA1 Stream 1 global Interrupt                                    */
    STM32F4_23_XX_DMA1_Stream2_IRQn = 13, /*!< DMA1 Stream 2 global Interrupt                                    */
    STM32F4_23_XX_DMA1_Stream3_IRQn = 14, /*!< DMA1 Stream 3 global Interrupt                                    */
    STM32F4_23_XX_DMA1_Stream4_IRQn = 15, /*!< DMA1 Stream 4 global Interrupt                                    */
    STM32F4_23_XX_DMA1_Stream5_IRQn = 16, /*!< DMA1 Stream 5 global Interrupt                                    */
    STM32F4_23_XX_DMA1_Stream6_IRQn = 17, /*!< DMA1 Stream 6 global Interrupt                                    */
    STM32F4_23_XX_ADC_IRQn = 18, /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
    STM32F4_23_XX_CAN1_TX_IRQn = 19, /*!< CAN1 TX Interrupt                                                 */
    STM32F4_23_XX_CAN1_RX0_IRQn = 20, /*!< CAN1 RX0 Interrupt                                                */
    STM32F4_23_XX_CAN1_RX1_IRQn = 21, /*!< CAN1 RX1 Interrupt                                                */
    STM32F4_23_XX_CAN1_SCE_IRQn = 22, /*!< CAN1 SCE Interrupt                                                */
    STM32F4_23_XX_EXTI9_5_IRQn = 23, /*!< External Line[9:5] Interrupts                                     */
    STM32F4_23_XX_TIM1_BRK_TIM9_IRQn = 24, /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
    STM32F4_23_XX_TIM1_UP_TIM10_IRQn = 25, /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
    STM32F4_23_XX_TIM1_TRG_COM_TIM11_IRQn = 26, /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
    STM32F4_23_XX_TIM1_CC_IRQn = 27, /*!< TIM1 Capture Compare Interrupt                                    */
    STM32F4_23_XX_TIM2_IRQn = 28, /*!< TIM2 global Interrupt                                             */
    STM32F4_23_XX_TIM3_IRQn = 29, /*!< TIM3 global Interrupt                                             */
    STM32F4_23_XX_TIM4_IRQn = 30, /*!< TIM4 global Interrupt                                             */
    STM32F4_23_XX_I2C1_EV_IRQn = 31, /*!< I2C1 Event Interrupt                                              */
    STM32F4_23_XX_I2C1_ER_IRQn = 32, /*!< I2C1 Error Interrupt                                              */
    STM32F4_23_XX_I2C2_EV_IRQn = 33, /*!< I2C2 Event Interrupt                                              */
    STM32F4_23_XX_I2C2_ER_IRQn = 34, /*!< I2C2 Error Interrupt                                              */
    STM32F4_23_XX_SPI1_IRQn = 35, /*!< SPI1 global Interrupt                                             */
    STM32F4_23_XX_SPI2_IRQn = 36, /*!< SPI2 global Interrupt                                             */
    STM32F4_23_XX_USART1_IRQn = 37, /*!< USART1 global Interrupt                                           */
    STM32F4_23_XX_USART2_IRQn = 38, /*!< USART2 global Interrupt                                           */
    STM32F4_23_XX_USART3_IRQn = 39, /*!< USART3 global Interrupt                                           */
    STM32F4_23_XX_EXTI15_10_IRQn = 40, /*!< External Line[15:10] Interrupts                                   */
    STM32F4_23_XX_RTC_Alarm_IRQn = 41, /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    STM32F4_23_XX_OTG_FS_WKUP_IRQn = 42, /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
    STM32F4_23_XX_TIM8_BRK_TIM12_IRQn = 43, /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
    STM32F4_23_XX_TIM8_UP_TIM13_IRQn = 44, /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
    STM32F4_23_XX_TIM8_TRG_COM_TIM14_IRQn = 45, /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
    STM32F4_23_XX_TIM8_CC_IRQn = 46, /*!< TIM8 Capture Compare Interrupt                                    */
    STM32F4_23_XX_DMA1_Stream7_IRQn = 47, /*!< DMA1 Stream7 Interrupt                                            */
    STM32F4_23_XX_FMC_IRQn = 48, /*!< FMC global Interrupt                                              */
    STM32F4_23_XX_SDIO_IRQn = 49, /*!< SDIO global Interrupt                                             */
    STM32F4_23_XX_TIM5_IRQn = 50, /*!< TIM5 global Interrupt                                             */
    STM32F4_23_XX_SPI3_IRQn = 51, /*!< SPI3 global Interrupt                                             */
    STM32F4_23_XX_UART4_IRQn = 52, /*!< UART4 global Interrupt                                            */
    STM32F4_23_XX_UART5_IRQn = 53, /*!< UART5 global Interrupt                                            */
    STM32F4_23_XX_TIM6_DAC_IRQn = 54, /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
    STM32F4_23_XX_TIM7_IRQn = 55, /*!< TIM7 global interrupt                                             */
    STM32F4_23_XX_DMA2_Stream0_IRQn = 56, /*!< DMA2 Stream 0 global Interrupt                                    */
    STM32F4_23_XX_DMA2_Stream1_IRQn = 57, /*!< DMA2 Stream 1 global Interrupt                                    */
    STM32F4_23_XX_DMA2_Stream2_IRQn = 58, /*!< DMA2 Stream 2 global Interrupt                                    */
    STM32F4_23_XX_DMA2_Stream3_IRQn = 59, /*!< DMA2 Stream 3 global Interrupt                                    */
    STM32F4_23_XX_DMA2_Stream4_IRQn = 60, /*!< DMA2 Stream 4 global Interrupt                                    */
    STM32F4_23_XX_ETH_IRQn = 61, /*!< Ethernet global Interrupt                                         */
    STM32F4_23_XX_ETH_WKUP_IRQn = 62, /*!< Ethernet Wakeup through EXTI line Interrupt                       */
    STM32F4_23_XX_CAN2_TX_IRQn = 63, /*!< CAN2 TX Interrupt                                                 */
    STM32F4_23_XX_CAN2_RX0_IRQn = 64, /*!< CAN2 RX0 Interrupt                                                */
    STM32F4_23_XX_CAN2_RX1_IRQn = 65, /*!< CAN2 RX1 Interrupt                                                */
    STM32F4_23_XX_CAN2_SCE_IRQn = 66, /*!< CAN2 SCE Interrupt                                                */
    STM32F4_23_XX_OTG_FS_IRQn = 67, /*!< USB OTG FS global Interrupt                                       */
    STM32F4_23_XX_DMA2_Stream5_IRQn = 68, /*!< DMA2 Stream 5 global interrupt                                    */
    STM32F4_23_XX_DMA2_Stream6_IRQn = 69, /*!< DMA2 Stream 6 global interrupt                                    */
    STM32F4_23_XX_DMA2_Stream7_IRQn = 70, /*!< DMA2 Stream 7 global interrupt                                    */
    STM32F4_23_XX_USART6_IRQn = 71, /*!< USART6 global interrupt                                           */
    STM32F4_23_XX_I2C3_EV_IRQn = 72, /*!< I2C3 event interrupt                                              */
    STM32F4_23_XX_I2C3_ER_IRQn = 73, /*!< I2C3 error interrupt                                              */
    STM32F4_23_XX_OTG_HS_EP1_OUT_IRQn = 74, /*!< USB OTG HS End Point 1 Out global interrupt                       */
    STM32F4_23_XX_OTG_HS_EP1_IN_IRQn = 75, /*!< USB OTG HS End Point 1 In global interrupt                        */
    STM32F4_23_XX_OTG_HS_WKUP_IRQn = 76, /*!< USB OTG HS Wakeup through EXTI interrupt                          */
    STM32F4_23_XX_OTG_HS_IRQn = 77, /*!< USB OTG HS global interrupt                                       */
    STM32F4_23_XX_DCMI_IRQn = 78, /*!< DCMI global interrupt                                             */
    STM32F4_23_XX_CRYP_IRQn = 79, /*!< CRYP crypto global interrupt                                      */
    STM32F4_23_XX_HASH_RNG_IRQn = 80, /*!< Hash and Rng global interrupt                                     */
    STM32F4_23_XX_FPU_IRQn = 81, /*!< FPU global interrupt                                              */
    STM32F4_23_XX_UART7_IRQn = 82, /*!< UART7 global interrupt                                            */
    STM32F4_23_XX_UART8_IRQn = 83, /*!< UART8 global interrupt                                            */
    STM32F4_23_XX_SPI4_IRQn = 84, /*!< SPI4 global Interrupt                                             */
    STM32F4_23_XX_SPI5_IRQn = 85, /*!< SPI5 global Interrupt                                             */
    STM32F4_23_XX_SPI6_IRQn = 86, /*!< SPI6 global Interrupt                                             */
    STM32F4_23_XX_SAI1_IRQn = 87, /*!< SAI1 global Interrupt                                             */
    STM32F4_23_XX_LTDC_IRQn = 88, /*!< LTDC global Interrupt                                              */
    STM32F4_23_XX_LTDC_ER_IRQn = 89, /*!< LTDC Error global Interrupt                                        */
    STM32F4_23_XX_DMA2D_IRQn = 90 /*!< DMA2D global Interrupt                                            */
} STM32F4_23_XX_IRQn_Type;

typedef enum {
    STM32F411XX_WWDG_IRQn = 0, /*!< Window WatchDog Interrupt                                         */
    STM32F411XX_PVD_IRQn = 1, /*!< PVD through EXTI Line detection Interrupt                         */
    STM32F411XX_TAMP_STAMP_IRQn = 2, /*!< Tamper and TimeStamp interrupts through the EXTI line             */
    STM32F411XX_RTC_WKUP_IRQn = 3, /*!< RTC Wakeup interrupt through the EXTI line                        */
    STM32F411XX_FLASH_IRQn = 4, /*!< FLASH global Interrupt                                            */
    STM32F411XX_RCC_IRQn = 5, /*!< RCC global Interrupt                                              */
    STM32F411XX_EXTI0_IRQn = 6, /*!< EXTI Line0 Interrupt                                              */
    STM32F411XX_EXTI1_IRQn = 7, /*!< EXTI Line1 Interrupt                                              */
    STM32F411XX_EXTI2_IRQn = 8, /*!< EXTI Line2 Interrupt                                              */
    STM32F411XX_EXTI3_IRQn = 9, /*!< EXTI Line3 Interrupt                                              */
    STM32F411XX_EXTI4_IRQn = 10, /*!< EXTI Line4 Interrupt                                              */
    STM32F411XX_DMA1_Stream0_IRQn = 11, /*!< DMA1 Stream 0 global Interrupt                                    */
    STM32F411XX_DMA1_Stream1_IRQn = 12, /*!< DMA1 Stream 1 global Interrupt                                    */
    STM32F411XX_DMA1_Stream2_IRQn = 13, /*!< DMA1 Stream 2 global Interrupt                                    */
    STM32F411XX_DMA1_Stream3_IRQn = 14, /*!< DMA1 Stream 3 global Interrupt                                    */
    STM32F411XX_DMA1_Stream4_IRQn = 15, /*!< DMA1 Stream 4 global Interrupt                                    */
    STM32F411XX_DMA1_Stream5_IRQn = 16, /*!< DMA1 Stream 5 global Interrupt                                    */
    STM32F411XX_DMA1_Stream6_IRQn = 17, /*!< DMA1 Stream 6 global Interrupt                                    */
    STM32F411XX_ADC_IRQn = 18, /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
    STM32F411XX_EXTI9_5_IRQn = 23, /*!< External Line[9:5] Interrupts                                     */
    STM32F411XX_TIM1_BRK_TIM9_IRQn = 24, /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
    STM32F411XX_TIM1_UP_TIM10_IRQn = 25, /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
    STM32F411XX_TIM1_TRG_COM_TIM11_IRQn = 26, /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
    STM32F411XX_TIM1_CC_IRQn = 27, /*!< TIM1 Capture Compare Interrupt                                    */
    STM32F411XX_TIM2_IRQn = 28, /*!< TIM2 global Interrupt                                             */
    STM32F411XX_TIM3_IRQn = 29, /*!< TIM3 global Interrupt                                             */
    STM32F411XX_TIM4_IRQn = 30, /*!< TIM4 global Interrupt                                             */
    STM32F411XX_I2C1_EV_IRQn = 31, /*!< I2C1 Event Interrupt                                              */
    STM32F411XX_I2C1_ER_IRQn = 32, /*!< I2C1 Error Interrupt                                              */
    STM32F411XX_I2C2_EV_IRQn = 33, /*!< I2C2 Event Interrupt                                              */
    STM32F411XX_I2C2_ER_IRQn = 34, /*!< I2C2 Error Interrupt                                              */
    STM32F411XX_SPI1_IRQn = 35, /*!< SPI1 global Interrupt                                             */
    STM32F411XX_SPI2_IRQn = 36, /*!< SPI2 global Interrupt                                             */
    STM32F411XX_USART1_IRQn = 37, /*!< USART1 global Interrupt                                           */
    STM32F411XX_USART2_IRQn = 38, /*!< USART2 global Interrupt                                           */
    STM32F411XX_EXTI15_10_IRQn = 40, /*!< External Line[15:10] Interrupts                                   */
    STM32F411XX_RTC_Alarm_IRQn = 41, /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    STM32F411XX_OTG_FS_WKUP_IRQn = 42, /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
    STM32F411XX_DMA1_Stream7_IRQn = 47, /*!< DMA1 Stream7 Interrupt                                            */
    STM32F411XX_SDIO_IRQn = 49, /*!< SDIO global Interrupt                                             */
    STM32F411XX_TIM5_IRQn = 50, /*!< TIM5 global Interrupt                                             */
    STM32F411XX_SPI3_IRQn = 51, /*!< SPI3 global Interrupt                                             */
    STM32F411XX_DMA2_Stream0_IRQn = 56, /*!< DMA2 Stream 0 global Interrupt                                    */
    STM32F411XX_DMA2_Stream1_IRQn = 57, /*!< DMA2 Stream 1 global Interrupt                                    */
    STM32F411XX_DMA2_Stream2_IRQn = 58, /*!< DMA2 Stream 2 global Interrupt                                    */
    STM32F411XX_DMA2_Stream3_IRQn = 59, /*!< DMA2 Stream 3 global Interrupt                                    */
    STM32F411XX_DMA2_Stream4_IRQn = 60, /*!< DMA2 Stream 4 global Interrupt                                    */
    STM32F411XX_OTG_FS_IRQn = 67, /*!< USB OTG FS global Interrupt                                       */
    STM32F411XX_DMA2_Stream5_IRQn = 68, /*!< DMA2 Stream 5 global interrupt                                    */
    STM32F411XX_DMA2_Stream6_IRQn = 69, /*!< DMA2 Stream 6 global interrupt                                    */
    STM32F411XX_DMA2_Stream7_IRQn = 70, /*!< DMA2 Stream 7 global interrupt                                    */
    STM32F411XX_USART6_IRQn = 71, /*!< USART6 global interrupt                                           */
    STM32F411XX_I2C3_EV_IRQn = 72, /*!< I2C3 event interrupt                                              */
    STM32F411XX_I2C3_ER_IRQn = 73, /*!< I2C3 error interrupt                                              */
    STM32F411XX_FPU_IRQn = 81, /*!< FPU global interrupt                                              */
    STM32F411XX_SPI4_IRQn = 84, /*!< SPI4 global Interrupt                                             */
    STM32F411XX_SPI5_IRQn = 85 /*!< SPI5 global Interrupt                                             */
} STM32F411XX_IRQn_Type;

typedef enum {
    STM32F429X_WWDG_IRQn = 0, /*!< Window WatchDog Interrupt                                         */
    STM32F429X_PVD_IRQn = 1, /*!< PVD through EXTI Line detection Interrupt                         */
    STM32F429X_TAMP_STAMP_IRQn = 2, /*!< Tamper and TimeStamp interrupts through the EXTI line             */
    STM32F429X_RTC_WKUP_IRQn = 3, /*!< RTC Wakeup interrupt through the EXTI line                        */
    STM32F429X_FLASH_IRQn = 4, /*!< FLASH global Interrupt                                            */
    STM32F429X_RCC_IRQn = 5, /*!< RCC global Interrupt                                              */
    STM32F429X_EXTI0_IRQn = 6, /*!< EXTI Line0 Interrupt                                              */
    STM32F429X_EXTI1_IRQn = 7, /*!< EXTI Line1 Interrupt                                              */
    STM32F429X_EXTI2_IRQn = 8, /*!< EXTI Line2 Interrupt                                              */
    STM32F429X_EXTI3_IRQn = 9, /*!< EXTI Line3 Interrupt                                              */
    STM32F429X_EXTI4_IRQn = 10, /*!< EXTI Line4 Interrupt                                              */
    STM32F429X_DMA1_Stream0_IRQn = 11, /*!< DMA1 Stream 0 global Interrupt                                    */
    STM32F429X_DMA1_Stream1_IRQn = 12, /*!< DMA1 Stream 1 global Interrupt                                    */
    STM32F429X_DMA1_Stream2_IRQn = 13, /*!< DMA1 Stream 2 global Interrupt                                    */
    STM32F429X_DMA1_Stream3_IRQn = 14, /*!< DMA1 Stream 3 global Interrupt                                    */
    STM32F429X_DMA1_Stream4_IRQn = 15, /*!< DMA1 Stream 4 global Interrupt                                    */
    STM32F429X_DMA1_Stream5_IRQn = 16, /*!< DMA1 Stream 5 global Interrupt                                    */
    STM32F429X_DMA1_Stream6_IRQn = 17, /*!< DMA1 Stream 6 global Interrupt                                    */
    STM32F429X_ADC_IRQn = 18, /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
    STM32F429X_CAN1_TX_IRQn = 19, /*!< CAN1 TX Interrupt                                                 */
    STM32F429X_CAN1_RX0_IRQn = 20, /*!< CAN1 RX0 Interrupt                                                */
    STM32F429X_CAN1_RX1_IRQn = 21, /*!< CAN1 RX1 Interrupt                                                */
    STM32F429X_CAN1_SCE_IRQn = 22, /*!< CAN1 SCE Interrupt                                                */
    STM32F429X_EXTI9_5_IRQn = 23, /*!< External Line[9:5] Interrupts                                     */
    STM32F429X_TIM1_BRK_TIM9_IRQn = 24, /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
    STM32F429X_TIM1_UP_TIM10_IRQn = 25, /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
    STM32F429X_TIM1_TRG_COM_TIM11_IRQn = 26, /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
    STM32F429X_TIM1_CC_IRQn = 27, /*!< TIM1 Capture Compare Interrupt                                    */
    STM32F429X_TIM2_IRQn = 28, /*!< TIM2 global Interrupt                                             */
    STM32F429X_TIM3_IRQn = 29, /*!< TIM3 global Interrupt                                             */
    STM32F429X_TIM4_IRQn = 30, /*!< TIM4 global Interrupt                                             */
    STM32F429X_I2C1_EV_IRQn = 31, /*!< I2C1 Event Interrupt                                              */
    STM32F429X_I2C1_ER_IRQn = 32, /*!< I2C1 Error Interrupt                                              */
    STM32F429X_I2C2_EV_IRQn = 33, /*!< I2C2 Event Interrupt                                              */
    STM32F429X_I2C2_ER_IRQn = 34, /*!< I2C2 Error Interrupt                                              */
    STM32F429X_SPI1_IRQn = 35, /*!< SPI1 global Interrupt                                             */
    STM32F429X_SPI2_IRQn = 36, /*!< SPI2 global Interrupt                                             */
    STM32F429X_USART1_IRQn = 37, /*!< USART1 global Interrupt                                           */
    STM32F429X_USART2_IRQn = 38, /*!< USART2 global Interrupt                                           */
    STM32F429X_USART3_IRQn = 39, /*!< USART3 global Interrupt                                           */
    STM32F429X_EXTI15_10_IRQn = 40, /*!< External Line[15:10] Interrupts                                   */
    STM32F429X_RTC_Alarm_IRQn = 41, /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    STM32F429X_OTG_FS_WKUP_IRQn = 42, /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
    STM32F429X_TIM8_BRK_TIM12_IRQn = 43, /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
    STM32F429X_TIM8_UP_TIM13_IRQn = 44, /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
    STM32F429X_TIM8_TRG_COM_TIM14_IRQn = 45, /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
    STM32F429X_TIM8_CC_IRQn = 46, /*!< TIM8 Capture Compare Interrupt                                    */
    STM32F429X_DMA1_Stream7_IRQn = 47, /*!< DMA1 Stream7 Interrupt                                            */
    STM32F429X_FMC_IRQn = 48, /*!< FMC global Interrupt                                              */
    STM32F429X_SDIO_IRQn = 49, /*!< SDIO global Interrupt                                             */
    STM32F429X_TIM5_IRQn = 50, /*!< TIM5 global Interrupt                                             */
    STM32F429X_SPI3_IRQn = 51, /*!< SPI3 global Interrupt                                             */
    STM32F429X_UART4_IRQn = 52, /*!< UART4 global Interrupt                                            */
    STM32F429X_UART5_IRQn = 53, /*!< UART5 global Interrupt                                            */
    STM32F429X_TIM6_DAC_IRQn = 54, /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
    STM32F429X_TIM7_IRQn = 55, /*!< TIM7 global interrupt                                             */
    STM32F429X_DMA2_Stream0_IRQn = 56, /*!< DMA2 Stream 0 global Interrupt                                    */
    STM32F429X_DMA2_Stream1_IRQn = 57, /*!< DMA2 Stream 1 global Interrupt                                    */
    STM32F429X_DMA2_Stream2_IRQn = 58, /*!< DMA2 Stream 2 global Interrupt                                    */
    STM32F429X_DMA2_Stream3_IRQn = 59, /*!< DMA2 Stream 3 global Interrupt                                    */
    STM32F429X_DMA2_Stream4_IRQn = 60, /*!< DMA2 Stream 4 global Interrupt                                    */
    STM32F429X_ETH_IRQn = 61, /*!< Ethernet global Interrupt                                         */
    STM32F429X_ETH_WKUP_IRQn = 62, /*!< Ethernet Wakeup through EXTI line Interrupt                       */
    STM32F429X_CAN2_TX_IRQn = 63, /*!< CAN2 TX Interrupt                                                 */
    STM32F429X_CAN2_RX0_IRQn = 64, /*!< CAN2 RX0 Interrupt                                                */
    STM32F429X_CAN2_RX1_IRQn = 65, /*!< CAN2 RX1 Interrupt                                                */
    STM32F429X_CAN2_SCE_IRQn = 66, /*!< CAN2 SCE Interrupt                                                */
    STM32F429X_OTG_FS_IRQn = 67, /*!< USB OTG FS global Interrupt                                       */
    STM32F429X_DMA2_Stream5_IRQn = 68, /*!< DMA2 Stream 5 global interrupt                                    */
    STM32F429X_DMA2_Stream6_IRQn = 69, /*!< DMA2 Stream 6 global interrupt                                    */
    STM32F429X_DMA2_Stream7_IRQn = 70, /*!< DMA2 Stream 7 global interrupt                                    */
    STM32F429X_USART6_IRQn = 71, /*!< USART6 global interrupt                                           */
    STM32F429X_I2C3_EV_IRQn = 72, /*!< I2C3 event interrupt                                              */
    STM32F429X_I2C3_ER_IRQn = 73, /*!< I2C3 error interrupt                                              */
    STM32F429X_OTG_HS_EP1_OUT_IRQn = 74, /*!< USB OTG HS End Point 1 Out global interrupt                       */
    STM32F429X_OTG_HS_EP1_IN_IRQn = 75, /*!< USB OTG HS End Point 1 In global interrupt                        */
    STM32F429X_OTG_HS_WKUP_IRQn = 76, /*!< USB OTG HS Wakeup through EXTI interrupt                          */
    STM32F429X_OTG_HS_IRQn = 77, /*!< USB OTG HS global interrupt                                       */
    STM32F429X_DCMI_IRQn = 78, /*!< DCMI global interrupt                                             */
    STM32F429X_HASH_RNG_IRQn = 80, /*!< Hash and RNG global interrupt                                     */
    STM32F429X_FPU_IRQn = 81, /*!< FPU global interrupt                                              */
    STM32F429X_UART7_IRQn = 82, /*!< UART7 global interrupt                                            */
    STM32F429X_UART8_IRQn = 83, /*!< UART8 global interrupt                                            */
    STM32F429X_SPI4_IRQn = 84, /*!< SPI4 global Interrupt                                             */
    STM32F429X_SPI5_IRQn = 85, /*!< SPI5 global Interrupt                                             */
    STM32F429X_SPI6_IRQn = 86, /*!< SPI6 global Interrupt                                             */
    STM32F429X_SAI1_IRQn = 87, /*!< SAI1 global Interrupt                                             */
    STM32F429X_LTDC_IRQn = 88, /*!< LTDC global Interrupt                                              */
    STM32F429X_LTDC_ER_IRQn = 89, /*!< LTDC Error global Interrupt                                        */
    STM32F429X_DMA2D_IRQn = 90 /*!< DMA2D global Interrupt                                            */

} STM32F429X_IRQn_Type;

typedef struct {

    stm32_family_t family;

    // Properties common to all families

    uint32_t hsi_freq_hz;
    uint32_t lsi_freq_hz;

    uint32_t eeprom_size_kb;
    uint32_t ccm_size_kb; // size of CCM area, in KB
    uint32_t back_sram_size_kb; // size of backup SRAM area, in KB

    // Bitband the 1 MB from 0x40000000-0x400FFFFF area to
    // 32 MB at 0x42000000-0x43FFFFFF.

    unsigned int has_periph_bitband :1;

#if 0
    // Peripherals common to all families.

    unsigned int has_rcc :1;
    unsigned int has_flash :1;
    unsigned int has_pwr :1;

    // System configuration; F4 specific.
    unsigned int has_syscfg :1;

    // Alternate function I/O; F1 specific
    unsigned int has_afio :1;

    // EXTI
    unsigned int has_exti :1;

#endif

    // GPIOs
    unsigned int has_gpioa :1;
    unsigned int has_gpiob :1;
    unsigned int has_gpioc :1;
    unsigned int has_gpiod :1;
    unsigned int has_gpioe :1;
    unsigned int has_gpiof :1;
    unsigned int has_gpiog :1;
    unsigned int has_gpioh :1; // Used by L1
    unsigned int has_gpioi :1; // Used by F4
    unsigned int has_gpioj :1; // Used by F4[23]
    unsigned int has_gpiok :1; // Used by F4[23]

    unsigned char num_gpio; // Will be computed, no need to set it.

    // DMA
    unsigned int has_dma :1;
    unsigned int has_dma1 :1;
    unsigned int has_dma2 :1;

    // Advanced control timers
    unsigned int has_ac_tim1 :1;
    unsigned int has_ac_tim8 :1;
    // General-purpose timers
    unsigned int has_gp_tim2 :1;
    unsigned int has_gp_tim5 :1;
    // General-purpose timers
    unsigned int has_gp_tim3 :1;
    unsigned int has_gp_tim4 :1;
    // General-purpose timers
    unsigned int has_gp_tim9 :1;
    unsigned int has_gp_tim12 :1;
    // General-purpose timers
    unsigned int has_gp_tim10 :1;
    unsigned int has_gp_tim11 :1;
    unsigned int has_gp_tim13 :1;
    unsigned int has_gp_tim14 :1;
    unsigned int has_gp_tim15 :1;
    unsigned int has_gp_tim16 :1;
    unsigned int has_gp_tim17 :1;
    // Basic timers
    unsigned int has_bc_tim6 :1;
    unsigned int has_bc_tim7 :1;
    // Watchdogs
    unsigned int has_iwdg :1;
    unsigned int has_wwdg :1;

    // I2C
    unsigned int has_i2c :1;
    unsigned int has_i2c1 :1;
    unsigned int has_i2c2 :1;
    unsigned int has_i2c3 :1;

    // Universal synchronous/asynchronous
    unsigned int has_usart1 :1;
    unsigned int has_usart2 :1;
    unsigned int has_usart3 :1;
    unsigned int has_usart4 :1;
    unsigned int has_usart5 :1;
    unsigned int has_usart6 :1;
    unsigned int has_usart7 :1;
    unsigned int has_usart8 :1;
    // Universal asynchronous
    unsigned int has_uart4 :1;
    unsigned int has_uart5 :1;

    // SPI
    unsigned int has_spi1 :1;
    unsigned int has_spi2 :1;
    unsigned int has_spi3 :1;
    unsigned int has_spi4 :1;
    unsigned int has_spi5 :1;

    // I2S
    unsigned int has_i2s1 :1;
    unsigned int has_i2s2 :1;

    unsigned int has_plli2s :1;

    // Memory
    unsigned int has_fsmc :1;

    // SDIO
    unsigned int has_sdio :1;

    // Ethernet
    unsigned int has_eth :1;
    // CAN
    unsigned int has_bx_can1 :1;
    unsigned int has_bx_can2 :1;
    unsigned int has_can1 :1;
    unsigned int has_can2 :1;
    // ADC
    unsigned int has_adc :1;
    unsigned int has_adc1 :1;
    unsigned int has_adc2 :1;
    unsigned int has_adc3 :1;
    // DAC
    unsigned int has_dac :1; // num_dac
    unsigned int has_dac1 :1;
    unsigned int has_dac2 :1;
    // USB
    unsigned int has_usb_fs :1;
    unsigned int has_usb_otg_fs :1;
    unsigned int has_usb_otg_hs :1;

    // RTC
    unsigned int has_rtc :1;

    // CRC
    unsigned int has_crc :1;

    // Temperature sensor
    unsigned int has_ts :1;

    unsigned int has_comp :1; // num_comp

    unsigned int has_dcmi :1;
    unsigned int has_rng :1;
    unsigned int has_hdmi_cec :1;

    // Has TSC (touch sensing controller)
    unsigned int has_tsc :1;

    // Keep them together
    unsigned char num_exti;
    unsigned char num_dma1;
    unsigned char num_dma2;
    unsigned char num_dma;
    unsigned char num_comp;

    // Number of backup bytes
    uint32_t num_back_bytes;

    /*
     * Note: the family definitions are mutual exclusive, and could
     * be packed in a union, but this makes writing the definitions
     * more complicated and was discarded.
     * The memory penalty is not significant.
     */
    struct {
        // DEPRECATED, to be removed!
        // unsigned int is_51xx :1;

        // The names follow the STM CMSIS SVD naming scheme,
        // with the STM32F prefix removed.
        unsigned int is_0x0 :1;
        unsigned int is_0x1 :1;
        unsigned int is_0x2 :1;
        unsigned int is_0x8 :1;
        unsigned int is_0xx :1;
        unsigned int is_030 :1;
        unsigned int is_031x :1;
        unsigned int is_042x :1;
        unsigned int is_072x :1;
        unsigned int is_091x :1;
    } f0;

    struct {
        unsigned int is_ld :1; // is low density
        unsigned int is_md :1; // is medium density
        unsigned int is_hd :1; // is high density
        unsigned int is_xd :1; // is extra density
        unsigned int is_cl :1; // is Connectivity Line
        unsigned int is_ldvl :1; // is low density
        unsigned int is_mdvl :1; // is medium density
        unsigned int is_hdvl :1; // is high density

        // Used in parallel with the above.
        unsigned int is_103xx :1;
        unsigned int is_107xx :1;

    } f1;

    struct {
        // DEPRECATED, to be removed!
        // unsigned int is_01_57_xx :1;
        // unsigned int is_23_xxx :1;
        // unsigned int is11xx :1;

        // The names follow the STM CMSIS SVD naming scheme,
        // with the STM32F prefix removed.
        unsigned int is_40x :1;
        unsigned int is_41x :1;
        unsigned int is_46_79x :1;
        unsigned int is_401x :1;
        unsigned int is_401xE :1;
        unsigned int is_410xx :1;
        unsigned int is_411xx :1;
        unsigned int is_412xG :1;
        unsigned int is_427x :1;
        unsigned int is_429x :1;
        unsigned int is_437x :1;
        unsigned int is_439x :1;
        unsigned int is_446x :1;
    } f4;
    // TODO: add other families that have sub-families.

} STM32Capabilities;

#endif /* STM32_CAPABILITIES_H_ */
