/*
 * Calefactor.cpp
 *
 *  Created on: Aug 22, 2024
 *      Author: W10
 */

#include <Calefactor/Calefactor.hpp>
#include "Uart/Uart.hpp"
Calefactor::Calefactor()
{
	// TODO Auto-generated constructor stub

}

Calefactor::~Calefactor()
{
	// TODO Auto-generated destructor stub
}

void Calefactor::Configurar(GPIO_TypeDef *puerto, uint16_t pin)
{
	GPIO_Port = puerto;
	Gpio_Pin = pin;

}
void Calefactor::Init()
{
	GPIO_InitTypeDef GPIO_InitStruct =	{ 0 };
	GPIO_InitStruct.Pin = Gpio_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIO_Port, &GPIO_InitStruct);
	Apagar();
}
void Calefactor::Encender()
{
	HAL_GPIO_WritePin(GPIO_Port, Gpio_Pin,	GPIO_PinState::GPIO_PIN_SET);
	Estado=ENCENDIDO;
}
void Calefactor::Apagar()
{
	HAL_GPIO_WritePin(GPIO_Port, Gpio_Pin,	GPIO_PinState::GPIO_PIN_RESET);
	Estado=APAGADO;
}
int Calefactor::DameEstado()
{
	return Estado;
}

