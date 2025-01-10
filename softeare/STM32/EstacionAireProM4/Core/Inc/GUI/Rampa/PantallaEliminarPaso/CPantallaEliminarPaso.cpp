/*
 * CPantallaEliminarPaso.cpp
 *
 *  Created on: Jan 9, 2025
 *      Author: W10
 */

#include <GUI/Rampa/PantallaEliminarPaso/CPantallaEliminarPaso.hpp>
#include <RapaTemperatura/CControladorPasosRampa.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>

CPantallaEliminarPaso::CPantallaEliminarPaso():
CPantallaBase(1, (char*)" ELIMINAR PASO")
{
	// TODO Auto-generated constructor stub
	LabelMemoria=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"Eliminar: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelGuardar=new CEtiquetaTft( 10, 200, 130, 30, COLOR::GREEN,(char*)"ACEPTAR", COLOR::BLACK, 3, 1, COLOR::WHITE);
	LabelCancelar=new CEtiquetaTft( 160, 200, 145, 30, COLOR::RED,(char*)"CANCELAR", COLOR::BLACK, 3, 1, COLOR::WHITE);

}

CPantallaEliminarPaso::~CPantallaEliminarPaso()
{
	// TODO Auto-generated destructor stub
}

void CPantallaEliminarPaso::OnBotonUnoClickEvent()
{
	//ControladorRampas.EliminaRampa(ID_Rampa);
	ControladorPasosRampa.EliminaPasoRampa(ID_Paso);
	ManejadorPantallas.AsignaPantallaPasosRampa(ID_Rampa);
}
void CPantallaEliminarPaso::OnBotonTresClickEvent()
{

	 ManejadorPantallas.MuestraPantallaPaso(ID_Rampa, ID_Paso);

}

void CPantallaEliminarPaso::SetIdPaso(int id_rampa,int id_paso)
{
	ID_Paso=id_paso;
	ID_Rampa=id_rampa;
	//CRampa rampa=	ControladorRampas.DameRampa(ID_Rampa);
	sprintf(TextoEliminar,"Eliminar ?");
}

void CPantallaEliminarPaso::Show()
{
	CPantallaBase::Show();
	LabelMemoria->SetTexto(TextoEliminar);
	LabelMemoria->Show();
	LabelGuardar->Show();
	LabelCancelar->Show();

}

