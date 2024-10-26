/*
 * SensorAnalogico.cpp
 *
 *  Created on: Oct 20, 2024
 *      Author: W10
 */

#include <SensorTemperatura/SensorAnalogico.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"
#include "Constantes.hpp"

extern I2C_HandleTypeDef hi2c1;

SensorAnalogico::SensorAnalogico()
{
	// TODO Auto-generated constructor stub

}

SensorAnalogico::~SensorAnalogico()
{
	// TODO Auto-generated destructor stub
}

void SensorAnalogico::Init()
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

	 sConfig.Channel = ADC_CHANNEL_4;//ADC_CHANNEL_3;
	 sConfig.Rank =1; // ADC_REGULAR_RANK_1;
	 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES; //ADC_SAMPLETIME_239CYCLES_5;
	 if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	 {
	 Error_Handler();
	 }
	 HAL_ADC_Start(&hadc1);

}
int SensorAnalogico::LeeTemepatura()
{
	int tiempoactual=HAL_GetTick();
	if(tiempoactual<TiempoTranscurrido)
	{
		return UltimaTemperatura;
	}
	TiempoTranscurrido=tiempoactual+500;

	Init();
	HAL_ADC_Start(&hadc1);
	int valor=HAL_ADC_GetValue(&hadc1);
	//4095->500
	//valor->X
	//x=valor*500/4095
	UltimaTemperatura=(int)(valor*400/4095)+LeeMemoria();
	return 	UltimaTemperatura;

}
void SensorAnalogico::Error_Handler(void)
{

}
int SensorAnalogico::LeeMemoria()
{
 	uint16_t diferencia;
 	if( HAL_I2C_Mem_Read(&hi2c1,ADDRESS_EEPROM,DIRMEMORIARPROM::AJUSTETEMPERATURA,I2C_MEMADD_SIZE_8BIT,(uint8_t*)&diferencia,2,HAL_MAX_DELAY)==HAL_OK)
 	{
 	 	if(diferencia>=-500 && diferencia<=500)
 	 	{
 	 		return diferencia;
 	 	}
	}
 	return 0;
}
