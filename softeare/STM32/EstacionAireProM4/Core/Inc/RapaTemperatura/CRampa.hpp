/*
 * CRampa.hpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#ifndef INC_RAPATEMPERATURA_CRAMPA_HPP_
#define INC_RAPATEMPERATURA_CRAMPA_HPP_
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"

#define TAM_NOMBRE 15
class CRampa
{
public:
	uint8_t Ocupado;
	uint16_t ID_RAMPA;
	char Nombre[TAM_NOMBRE]; //nombre de la rampa
	CRampa();
	virtual ~CRampa();
	CRampa operator=(CRampa &rampa);
	void SetNombre(char* nombre);
	CRampa(CRampa &&rampa);
//	CRampa(CRampa &rampa);
};

#endif /* INC_RAPATEMPERATURA_CRAMPA_HPP_ */
