#ifndef __STM32F1_RCC_H
#define __STM32F1_RCC_H

//*** GPIO ****//
//#define  RCC_APB2ENR_IOPAEN /*!< I/O port A clock enable */
//#define  RCC_APB2ENR_IOPBEN /*!< I/O port B clock enable */
//#define  RCC_APB2ENR_IOPCEN /*!< I/O port C clock enable */
//#define  RCC_APB2ENR_IOPDEN /*!< I/O port D clock enable */

//***Timer *****//
//#define  RCC_APB2ENR_TIM1EN /*!< TIM1 Timer clock enable */
//#define  RCC_APB1ENR_TIM2EN /*!< Timer 2 clock enabled*/
//#define  RCC_APB1ENR_TIM3EN /*!< Timer 3 clock enable */
//#define  RCC_APB1ENR_TIM4EN /*!< Timer 4 clock enable */
//#define  RCC_APB1ENR_TIM5EN /*!< Timer 5 clock enable */
//#define  RCC_APB1ENR_TIM6EN /*!< Timer 6 clock enable */
//#define  RCC_APB1ENR_TIM7EN /*!< Timer 7 clock enable */
//#define  RCC_APB2ENR_TIM8EN /*!< TIM8 Timer clock enable */
//#define  RCC_APB2ENR_TIM9EN /*!< TIM9 Timer clock enable  */
//#define  RCC_APB2ENR_TIM10EN /*!< TIM10 Timer clock enable  */
//#define  RCC_APB2ENR_TIM11EN  /*!< TIM11 Timer clock enable */

//***RTC *****//
//#define  RCC_APB1ENR_BKPEN    /*!< Backup interface clock enable */
//#define  RCC_APB1ENR_PWREN    /*!< Power interface clock enable */

//** UART **//
//#define  RCC_APB2ENR_USART1EN
//#define  RCC_APB1ENR_USART2EN
//#define  RCC_APB1ENR_USART3EN
//#define  RCC_APB1ENR_UART4EN     
//#define  RCC_APB1ENR_UART5EN  
 
#define RCC_AHB_Init(Periph) RCC->AHBENR |= Periph
#define RCC_APB1_Init(Periph) RCC->APB1ENR |= Periph
#define RCC_APB2_Init(Periph) RCC->APB2ENR |= Periph

#endif