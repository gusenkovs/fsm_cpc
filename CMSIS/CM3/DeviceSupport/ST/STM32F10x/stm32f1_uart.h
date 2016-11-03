#ifndef __STM32F1_UART_H
#define __STM32F1_UART_H

//Например, у нас частота шины 36МГц, а бодрейт у нас должен быть 19200 бод. 
//(36 000 000/19200)/16 = 117.18
//Целая часть у нас будет 117, а вот дробную надо будет восстановить, умножив на 16 и округлив до ближайшего целого:
//0.18 * 16 = 2.88 -> 3
//Переводим в хекс и получаем 0х75 и 0х3 т.е. USART_BRR = 0x00000753

#define UART_72_19200 0xEA6 //234 6
#define UART_72_9600 0x1D4C //468 12
#define UART_init(UART, baundrate) UART->BRR=baundrate; \
        UART->CR1  |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE; 

#define UartRead(UART, data) data=UART->DR;

#define UartWrite(UART, data) while(!(UART->SR & USART_SR_TC)); \
        UART->DR=data; 
        
        

#endif