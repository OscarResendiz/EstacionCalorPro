/*
 * CPantallaPaso.cpp
 *
 *  Created on: Jan 9, 2025
 *      Author: W10
 */

#include <GUI/Rampa/PantallaPaso/CPantallaPaso.hpp>
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>

CPantallaPaso::CPantallaPaso():
CPantallaMenuBase((char*) " PASO")
{
	// TODO Auto-generated constructor stub
	AgregaMenuItem((char*)"Modificar",MENU_PANTALLA_PASO::PANTALLA_PASO_MODIFICAR);
	AgregaMenuItem((char*)"Eliminar", MENU_PANTALLA_PASO::PANTALLA_PASO_ELIMINAR);
	AgregaMenuItem((char*)"Salir", MENU_PANTALLA_PASO::PANTALLA_PASO_SALIR);

}

CPantallaPaso::~CPantallaPaso()
{
	// TODO Auto-generated destructor stub
}

void CPantallaPaso::SetIdPaso(int id_rampa,int id_Paso)
{
	ID_Paso=id_Paso;
	ID_Rampa=id_rampa;
//	CRampa rampa=ControladorRampas.DameRampa(ID_Rampa);
//	this->SetTituloPantalla(rampa.Nombre);
}
void CPantallaPaso::OnMenuEvent(int identificador)
{

	switch(identificador)
	{
	case MENU_PANTALLA_PASO::PANTALLA_PASO_SALIR:
		ManejadorPantallas.AsignaPantallaPasosRampa(ID_Rampa);
		break;
	case MENU_PANTALLA_PASO::PANTALLA_PASO_MODIFICAR:
		ManejadorPantallas.MuestraPantallaEdicionPaso(ID_Rampa, ID_Paso);
		break;
	case MENU_PANTALLA_PASO::PANTALLA_PASO_ELIMINAR:
		ManejadorPantallas.MuestraPantallaEliminarPaso(ID_Rampa,ID_Paso);
		break;
	}

}
