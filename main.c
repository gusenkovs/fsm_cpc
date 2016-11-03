#include "stm32f10x.h"
#include "stm32f1_gpio.h"
#include "stm32f1_rcc.h"
#include "stm32f1_timer.h"
#include "stm32f1_systick.h"
#include "stm32f1_rtc.h"
#include "stm32f1_uart.h"
#include <stdio.h>

volatile uint32_t dcount;
void Delay(volatile uint32_t nCount);

int main(void)
{
  /** RCC **/
  RCC_APB2_Init(RCC_APB2ENR_IOPAEN);
  RCC_APB2_Init(RCC_APB2ENR_IOPCEN);
  RCC_APB1_Init(RCC_APB1ENR_TIM4EN);
  RCC_APB1_Init(RCC_APB1ENR_PWREN);
  RCC_APB1_Init(RCC_APB1ENR_BKPEN);
  RCC_APB2_Init(RCC_APB2ENR_USART1EN);
  
  /** Init **/
  GPIO_INIT_PIN(GPIOC, 13,GPIO_MODE_OUTPUT50_OPEN_DRAIN);
  GPIO_INIT_PIN(GPIOA, 9,GPIO_MODE_OUTPUT50_ALT_PUSH_PULL);
  GPIO_INIT_PIN(GPIOA, 10,GPIO_MODE_INPUT_ANALOG);
  TIMER_init(TIM4,36000,1000);
 // SysTick_init(1);
 // RTC_Init();
 // RTC_SetCounter(0);
  UART_init(USART1,UART_72_9600);
  /** IRQ **/
  NVIC_EnableIRQ(TIM4_IRQn);
  //NVIC_EnableIRQ(RTC_IRQn);
  /* Infinite loop */
  while (1)
  {
      GPIO_ON(GPIOC,13);
      UartWrite(USART1,'d');
      Delay(10);
      GPIO_OFF(GPIOC,13);
      Delay(10);
      
  }
}

void Delay(volatile uint32_t nCount)
{
    dcount=nCount;
    while(dcount)
    {
    }
    //uint32_t dcount=RTC_GetCounter();
   // while((RTC_GetCounter()-dcount)<nCount){}
}

