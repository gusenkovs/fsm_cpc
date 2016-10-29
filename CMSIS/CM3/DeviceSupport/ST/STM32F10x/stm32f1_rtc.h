#ifndef __STM32F1_RTC_H
#define __STM32F1_RTC_H

#define RTC_Init() PWR->CR |= PWR_CR_DBP; \
    if ((RCC->BDCR & RCC_BDCR_RTCEN) != RCC_BDCR_RTCEN){ \
        RCC->BDCR |=  RCC_BDCR_BDRST; \
        RCC->BDCR &= ~RCC_BDCR_BDRST; \
        RCC->BDCR |=  RCC_BDCR_RTCEN | RCC_BDCR_RTCSEL_LSI; \
        RTC->CRL  |=  RTC_CRL_CNF; \
        RTC->PRLL  =  0x7FFF; \
        RTC->CRH  |=  RTC_CRH_SECIE; \
        RTC->CRL  &=  ~RTC_CRL_CNF; \
        while (!(RTC->CRL & RTC_CRL_RTOFF)); \
        RTC->CRL &= (uint16_t)~RTC_CRL_RSF; \
        while((RTC->CRL & RTC_CRL_RSF) != RTC_CRL_RSF){} \
        RTC->CRL &= ~RTC_CRL_SECF; \
        }\
        else { \
        RTC->CRH  |=  RTC_CRH_SECIE; \
        } \
        PWR->CR &= ~PWR_CR_DBP;    

#define RTC_GetCounter() (uint32_t)((RTC->CNTH << 16) | RTC->CNTL)        
#define RTC_SetCounter(count) RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;  \
    PWR->CR |= PWR_CR_DBP;\
    while (!(RTC->CRL & RTC_CRL_RTOFF)); \
    RTC->CRL |= RTC_CRL_CNF; \
    RTC->CNTH = count>>16;     \
    RTC->CNTL = count;\
    RTC->CRL &= ~RTC_CRL_CNF; \
    while (!(RTC->CRL & RTC_CRL_RTOFF));\
    PWR->CR &= ~PWR_CR_DBP;
/** IRQ**/ 

//RTC_IRQn RTCAlarm_IRQHandler

#endif