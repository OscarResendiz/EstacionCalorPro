/*
 * CPantallaCalibracion.cpp
 *
 *  Created on: Oct 22, 2024
 *      Author: W10
 */

#include <GUI/PantallaCalibracion/CPantallaCalibracion.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include "stm32f4xx_hal_conf.h"
#include <EPROM/CEprom.hpp>

extern I2C_HandleTypeDef hi2c1;

CPantallaCalibracion::CPantallaCalibracion():
CPantallaBase(1, (char*)"   Modo: Calibrar")
{
	TemperaturaODiferencia=true;
	Diferencia=0;
	Temperatura=0;
	DiferenciaAnterior=0;
	// TODO Auto-generated constructor stub
	LabelTemperatura=new CEtiquetaTft( 5, 40, 50, 20, COLOR::BLACK,(char*)"temp: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	TextTemperatura = new CEtiquetaTft( 95, 40, 150, 30,COLOR::WHITE, (char*)"000", COLOR::BLACK, 3, 1, COLOR::RED);

	LabelDiferencia=new CEtiquetaTft( 5, 80, 50, 20, COLOR::BLACK,(char*)"Dif: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	TextDiferencia = new CEtiquetaTft( 95, 80, 150, 30,COLOR::GREY, (char*)"000", COLOR::BLACK, 3, 1, COLOR::RED);
	TextDiferencia->SetSeparacion(5, 5);

	LabelTemperatura2=new CEtiquetaTft( 5, 120, 50, 20, COLOR::BLACK,(char*)"temp: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	TextTemperatura2 = new CEtiquetaTft( 95, 120, 150, 30,COLOR::GREY, (char*)"000", COLOR::BLACK, 3, 1, COLOR::RED);

	LabelAire = new CEtiquetaTft( 5, 160, 200, 30, COLOR::BLACK,(char*) "Aire: 00",COLOR::WHITE, 3, 0, COLOR::RED);

	LabelGuardar=new CEtiquetaTft( 10, 200, 130, 30, COLOR::GREEN,(char*)"GUARDAR", COLOR::BLACK, 3, 1, COLOR::WHITE);
	LabelCancelar=new CEtiquetaTft( 160, 200, 145, 30, COLOR::RED,(char*)"CANCELAR", COLOR::BLACK, 3, 1, COLOR::WHITE);
}

CPantallaCalibracion::~CPantallaCalibracion()
{
	// TODO Auto-generated destructor stub
}

 void CPantallaCalibracion::Show()
 {
		LeeMemoria();
	 	CPantallaBase::Show();
	 	LabelTemperatura->Show();
		LabelGuardar->Show();
		LabelCancelar->Show();
		LabelAire->Show();
		TextTemperatura->Show();
		LabelDiferencia->Show();
		TextDiferencia->Show();
	 	LabelTemperatura2->Show();
		TextTemperatura2->Show();
		MuestraInformacion();
 }
void CPantallaCalibracion::Refresca()
{
	MuestraInformacion();
}
void CPantallaCalibracion::OnBotonTresClickEvent()
{
	 ManejadorPantallas.MuestraMenuPrincipal();

}
void CPantallaCalibracion::MuestraInformacion()
{
	LeeDatosEstacion();

	if(TemperaturaAnterior!=Temperatura)
	{
		TextTemperatura->SetTexto((char*)"%d", Temperatura);
		TextTemperatura->Show();
		TemperaturaAnterior=Temperatura;
	}

	if(DiferenciaAnterior!=Diferencia)
	{
		DiferenciaAnterior=Diferencia;
		TextDiferencia->SetTexto((char*)"%d",Diferencia);
		TextDiferencia->Show();
	}

	if( VelocidadAireAnterior!=VelocidadAire)
	{
		LabelAire->SetTexto((char*)"Aire: %d", VelocidadAire);
		LabelAire->Show();
		VelocidadAireAnterior=VelocidadAire;
	}
}
void CPantallaCalibracion::OnBotonPerillaClickEvent()
{
	TemperaturaODiferencia=!TemperaturaODiferencia;
	if(TemperaturaODiferencia==true)
	{
		TextTemperatura->SetBackColor(COLOR::WHITE);
		TextDiferencia->SetBackColor(COLOR::GREY);
	}
	else
	{
		TextTemperatura->SetBackColor(COLOR::GREY);
		TextDiferencia->SetBackColor(COLOR::WHITE);
	}
	TextTemperatura->Show();
	TextDiferencia->Show();
}

void CPantallaCalibracion::OnPerillaIncremento()
{
	if(TemperaturaODiferencia==true)
	{
		if(Temperatura<=500)
			Temperatura++;
		TextTemperatura->SetTexto((char*)"%d",Temperatura);
		TextTemperatura->Show();
	}
	else
	{
		if(Diferencia>=500)
			return;
		Diferencia++;
		Estacion->SetTemperatura(Temperatura);
		TextDiferencia->SetTexto((char*)"%d",Diferencia);
		TextDiferencia->Show();
	}
	TextTemperatura2->SetTexto((char*)"%d",Temperatura+Diferencia);
	TextTemperatura2->Show();
}
void CPantallaCalibracion::OnPerillaDecremento()
{
	if(TemperaturaODiferencia==true)
	{
		if(Temperatura<=0)
			return;
		Temperatura--;
		Estacion->SetTemperatura(Temperatura);
		TextTemperatura->SetTexto((char*)"%d",Temperatura);
		TextTemperatura->Show();
	}
	else
	{
		if(Diferencia>-500)
			Diferencia--;
		TextDiferencia->SetTexto((char*)"%d",Diferencia);
		TextDiferencia->Show();
	}
	TextTemperatura2->SetTexto((char*)"%d",Temperatura+Diferencia);
	TextTemperatura2->Show();
}

void CPantallaCalibracion::LeeMemoria()
{
	Temperatura=Eprom.DameTemperaturaManual();
	Diferencia=Eprom.DameAjusteTemperatura();
	Estacion->SetTemperatura(Temperatura);
}
void CPantallaCalibracion::LeeDatosEstacion()
{
	VelocidadAire = ManejadorControles->GetNivelAire();
	Estacion->SetNivelAire(VelocidadAire);
}
void CPantallaCalibracion::OnBotonUnoClickEvent()
{
	Eprom.GuardaAjusteTemperatura(Diferencia);
	 ManejadorPantallas.MuestraMenuPrincipal();
}
void CPantallaCalibracion::SetEstacion(CEstacionBase *estacion)
{
	CPantallaBase::SetEstacion(estacion);
	Estacion->ActivarCalefactor();
}
