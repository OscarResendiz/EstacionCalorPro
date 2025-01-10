/*
 * CRampa.cpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#include <RapaTemperatura/CRampa.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"

CRampa::CRampa()
{
	// TODO Auto-generated constructor stub
	ID_RAMPA=0;
	Ocupado=0;
	for(int i=0;i<TAM_NOMBRE;i++)
	{
		Nombre[i]=' ';
	}

}

CRampa::~CRampa()
{
	// TODO Auto-generated destructor stub
}

CRampa CRampa::operator=(CRampa &rampa)
{
	CRampa tmp;
	tmp.ID_RAMPA=rampa.ID_RAMPA;
	tmp.Ocupado=rampa.Ocupado;
	for(int i=0;i<TAM_NOMBRE;i++)
	{
		tmp.Nombre[i]=rampa.Nombre[i];
	}
	return tmp;

}
void CRampa::SetNombre(char* nombre)
{
	for(int i=0;i<TAM_NOMBRE;i++)
	{
		Nombre[i]=nombre[i];
	}
}
CRampa::CRampa(CRampa &&rampa)
{
	ID_RAMPA=rampa.ID_RAMPA;
	Ocupado=rampa.Ocupado;
	for(int i=0;i<TAM_NOMBRE;i++)
	{
		Nombre[i]=rampa.Nombre[i];
	}

}
/*
CRampa::CRampa(CRampa &rampa)
{
	ID_RAMPA=rampa.ID_RAMPA;
	Ocupado=rampa.Ocupado;
	for(int i=0;i<TAM_NOMBRE;i++)
	{
		Nombre[i]=rampa.Nombre[i];
	}

}
*/
