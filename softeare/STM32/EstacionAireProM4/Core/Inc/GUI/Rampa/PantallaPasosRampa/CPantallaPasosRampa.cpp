/*
 * CPantallaPasosRampa.cpp
 *
 *  Created on: Jan 6, 2025
 *      Author: W10
 */

#include <GUI/Rampa/PantallaPasosRampa/CPantallaPasosRampa.hpp>
#include <RapaTemperatura/CControladorPasosRampa.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include "GUI/Menu/CMenuItem.hpp"
#include "GUI/CEtiquetaTft.hpp"
#include "GUI/Menu/CMenu.hpp"
#include "string.h"
#include <RapaTemperatura/CControladorRampas.hpp>
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>
CControladorPasosRampa ControladorPasosRampa;

CPantallaPasosRampa::CPantallaPasosRampa(int id_Rampa):
CPantallaMenuBase((char*) " Menu PASOS")
{
	// TODO Auto-generated constructor stub
	ID_Rampa=id_Rampa;

}
void CPantallaPasosRampa::SetIDRampa(int idRampa)
{
	ID_Rampa=idRampa;
	int numeroPaso=1;
	int id_paso=0;
	char texto[20];
	this->BorraMenu();
	CRampa rampa=ControladorRampas.DameRampa(ID_Rampa);
	this->SetTituloPantalla(rampa.Nombre);

	int npasos=ControladorPasosRampa.DameNumeroPasosRampa(ID_Rampa);
	for(int i=0;i<npasos;i++)
	{
		CPaso paso=		ControladorPasosRampa.DameSiguientePaso(ID_Rampa,id_paso);
		if(paso.Ocupado==0)
			continue;
		id_paso=paso.ID_Paso;
		sprintf(texto,"Paso %d",numeroPaso);
		numeroPaso++;
		AgregaMenuItem(texto,paso.ID_Paso);
	}
	AgregaMenuItem((char*)"Agregar", MENU_PASO::MENU_PASO_AGREGAR);
	AgregaMenuItem((char*)"Salir", MENU_PASO::MENU_PASO_SALIR);

}
CPantallaPasosRampa::~CPantallaPasosRampa()
{
	// TODO Auto-generated destructor stub
}

void CPantallaPasosRampa::OnMenuEvent(int identificador)
{
	switch(identificador)
	{
	case MENU_PASO::MENU_PASO_SALIR:
		ManejadorPantallas.MuestraPantallaRampa(ID_Rampa);
		break;
	case MENU_PASO::MENU_PASO_AGREGAR:
		ManejadorPantallas.MuestraPantallaEdicionPaso(ID_Rampa,-1);
		break;
	default:
		ManejadorPantallas.MuestraPantallaPaso(ID_Rampa,identificador);
		//ManejadorPantallas.MuestraPantallaRampa(identificador);

	}

}
