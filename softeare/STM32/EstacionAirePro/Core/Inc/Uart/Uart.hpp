/*
 * uart.h
 *
 *  Created on: 15/11/2021
 *      Author: Alcides Ramos
 */

#ifndef LIBRERIAS_UART_H_
#define LIBRERIAS_UART_H_


//#include <Constantes.hpp>
#include "stm32f1xx_hal.h"
extern UART_HandleTypeDef Huart1;



void uartx_write(char ch);
void uartx_write_text(char *info);
uint8_t uartx_read();
void uartx_read_text(uint8_t  *info,const uint8_t final,uint8_t cuanto);
//static
void USART1_UART_Init(void);
void ErrorHandler(void);
void SerialPrintf(char *formato, ...);


#endif
