/*
 * max6675.c
 *
 *  Created on: Apr 9, 2023
 *      Author: Alcides Ramos
 */

#include "Max6675/Max6675.hpp"
MAX6675::MAX6675()
{

}
void MAX6675::SetConfigDatPin(GPIO_TypeDef *portDat, uint16_t pinDat)
{
	DAT_MAX_GPIO_Port = portDat;
	DAT_MAX_Pin = pinDat;

}
void MAX6675::SetConfigCkPin(GPIO_TypeDef *portCk, uint16_t pinCk)
{
	CK_MAX_GPIO_Port = portCk;
	CK_MAX_Pin = pinCk;

}
void MAX6675::SetConfigCsPin(GPIO_TypeDef *portCs, uint16_t pinCs)
{
	CS_MAX_GPIO_Port = portCs;
	CS_MAX_Pin = pinCs;

}

void MAX6675::MAX6675_init()
{
	HAL_GPIO_WritePin(CK_MAX_GPIO_Port, CK_MAX_Pin,
			GPIO_PinState::GPIO_PIN_RESET); //SACA UN 0 reloj
	HAL_GPIO_WritePin(CS_MAX_GPIO_Port, CS_MAX_Pin,
			GPIO_PinState::GPIO_PIN_SET); //APAGA el modulo
	HAL_Delay(100);
}

uint8_t MAX6675::MAX6675_pulso()
{
	uint8_t lei;
	HAL_GPIO_WritePin(CK_MAX_GPIO_Port, CK_MAX_Pin,
			GPIO_PinState::GPIO_PIN_SET); //SACA UN 1 reloj
	Delay_us(10);
	lei = HAL_GPIO_ReadPin(DAT_MAX_GPIO_Port, DAT_MAX_Pin); // lee el pin
	HAL_GPIO_WritePin(CK_MAX_GPIO_Port, CK_MAX_Pin,
			GPIO_PinState::GPIO_PIN_RESET); //SACA UN 0 reloj
	Delay_us(10);
	return lei;
}

float MAX6675::MAX6675_lee()
{
	uint16_t sensor_dato;
	uint16_t max6675_dato = 0;
	int8_t cont;
	HAL_GPIO_WritePin(CS_MAX_GPIO_Port, CS_MAX_Pin,
			GPIO_PinState::GPIO_PIN_RESET); //Habilita el modulo
	for (cont = 15; cont >= 0; cont--)
	{
		if (MAX6675_pulso() == 1)
			max6675_dato = max6675_dato | 1 << cont;

	}

	HAL_GPIO_WritePin(CS_MAX_GPIO_Port, CS_MAX_Pin,
			GPIO_PinState::GPIO_PIN_SET); //APAGA el modulo
	sensor_dato = (max6675_dato >> 3); //desplaz 3 veces
	return (((float) sensor_dato * 0.25));
}
void MAX6675::Init()
{

	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	HAL_GPIO_WritePin(GPIOA, CK_MAX_Pin | CS_MAX_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pin : DAT_MAX_Pin */
	GPIO_InitStruct.Pin = DAT_MAX_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(DAT_MAX_GPIO_Port, &GPIO_InitStruct);
	/*Configure GPIO pins : CK_MAX_Pin CS_MAX_Pin */
	GPIO_InitStruct.Pin = CK_MAX_Pin | CS_MAX_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	MAX6675_init();
}
