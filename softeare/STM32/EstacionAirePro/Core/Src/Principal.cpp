/*
 * Principal.c
 *
 *  Created on: Jul 16, 2024
 *      Author: W10
 */

#include "stm32f1xx_hal.h"
#include "Principal.hpp"
#include <stdio.h>
#include "Uart/Uart.h"
#include "max6675/max6675.hpp"
#include "ControlVelocidadAire/ControlVelocidadAire.hpp"
#include "Boton/CManejadorBoton.hpp"
#include <ILI9341/ILI9341_GFX.hpp>
#include <ILI9341/ILI9341_STM32_Driver.hpp>
#include <ILI9341/ILI9341_Touchscreen.hpp>
#include "GUI/CRectanguloTft.hpp"
#include "GUI/CEtiquetaTft.hpp"
#include "GUI/CPantallaBase.hpp"
#include "GUI/PantallaManual/CPantallaManual.hpp"
#include <Estaciones/CestacionBaku601.hpp>
#include "Delays/delays.hpp"
#include <Timer/Timer.hpp>
#include "GUI/ManejadorPantallas/CManejadorPantallas.hpp"
#include "ManejadorControles/CManejadorControles.hpp"

CestacionBaku601 *estacion;
//TIM_HandleTypeDef htim2;
CManejadorPantallas ManejadorPantallas;
CManejadorControles *ManejadorControles;

void IncializaSistema()
{
	CTimer timer;
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	estacion = new CestacionBaku601();
	ManejadorControles=new CManejadorControles();
	ILI9341_Init(); //initial driver setup to drive ili9341
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Fill_Screen(WHITE);
	//nicio eltimer
	timer.Init(TIM3, 1,  TIM3_IRQn);
	timer.Start();

}

void EjecutaSistema()
{
	ManejadorPantallas.SetEstacion(estacion);
	ManejadorPantallas.SetManejadorControles(ManejadorControles);
	ManejadorPantallas.MuestraPantallaManual();
	while (1)
	{
		estacion->Procesa();
		ManejadorPantallas.RefrescaPantalla();
		HAL_Delay(1);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	estacion->GPIO_INTERRUPCION(GPIO_Pin);
	ManejadorControles->GPIO_INTERRUPCION(GPIO_Pin);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM3)
	{
		estacion->TimerTick();
	}
}

