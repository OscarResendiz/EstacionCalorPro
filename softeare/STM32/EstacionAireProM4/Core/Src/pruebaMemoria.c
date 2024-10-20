/*
 * pruebaMemoria.cpp
 *
 *  Created on: Sep 26, 2024
 *      Author: W10
 */
#include "pruebaMemoria.h"
#include <stdio.h>
#include <string.h>
#include "Uart/Uart.hpp"

void pruebalectura(char *mensaje)
{
	uint8_t datos_r[10];
	char buf_tx[30];
	SerialPrintf("\r\n%s\r\n",mensaje);
	 if( HAL_I2C_Mem_Read(&hi2c1,ADDRESS_EEPROM,0,I2C_MEMADD_SIZE_8BIT,datos_r,10,HAL_MAX_DELAY)!=HAL_OK)
	 {
		 SerialPrintf("ERROR al leer la memoria \r\n");

	 }
	  for(uint8_t i=0;i<10;i++)
	  {
		  sprintf(buf_tx,"Dir: %u, Dato: %u\r\n",i,datos_r[i]);
		  SerialPrintf("%s",buf_tx);
	  }
	  SerialPrintf("\r\n");
}




