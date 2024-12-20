/*
 * max6675.c
 *
 *  Created on: Apr 9, 2023
 *      Author: Alcides Ramos
 */

#include "SensorTemperatura/Max6675/Max6675.hpp"
#include "Uart/Uart.hpp"
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
int MAX6675::LeeTemepatura()
{
	//Init();
	uint16_t sensor_dato;
	uint16_t max6675_dato=0 ;
	int8_t cont;
	int tiempoactual=HAL_GetTick();
	if(tiempoactual<TiempoTranscurrido)
	{
		return UltimaTemperatura;
	}
	TiempoTranscurrido=tiempoactual+500;

	HAL_GPIO_WritePin(CS_MAX_GPIO_Port, CS_MAX_Pin,	GPIO_PinState::GPIO_PIN_RESET); //Habilita el modulo
	Retardo();
	for (cont = 15; cont >= 0; cont--)
	{
		if (MAX6675_pulso() == 1)
			max6675_dato = max6675_dato | 1 << cont;

	}

	HAL_GPIO_WritePin(CS_MAX_GPIO_Port, CS_MAX_Pin,	GPIO_PinState::GPIO_PIN_SET); //APAGA el modulo
	sensor_dato = (max6675_dato >> 3); //desplaz 3 veces
	UltimaTemperatura= (sensor_dato * 0.25);//-90; //0.25

	return UltimaTemperatura;

}
uint8_t MAX6675::MAX6675_pulso()
{
	uint8_t lei;
	HAL_GPIO_WritePin(CK_MAX_GPIO_Port, CK_MAX_Pin,	GPIO_PinState::GPIO_PIN_SET); //SACA UN 1 reloj
	Retardo();
	lei = HAL_GPIO_ReadPin(DAT_MAX_GPIO_Port, DAT_MAX_Pin); // lee el pin
//	Retardo();
	HAL_GPIO_WritePin(CK_MAX_GPIO_Port, CK_MAX_Pin,	GPIO_PinState::GPIO_PIN_RESET); //SACA UN 0 reloj
	Retardo();
	return lei;
}
void MAX6675::Retardo()
{
	uint16_t time=10;
	uint32_t frecuencia=HAL_RCC_GetHCLKFreq();
	uint16_t delay= time*(frecuencia/1000000);
	for(int i=0;i<delay;i+=5)
	{
		__ASM("NOP");
	}

}
void MAX6675::Init()
{

	GPIO_InitTypeDef GPIO_InitStruct =	{ 0 };

	HAL_GPIO_WritePin(GPIOA, CK_MAX_Pin | CS_MAX_Pin, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = DAT_MAX_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull =GPIO_PULLUP;//  GPIO_NOPULL;
	HAL_GPIO_Init(DAT_MAX_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : CK_MAX_Pin CS_MAX_Pin */
	GPIO_InitStruct.Pin = CK_MAX_Pin | CS_MAX_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	HAL_GPIO_WritePin(CK_MAX_GPIO_Port, CK_MAX_Pin, GPIO_PinState::GPIO_PIN_RESET); //SACA UN 0 reloj
	HAL_GPIO_WritePin(CS_MAX_GPIO_Port, CS_MAX_Pin, GPIO_PinState::GPIO_PIN_SET); //APAGA el modulo

	HAL_Delay(100);
	TiempoTranscurrido = HAL_GetTick();
}
