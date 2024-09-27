/*
 * Boton.cpp
 *
 *  Created on: Jul 19, 2024
 *      Author: W10
 */

#include "Boton/CManejadorBoton.hpp"
#include "Constantes.hpp"

CManejadorBoton::CManejadorBoton()
{
	// TODO Auto-generated constructor stub

}

CManejadorBoton::~CManejadorBoton()
{
	// TODO Auto-generated destructor stub
}

void CManejadorBoton::Configurar(GPIO_TypeDef *puerto, uint16_t pin,uint8_t identificador)
{
	GPIO_Port = puerto;
	Gpio_Pin = pin;
	Identificador = identificador;
}
void CManejadorBoton::Init()
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	GPIO_InitStruct.Pin = Gpio_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIO_Port, &GPIO_InitStruct);
}
int CManejadorBoton::Leer()
{
	return HAL_GPIO_ReadPin(GPIO_Port, Gpio_Pin); // lee el pin

}
void CManejadorBoton::AsignaManejadorEventos(CManejadorEventosBoton *manejador)
{
	Manejador = manejador;
}
void CManejadorBoton::Procesa(int gpio_pin)
{
	if (Manejador == NULL)
		return;
	if(gpio_pin!=Gpio_Pin)
		return;
	int tiempoClick = 0;
	int estado = 0;
	estado = Leer();
	//leo el tiempo actual
	int tiempo = HAL_GetTick();
	if ((tiempo - ReboteMilis) < TIEMPO_REBOTE)
	{
		//como todavia no pasa el tiempo de espera para evitar rebotes no hago nada
		return;
	}
	ReboteMilis = HAL_GetTick();  //leo el tiempo actual

	//ya filtre los rebotes, por lo que ahora si informo del cambio de estado del boton
	Estado = estado;
	if (Estado == BOTON_SUELTO)
	{
		Manejador->OnBotonSueltoEvent(Identificador);
		tiempoClick = HAL_GetTick() - TiempoInicioClick;
		Manejador->OnBotonClickEvent(Identificador, tiempoClick);
	}
	if (Estado == BOTON_PRESIONADO)
	{
		TiempoInicioClick = HAL_GetTick();
		Manejador->OnBotonPresionadoEvent(Identificador);
	}
}
