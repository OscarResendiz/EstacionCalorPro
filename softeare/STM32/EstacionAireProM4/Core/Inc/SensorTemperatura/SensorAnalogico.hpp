/*
 * SensorAnalogico.hpp
 *
 *  Created on: Oct 20, 2024
 *      Author: W10
 */

#ifndef INC_SENSORTEMPERATURA_SENSORANALOGICO_HPP_
#define INC_SENSORTEMPERATURA_SENSORANALOGICO_HPP_
#include "SensorTemperatura/InterfaceSensorTemperatura/InterfaceSensorTemperatura.hpp"
#include "stm32f4xx.h"

class SensorAnalogico: public InterfaceSensorTemperatura
{
private:
	ADC_HandleTypeDef hadc1;
	int TiempoTranscurrido=0;
	int UltimaTemperatura=0;

public:
	SensorAnalogico();
	virtual ~SensorAnalogico();
	virtual void Init();
	virtual int LeeTemepatura();
private:
	int LeeMemoria();
	void Error_Handler(void);
};

#endif /* INC_SENSORTEMPERATURA_SENSORANALOGICO_HPP_ */
