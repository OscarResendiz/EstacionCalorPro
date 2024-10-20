/*
 * pruebaMemoria.hpp
 *
 *  Created on: Sep 25, 2024
 *      Author: W10
 */

#ifndef PRUEBAMEMORIA_HPP_
#define PRUEBAMEMORIA_HPP_

#include "Uart/Uart.hpp"
#define ADDRESS_EEPROM 0XA0
//uint8_t datos_w[10];
extern UART_HandleTypeDef huart1;
extern I2C_HandleTypeDef hi2c1;

void pruebalectura(char *mensaje);
#endif /* PRUEBAMEMORIA_HPP_ */
