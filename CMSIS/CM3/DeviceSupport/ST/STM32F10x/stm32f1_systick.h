#ifndef __STM32F1_SysTick_H
#define __STM32F1_SysTick_H

#define SysTick_init(time) SysTick->LOAD=time; \
        SysTick->VAL=time;\
        SysTick->CTRL=	SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
        
#endif