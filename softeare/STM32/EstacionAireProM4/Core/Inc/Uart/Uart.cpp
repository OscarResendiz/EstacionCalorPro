/*
 * uart.c
 *
 *  Created on: 15/11/2021
 *      Author: Alcides Ramos
 */

#include "uart.hpp"
#include "stdio.h"
#include <stdarg.h>
#include "string.h"
#include "stm32f4xx_hal.h"
UART_HandleTypeDef Huart1;

void uartx_write(char ch)
{
	HAL_UART_Transmit(&Huart1,(uint8_t*) &ch, 1, 0xffff);

}

void uartx_write_text(char *info)
{

	while(*info)  uartx_write(*info++);

}


uint8_t uartx_read()
{
	uint8_t dato_rx_=0;
	HAL_UART_Receive(&Huart1,&dato_rx_, 1,HAL_MAX_DELAY);
	return(dato_rx_);
}



void uartx_read_text(uint8_t  *info,const uint8_t final,uint8_t cuanto)
{
	uint8_t dato_rx=0;//  los datos leidos son de 8 bits
	char i=0;
	memset(info,0,cuanto);//limpia el buffer
	while(dato_rx!=final)// lee hasta que llegue el final
	{
		dato_rx =uartx_read();
		*info=dato_rx;//  va almacenado en el buffer
		info++;
		i++;// incrementa contador
		if (i>cuanto-1) break;// si llegan n elementosa sale
	}
}

//static
void USART1_UART_Init(void)
{

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	Huart1.Instance = USART1;
	Huart1.Init.BaudRate = 115200;
	Huart1.Init.WordLength = UART_WORDLENGTH_8B;
	Huart1.Init.StopBits = UART_STOPBITS_1;
	Huart1.Init.Parity = UART_PARITY_NONE;
	Huart1.Init.Mode = UART_MODE_TX_RX;
	Huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	Huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&Huart1) != HAL_OK)
	{
		ErrorHandler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}
void ErrorHandler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}
void SerialPrintf(char * formato, ...)
{

    char *p;
    char buffer[100];

    char formatoFlotante[20];
    int posisionFormato=0;
    char tmp[100];
    int postmp=0;
    int posbuffer = 0;
    va_list pa;
    int encontrado=0;
    //float a;
    va_start(pa, formato);
    for (p = formato; *p; p++)
    {

      if (*p != '%')
      {
        buffer[posbuffer] = *p;
        posbuffer++;
        continue;
      }
      encontrado=0;
      switch (*++p)
      {
        case 'd':
          sprintf(tmp, "%d", va_arg(pa, int));
          encontrado=1;
          break;
        case 'i':
          sprintf(tmp, "%i", va_arg(pa, int));
          encontrado=1;
          break;
        case 'x':
          sprintf(tmp, "%x", va_arg(pa, int));
          encontrado=1;
          break;
        case 'p':
          sprintf(tmp, "%p", va_arg(pa, void*));
          encontrado=1;
          break;
        case 'c':
          sprintf(tmp, "%c", va_arg(pa, int));
          encontrado=1;
          break;
        case 'f':
          sprintf(tmp, "%f", va_arg(pa, double));
          encontrado=1;
          break;
        case 's':
          sprintf(tmp, "%s", va_arg(pa, char *));
          encontrado=1;
          break;
        case '.':
        	//asume que es flotante con decimales definidos
        	formatoFlotante[0]='%';
        	posisionFormato=1;
        	while(*p!='f')
        	{
        		formatoFlotante[posisionFormato]=*p;
        		p++;
        		posisionFormato++;
        	}
        	formatoFlotante[posisionFormato]='f';
        	formatoFlotante[posisionFormato+1]='\0';
            sprintf(tmp, formatoFlotante, va_arg(pa, double));
            encontrado=1;
            break;
        default:
          buffer[posbuffer] = *p;
          posbuffer++;
          break;
      }
      if(encontrado==1)
      {
          postmp=0;
          while(tmp[postmp]!='\0')
          {
          buffer[posbuffer] = tmp[postmp];
          posbuffer++;
          postmp++;
          }
      }
    }
    va_end(pa);
    buffer[posbuffer] = '\0';
    uartx_write_text(buffer);
}

