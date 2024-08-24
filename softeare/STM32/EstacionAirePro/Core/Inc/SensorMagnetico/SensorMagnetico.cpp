/*
 * SensorMagnetico.cpp
 *
 *  Created on: Aug 23, 2024
 *      Author: W10
 */

#include <SensorMagnetico/SensorMagnetico.hpp>
#include "stm32f1xx.h"
#include "Constantes.hpp"

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
