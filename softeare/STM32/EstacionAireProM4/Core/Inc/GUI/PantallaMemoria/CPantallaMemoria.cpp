/*
 * CPantallaMemoria.cpp
 *
 *  Created on: Sep 27, 2024
 *      Author: W10
 */

#include <GUI/PantallaMemoria/CPantallaMemoria.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include "Uart/Uart.hpp"
#include "Constantes.hpp"
#include <EPROM/CEprom.hpp>

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1;

CPantallaMemoria::~CPantallaMemoria()
{
	// TODO Auto-generated destructor stub
}


CPantallaMemoria::CPantallaMemoria() :
		CPantallaManual()
{
	LabelTitulo->SetTexto((char*)"MODO: MEMORIA");
	LabelMemoria=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"Memoria: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTemperatura->CambiaPosicion(5,65);
	int centroX = DameCentroX();
	LabelTemperaturas->CambiaPosicion(centroX - 150 / 2, 95);
	LabelAire1->CambiaPosicion(5, 135);
	LabelAire2->CambiaPosicion(110, 135);
	LabelEstado->CambiaPosicion(5, 175);

}


 void CPantallaMemoria::GuardaTemperatura()
 {
 }


 void CPantallaMemoria::Show()
 {
	 CPantallaManual::Show();
 	//leo la temperatura desde la memoria
	LabelMemoria->SetTexto((char*)"Memoria: %d", NumeroMemoria);
	LabelMemoria->Show();
	LeeDatosMemoria();
	Estacion->SetTemperatura(Temperatura);
	VelocidadAireInicialPotenciometro=ManejadorControles->GetNivelAire();
 }


void CPantallaMemoria::SetMemoria(int numeroMemoria)
{
	NumeroMemoria=numeroMemoria;
//	DireccionMemoria=DameDireccionMemoria();
}


void CPantallaMemoria::OnBotonCuatroClickEvent()
{
	ManejadorPantallas.MuestraPantallaManual();
}

void CPantallaMemoria::LeeDatosMemoria()
{

	switch(NumeroMemoria)
	{
	case 1:
		Temperatura=Eprom.DameTemperatuarMemoria1();
		VelocidadAire=Eprom.DameVelocidadMemoria1();
		break;
	case 2:
		Temperatura=Eprom.DameTemperatuarMemoria2();
		VelocidadAire=Eprom.DameVelocidadMemoria2();
		break;
	case 3:
		Temperatura=Eprom.DameTemperatuarMemoria3();
		VelocidadAire=Eprom.DameVelocidadMemoria3();
		break;
	}

}
void CPantallaMemoria::LeeDatosEstacion()
{
	CPantallaManual::LeeDatosEstacion();
	int velocidad=ManejadorControles->GetNivelAire();
	if(VelocidadAireInicialPotenciometro>velocidad+DiferenciaAire ||VelocidadAireInicialPotenciometro<velocidad-DiferenciaAire)
	{
		NivelAire =velocidad;
		CambioNIvelAire=true;
	}
	else
	{
		NivelAire =VelocidadAire;
		CambioNIvelAire=false;
	}
}
void CPantallaMemoria::OnPerillaIncremento()
{
	ManejadorPantallas.MuestraPantallaManual();
}
void CPantallaMemoria::OnPerillaDecremento()
{
	ManejadorPantallas.MuestraPantallaManual();
}
void CPantallaMemoria::MuestraInformacion(bool forzar)
{
		LeeDatosEstacion();
		if(CambioNIvelAire==true)
		{
			ManejadorPantallas.MuestraPantallaManual();
			return;
		}
		MuestraTemperaturas(forzar);
		MuestraEstado(forzar);
		MuestraNivelAire(forzar);
		//marco como visible
		SetVisible(true);
}

void CPantallaMemoria::SetEstacion(CEstacionBase *estacion)
{
	CPantallaBase::SetEstacion(estacion);
	Estacion->ActivarCalefactor();
}
