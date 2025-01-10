/*
 * CPaso.hpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#ifndef INC_RAPATEMPERATURA_CPASO_HPP_
#define INC_RAPATEMPERATURA_CPASO_HPP_
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"

class CPaso
{

public:
	uint8_t Ocupado;
	uint8_t ID_Rampa;
	uint8_t ID_Paso;
	uint16_t Temperatura;
	uint8_t NivelAire;
	uint8_t Segundos;

	CPaso();
	virtual ~CPaso();
};

#endif /* INC_RAPATEMPERATURA_CPASO_HPP_ */
