#include "stm32f10x.h"
#include "stm32f1_gpio.h"
#include "stm32f1_rcc.h"
#include "stm32f1_timer.h"
#include "stm32f1_systick.h"
#include "stm32f1_rtc.h"
#include <stdio.h>

//volatile uint32_t dcount;
void Delay(volatile uint32_t nCount);

int main(void)
{
  /** RCC **/
  RCC_APB2_Init(RCC_APB2ENR_IOPCEN);
  RCC_APB1_Init(RCC_APB1ENR_TIM4EN);
  RCC_APB1_Init(RCC_APB1ENR_PWREN);
  RCC_APB1_Init(RCC_APB1ENR_BKPEN);
  
  /** Init **/
  GPIO_INIT_PIN(GPIOC, 13,GPIO_MODE_OUTPUT50_OPEN_DRAIN);
  TIMER_init(TIM4,24000,1000);
 // SysTick_init(1);
  RTC_Init();
  RTC_SetCounter(0);
  
  /** IRQ **/
  NVIC_EnableIRQ(TIM4_IRQn);
  //NVIC_EnableIRQ(RTC_IRQn);
  /* Infinite loop */
  while (1)
  {
      GPIO_ON(GPIOC,13);
      Delay(1);
      GPIO_OFF(GPIOC,13);
      Delay(1);
      
  }
}

void Delay(volatile uint32_t nCount)
{
    uint32_t dcount=RTC_GetCounter();
    while((RTC_GetCounter()-dcount)<nCount){}
}

