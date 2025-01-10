/*
 * CPantallaEliminarRampa.cpp
 *
 *  Created on: Jan 8, 2025
 *      Author: W10
 */

#include <GUI/Rampa/PantallaEliminarRampa/CPantallaEliminarRampa.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include <EPROM/CEprom.hpp>
#include<string.h>
#include <RapaTemperatura/CControladorPasosRampa.hpp>

CPantallaEliminarRampa::CPantallaEliminarRampa():
CPantallaBase(1, (char*)" ELIMINAR RAMPA")
{
	// TODO Auto-generated constructor stub
	LabelMemoria=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"Eliminar: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelGuardar=new CEtiquetaTft( 10, 200, 130, 30, COLOR::GREEN,(char*)"ACEPTAR", COLOR::BLACK, 3, 1, COLOR::WHITE);
	LabelCancelar=new CEtiquetaTft( 160, 200, 145, 30, COLOR::RED,(char*)"CANCELAR", COLOR::BLACK, 3, 1, COLOR::WHITE);

}

CPantallaEliminarRampa::~CPantallaEliminarRampa()
{
	// TODO Auto-generated destructor stub
}

void CPantallaEliminarRampa::OnBotonUnoClickEvent()
{
	ControladorRampas.EliminaRampa(ID_Rampa);
	ControladorPasosRampa.EliminaPasosRampa(ID_Rampa);
	ManejadorPantallas.MuestraMenuRampa();
}
void CPantallaEliminarRampa::OnBotonTresClickEvent()
{

	 ManejadorPantallas.MuestraPantallaRampa(ID_Rampa);

}

void CPantallaEliminarRampa::SetIdRampa(int id_rampa)
{
	ID_Rampa=id_rampa;
	CRampa rampa=	ControladorRampas.DameRampa(ID_Rampa);
	sprintf(TextoEliminar,"Eliminar %s?",rampa.Nombre);
}

void CPantallaEliminarRampa::Show()
{
	CPantallaBase::Show();

	LabelMemoria->SetTexto(TextoEliminar);
	LabelMemoria->Show();
	LabelGuardar->Show();
	LabelCancelar->Show();

}

