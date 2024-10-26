/*
 * ControlVelocidadAire.cpp
 *
 *  Created on: Jul 18, 2024
 *      Author: W10
 */

#include "ControlVelocidadAire.hpp"
#include "stm32f4xx.h"
//#include "stm32f1xx_hal_adc.h"

ControlVelocidadAire::ControlVelocidadAire()
{
	// TODO Auto-generated constructor stub

}

ControlVelocidadAire::~ControlVelocidadAire()
{
	// TODO Auto-generated destructor stub
}

void ControlVelocidadAire::Inicializa()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	 ADC_ChannelConfTypeDef sConfig = {0};
	 hadc1.Instance = ADC1;
	  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2; //NUEVO
	  hadc1.Init.Resolution = ADC_RESOLUTION_12B; //nuevo

	 hadc1.Init.ScanConvMode =  DISABLE;
	 hadc1.Init.ContinuousConvMode = ENABLE;
	 hadc1.Init.DiscontinuousConvMode = DISABLE;
	 hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;//nuevo
	 hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	 hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	 hadc1.State=	 HAL_ADC_STATE_RESET;
	 hadc1.Init.NbrOfConversion = 1;
	  hadc1.Init.DMAContinuousRequests = DISABLE; //nuevo
	  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	 if (HAL_ADC_Init(&hadc1) != HAL_OK)
	 {
	 Error_Handler();
	 }

	 sConfig.Channel = ADC_CHANNEL_3;
	 sConfig.Rank =1; // ADC_REGULAR_RANK_1;
	 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES; //ADC_SAMPLETIME_239CYCLES_5;
	 if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	 {
	 Error_Handler();
	 }
	 HAL_ADC_Start(&hadc1);
}
int ControlVelocidadAire::LeeVelocidad()
{
	Inicializa();
	HAL_ADC_Start(&hadc1);
	int valor=HAL_ADC_GetValue(&hadc1);
	//4095->100
	//valor->X
	//x=valor*100/4095
	return 	100-(int)(valor*100/4095);
}
void ControlVelocidadAire::Error_Handler(void)
{

}
