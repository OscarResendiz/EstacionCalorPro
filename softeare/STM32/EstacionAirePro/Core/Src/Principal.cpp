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
#include <Estaciones/CestacionBaku601.hpp>
#include "Delays/delays.hpp"
#include <Timer/Timer.hpp>
#include "GUI/ManejadorPantallas/CManejadorPantallas.hpp"
CestacionBaku601 *estacion;
//TIM_HandleTypeDef htim2;
CManejadorPantallas ManejadorPantallas;
void IncializaSistema()
{
	CTimer timer;
	USART1_UART_Init();
	SerialPrintf("\r\IniciandoSistema");
	uartx_write_text("HOLA");
	//TIMX->CR1|=1>>0;
	//delay_us_tim_init();
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	USART1_UART_Init();
	estacion = new CestacionBaku601();
	ILI9341_Init(); //initial driver setup to drive ili9341
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Fill_Screen(WHITE);
	//nicio eltimer
	timer.Init(TIM3, 1,  TIM3_IRQn);
	timer.Start();

}

void EjecutaSistema()
{
//	CManejadorPantallas* manejador=CManejadorPantallas::DameControlador();
	ManejadorPantallas.SetEstacion(estacion);
//	CPantallaManual *pantalla = new CPantallaManual();
	ManejadorPantallas.MuestraPantallaManual();
//	pantalla->SetEstacion(estacion);
//	pantalla->Show();
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
/*
	if(GPIO_Pin==EncoderClk_Pin)
	{
		estacion->InterrupcionEncoder();
	}
	else if(GPIO_Pin==CruceCero_Pin)
	{
		estacion->CruceXCero();
	}
*/
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM3)
	{
		estacion->TimerTick();
		//HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
	}
}

