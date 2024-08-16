/*
 * Pwm.cpp
 *
 *  Created on: Aug 14, 2024
 *      Author: W10
 */

#include <PWM/Pwm.hpp>
#include "stm32f1xx_hal.h"
#include "stdlib.h"

Pwm::Pwm()
{
	// TODO Auto-generated constructor stub

}

Pwm::~Pwm()
{
	// TODO Auto-generated destructor stub
}
void Pwm::Init(TIM_TypeDef * timer, int chanel,int periodo)
{
	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  TIM_OC_InitTypeDef sConfigOC = {0};

	  Htim.Instance = timer;
	  Htim.Init.Prescaler = 0;
	  Htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	  Htim.Init.Period = periodo;
	  Htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  Htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	  if (HAL_TIM_Base_Init(&Htim) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&Htim, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  if (HAL_TIM_PWM_Init(&Htim) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&Htim, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 0;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&Htim, &sConfigOC, chanel) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  HAL_TIM_MspPostInit(&Htim);
	HAL_TIM_PWM_Start(&Htim,chanel);
	Htim.Instance->CCR1=25000;
}
void Pwm::SicloTrabajo(int siclo)
{
	// si 65535->100
	// x->siclo
	int valor=siclo*Htim.Init.Period/100;
	Htim.Instance->CCR1=valor;
}

void Pwm::Error_Handler(void)
{

}
void Pwm::HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(htim->Instance==TIM1)
  {
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM1 GPIO Configuration
    PA8     ------> TIM1_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  }
  else if(htim->Instance==TIM2)
  {
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM2 GPIO Configuration
    PA15     ------> TIM2_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    __HAL_AFIO_REMAP_TIM2_PARTIAL_1();
  }

}
