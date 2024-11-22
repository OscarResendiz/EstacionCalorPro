/*
 * CPantallaInicializaMemoria.cpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#include <GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.hpp>
#include <GUI/PantallaManual/CPantallaManual.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include <RapaTemperatura/CControladorRampas.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>

CPantallaInicializaMemoria::CPantallaInicializaMemoria():
	CPantallaBase(1, (char*)"Iniciando memoria")

{
	// TODO Auto-generated constructor stub
	BarraProgreso=new CBarraProgreso(10, 100, 300,20);
	BarraProgreso->SetMaximo(100);
	BarraProgreso->SetValor(0);
	ControladorRampas.SetControlProgreso(this);
}

CPantallaInicializaMemoria::~CPantallaInicializaMemoria()
{
	// TODO Auto-generated destructor stub
}

void CPantallaInicializaMemoria::Show()
{
	CPantallaBase::Show();
	BarraProgreso->Show();
}
void CPantallaInicializaMemoria::OnProgreso(int valor, int maximo)
{
	BarraProgreso->SetMaximo(maximo);
	BarraProgreso->SetValor(valor);
	BarraProgreso->Show();
}
void CPantallaInicializaMemoria::OnFinProgreso()
{
	ManejadorPantallas.MuestraPantallaManual();
}
void CPantallaInicializaMemoria::Refresca()
{
	ControladorRampas.InicializaMemoria();
}

