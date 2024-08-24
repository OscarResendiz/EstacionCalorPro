/*
 * Principal.c
 *
 *  Created on: Jul 16, 2024
 *      Author: W10
 */

#include "stm32f1xx_hal.h"
#include "Principal.hpp"
#include <stdio.h>
#include "Uart/Uart.hpp"
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
#include <Estaciones/CestacionVirtual.hpp>
#include "Delays/delays.hpp"

CestacionVirtual *estacion;
//TIM_HandleTypeDef htim2;

void IncializaSistema()
{
	//TIMX->CR1|=1>>0;
	//delay_us_tim_init();
	  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	USART1_UART_Init();
	estacion=new CestacionVirtual();
	ILI9341_Init(); //initial driver setup to drive ili9341
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
}

void EjecutaSistema()
{
	CPantallaManual *pantalla=new CPantallaManual();
	pantalla->SetEstacion(estacion);
	pantalla->Show();
	while(1)
	{
		estacion->Procesa();
		pantalla->Refresca();
		HAL_Delay(1);
	}
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	estacion->InterrupcionEncoder();
}
