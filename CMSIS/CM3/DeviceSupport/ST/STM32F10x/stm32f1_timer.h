#ifndef __STM32F1_TIMER_H
#define __STM32F1_TIMER_H

#define TIMER_init(TIMER,frequency_processor,time) TIMER->PSC=frequency_processor-1; \
    TIMER->ARR=time; \
    TIMER->DIER |= TIM_DIER_UIE; \
    TIMER->CR1 |= TIM_CR1_CEN; 
    
#define TIMER_IRQ_Reset(TIMER) TIMER->SR &= ~TIM_SR_UIF; 

//****IRG****/
//  TIM1_BRK_IRQn          TIM1_BRK_IRQHandler     /*!< TIM1 Break Interrupt                                 */
//  TIM1_UP_IRQn           TIM1_UP_IRQHandler      /*!< TIM1 Update Interrupt                                */
//  TIM1_TRG_COM_IRQn      TIM1_TRG_COM_IRQHandler /*!< TIM1 Trigger and Commutation Interrupt               */
//  TIM1_CC_IRQn           TIM1_CC_IRQHandler      /*!< TIM1 Capture Compare Interrupt                       */
//  TIM2_IRQn              TIM2_IRQHandler         /*!< TIM2 global Interrupt                                */
//  TIM3_IRQn              TIM3_IRQHandler         /*!< TIM3 global Interrupt                                */
//  TIM4_IRQn              TIM4_IRQHandler         /*!< TIM4 global Interrupt                                */

#endif