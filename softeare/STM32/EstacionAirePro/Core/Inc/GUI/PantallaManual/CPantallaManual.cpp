/*
 * CPantallaManual.cpp
 *
 *  Created on: Jul 25, 2024
 *      Author: W10
 */

#include <GUI/PantallaManual/CPantallaManual.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>

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

	LabelPID=new CEtiquetaTft( 5, 180, 200, 30, COLOR::BLACK, "PID: 00",COLOR::WHITE, 3, 0, COLOR::RED);
}

/*void CPantallaManual::SetEstacion(CEstacionBase *estacion)
{
	Estacion = estacion;
	//asigno los evetos de la estacion
	Estacion->SetManejadorControles(this);
	Estacion->ActivarCalefactor();
}
*/

void CPantallaManual::MuestraEstado(bool forzar)
{
	if(forzar==false)
	{
		if(EstadoBoquillaAnterior==EstadoBoquilla )
		{
			if(EsVisible()==true)
			{
				return;
			}
		}
	}
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


void CPantallaManual::MuestraTemperaturas(bool forzar)
{
	if(forzar==false)
	{
		if(TemperaturaAnterior==Temperatura &&SetTemperaturaAnterior==SetTemperatura && EsVisible()==true )
			return;
	}
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

void CPantallaManual::MuestraNivelAire(bool forzar)
{
	if(forzar==false)
	{
		if(NivelAireAnterior==NivelAire && EsVisible()==true )
			return;
	}
	NivelAireAnterior=NivelAire;
	LabelAire->SetTexto("Aire: %d", NivelAire);
	LabelAire->Show();

}

void CPantallaManual::OnTemperaturaRealEvent(int temperatura)
{
	Temperatura = temperatura;
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


void CPantallaManual::Refresca()
{
	MuestraInformacion(false);
}
 void CPantallaManual::OnBotonUnoClickEvent(int tiempoClick)
{
	int pid=Estacion->GetPID();
	pid++;
	Estacion->SetPID(pid);
}
 void CPantallaManual::OnBotonDosClickEvent(int tiempoClick)
{
		int pid=Estacion->GetPID();
		pid--;
		Estacion->SetPID(pid);

}
 void CPantallaManual::OnBotonPerillaClickEvent(int tiempoClick)
 {
	 ManejadorPantallas.MuestraMenuPrincipal();
 }
 void CPantallaManual::Show()
 {
 	CPantallaBase::Show();

 	LabelTemperatura->Show();
 	LeeDatosEstacion();
 	MuestraInformacion(true);
 }
 void CPantallaManual::MuestraInformacion(bool forzar)
 {
		LeeDatosEstacion();
		MuestraTemperaturas(forzar);
		MuestraEstado(forzar);
		MuestraNivelAire(forzar);
		//muestro el PID
		int pid=Estacion->GetPID();
		if(pid==0 && forzar==false)
			return;
		if(pidAnteriro!=pid || forzar==true)
		{
			pidAnteriro=pid;
			LabelPID->SetTexto("PID: %d", pid);
			LabelPID->Show();
		}
		//marco como visible
		SetVisible(true);

 }
