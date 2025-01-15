/*
 * CPaso.cpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#include <RapaTemperatura/CPaso.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"

CPaso::CPaso()
{
	// TODO Auto-generated constructor stub
	Ocupado=0;
	ID_Rampa=0;
	ID_Paso=0;
	Temperatura=0;
	NivelAire=0;
	Minutos=0;

}

CPaso::~CPaso()
{
	// TODO Auto-generated destructor stub
}

