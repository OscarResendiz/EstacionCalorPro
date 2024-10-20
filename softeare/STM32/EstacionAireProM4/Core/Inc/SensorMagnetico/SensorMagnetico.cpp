/*
 * SensorMagnetico.cpp
 *
 *  Created on: Aug 23, 2024
 *      Author: W10
 */

#include <SensorMagnetico/SensorMagnetico.hpp>
#include "stm32f4xx.h"
#include "Constantes.hpp"
#include "max6675/max6675.hpp"
#include "Uart/Uart.hpp"

/*
void PruebaTempratura(int n)
{
//	HAL_InitTick()
	int temperatura;
	MAX6675 thermocouple;
	double t=1/SystemCoreClock;
	//if(n==0)
	{
	thermocouple.SetConfigCkPin(GPIOA, GPIO_PIN_1);
	thermocouple.SetConfigCsPin(GPIOA, GPIO_PIN_2);
	thermocouple.SetConfigDatPin(GPIOA, GPIO_PIN_0);
	thermocouple.Init();
	}
	int x=10;
	while(x>1)
	{
	//	x--;

		temperatura=thermocouple.MAX6675_leex();
		SerialPrintf("\r\nTemperatura: %d intento = %d",temperatura,n);
		HAL_Delay(1000);
	}
}
*/
SensorMagnetico::SensorMagnetico()
{
	// TODO Auto-generated constructor stub

}

SensorMagnetico::~SensorMagnetico()
{
	// TODO Auto-generated destructor stub
}

void SensorMagnetico::Configurar(GPIO_TypeDef *puerto, uint16_t pin)
{
	GPIO_Port = puerto;
	Gpio_Pin = pin;

}
void SensorMagnetico::Init()
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	GPIO_InitStruct.Pin = Gpio_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	//PruebaTempratura(0);
	HAL_GPIO_Init(GPIO_Port, &GPIO_InitStruct);
}
void SensorMagnetico::AsignaManejadorEventos(
		CManejadorEventoSensorMagnetico *manejador)
{
	Manejador = manejador;

}
int SensorMagnetico::Leer()
{
	return HAL_GPIO_ReadPin(GPIO_Port, Gpio_Pin); // lee el pin

}

void SensorMagnetico::Procesa()
{
	int estado = 0;
	if (Manejador == NULL)
	{
		return;
	}
	estado = Leer();

	if (Estado == estado)
	{
		//no ha cambiado por lo que no hay evento que informar
		return;
	}
	if (estado != PreEstado)
	{
		//acaba de cambiar
		ReboteMilis = HAL_GetTick();  //leo el tiempo actual
		PreEstado = estado;
		return;
	}
	//leo el tiempo actual
	int tiempo = HAL_GetTick();
	if ((tiempo - ReboteMilis) < TIEMPO_REBOTE)
	{
		//como todavia no pasa el tiempo de espera para evitar rebotes no hago nada
		return;
	}
	//ya filtre los rebotes, por lo que ahora si informo del cambio de estado del boton
	Estado = estado;
	Manejador->OnSensorMagneticoChange(Estado);
}
