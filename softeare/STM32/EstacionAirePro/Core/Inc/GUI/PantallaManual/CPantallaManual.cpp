/*
 * CPantallaManual.cpp
 *
 *  Created on: Jul 25, 2024
 *      Author: W10
 */

#include <GUI/PantallaManual/CPantallaManual.hpp>

CPantallaManual::~CPantallaManual()
{
	// TODO Auto-generated destructor stub
}

CPantallaManual::CPantallaManual() :
		CPantallaBase(1, "   Modo: Manual")
{
	LabelTemperatura = new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,"Temperatura", COLOR::WHITE, 3, 0, COLOR::WHITE);
	int centroX = DameCentroX();
	LabelTemperaturas = new CEtiquetaTft( centroX - 150 / 2, 65, 150, 30,COLOR::WHITE, "000/000", COLOR::BLACK, 3, 1, COLOR::RED);
	LabelTemperaturas->SetSeparacion(5, 5);
	LabelAire = new CEtiquetaTft( 5, 105, 200, 30, COLOR::BLACK, "Aire: 00",COLOR::WHITE, 3, 0, COLOR::RED);
	LabelEstado = new CEtiquetaTft( 5, 145, 300, 35, COLOR::BLACK,"Estado: REPOSO", COLOR::WHITE, 3, 0, COLOR::RED);
	LabelEstado->SetSeparacion(15, 5);
}

void CPantallaManual::SetEstacion(CEstacionBase *estacion)
{
	Estacion = estacion;
	//asigno los evetos de la estacion
	Estacion->SetManejadorControles(this);
	Estacion->ActivarCalefactor();
}

void CPantallaManual::Show()
{
	CPantallaBase::Show();

	LabelTemperatura->Show();
	LeeDatosEstacion();
	Refresca();
}

void CPantallaManual::MuestraEstado()
{
	if(EstadoBoquillaAnterior==EstadoBoquilla)
		return;
	EstadoBoquillaAnterior=EstadoBoquilla;
	if (EstadoBoquilla == 1)
	{
		LabelEstado->SetColorFondo(COLOR::BLUE);
		LabelEstado->SetColorTexto(COLOR::BLACK);
		LabelEstado->SetTexto("Estado: ACTIVO");
	}
	else
	{
		LabelEstado->SetColorFondo(COLOR::RED);
		LabelEstado->SetColorTexto(COLOR::WHITE);
		LabelEstado->SetTexto("Estado: REPOSO");
	}
	LabelEstado->Show();
}

void CPantallaManual::LeeDatosEstacion()
{
	SetTemperatura = Estacion->GetTemperatura();
	Temperatura = Estacion->GetTemperaturaReal();
	NivelAire = Estacion->GetNivelAire();
	EstadoBoquilla=Estacion->GetEstado();
}


void CPantallaManual::MuestraTemperaturas()
{
	if(TemperaturaAnterior==Temperatura &&SetTemperaturaAnterior==SetTemperatura)
		return;
	TemperaturaAnterior=Temperatura;
	SetTemperaturaAnterior=SetTemperatura;
	LabelTemperaturas->SetTexto("%d/%d", Temperatura, SetTemperatura);
	LabelTemperaturas->Show();
}

void CPantallaManual::OnNivelAireEvent(int aire)
{
	NivelAire = aire;
	Estacion->SetNivelAire(NivelAire);
}

void CPantallaManual::MuestraNivelAire()
{
	if(NivelAireAnterior==NivelAire)
		return;
	NivelAireAnterior=NivelAire;
	LabelAire->SetTexto("Aire: %d", NivelAire);
	LabelAire->Show();

}

void CPantallaManual::OnTemperaturaRealEvent(int temperatura)
{
	Temperatura = temperatura;
}

void CPantallaManual::OnBotonDosClickEvent(int tiempoClick)
{
//    AdmiinstradorPantallasBase->ShowMenuPrincipal();
}

//eventos del Encoder
void CPantallaManual::OnPerillaIncremento()
{
	Estacion->IncrementaTemperatura();
}

void CPantallaManual::OnPerillaDecremento()
{
	Estacion->DecrementaTemperatura();
}

void CPantallaManual::OnBotonPerillaClickEvent(int tiempoClick)
{
}

void CPantallaManual::Refresca()
{
	LeeDatosEstacion();
	MuestraTemperaturas();
	MuestraEstado();
	MuestraNivelAire();
}
