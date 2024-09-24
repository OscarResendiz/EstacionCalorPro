/*
 * Timer.c
 *
 *  Created on: Sep 10, 2024
 *      Author: W10
 */

#include "Timer.hpp"
#include<stdbool.h>

bool CTimer::Init(TIM_TypeDef* TimInstance, uint32_t periodo, 	IRQn_Type Tim_Irq)
{
	Periodo = periodo;
	__HAL_RCC_TIM3_CLK_ENABLE();
	HTim.Instance = TimInstance;
	HTim.Init.CounterMode = TIM_COUNTERMODE_UP;
	HTim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	//la siguiente configuracion es para que me de un tiempo de 83.3 micro segundos para generar la interrupcion
	
	HTim.Init.Period = 3350-1;//3000 - 1; //8399
	HTim.Init.Prescaler = (Periodo * 1) - 1;
	HTim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HTim.Init.RepetitionCounter = 0;
	if (HAL_TIM_Base_Init(&HTim) != HAL_OK)
	{
		return false;
	}

	TIM_ClockConfigTypeDef TimClock =
	{ 0 };
	TimClock.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&HTim, &TimClock) != HAL_OK)
	{
		return false;
	}

	TIM_MasterConfigTypeDef TimMaster =
	{ 0 };
	TimMaster.MasterSlaveMode = TIM_SLAVEMODE_DISABLE;
	TimMaster.MasterOutputTrigger = TIM_TRGO_RESET;
	if (HAL_TIMEx_MasterConfigSynchronization(&HTim, &TimMaster) != HAL_OK)
	{
		return false;
	}

	HAL_NVIC_SetPriority(Tim_Irq, 5, 0);
	HAL_NVIC_EnableIRQ(Tim_Irq);
	return true;
}
void CTimer::Start()
{
	HAL_TIM_Base_Start_IT(&HTim);
}
void CTimer::Stop()
{
	HAL_TIM_Base_Stop_IT(&HTim);
}
