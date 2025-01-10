/*
 * CPantallaEdicionPaso.cpp
 *
 *  Created on: Jan 8, 2025
 *      Author: W10
 */

#include <GUI/Rampa/PantallaEdicionPaso/CPantallaEdicionPaso.hpp>
#include <RapaTemperatura/CControladorRampas.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include <RapaTemperatura/CControladorPasosRampa.hpp>

CPantallaEdicionPaso::CPantallaEdicionPaso():
CPantallaBase(1, (char*)"EDITOR PASO")
{
	// TODO Auto-generated constructor stub
	// TODO Auto-generated constructor stub
	LabelRampa=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"Memoria: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	// temperatra
	LabelTemperatura = new CEtiquetaTft( 5, 65, 50, 20, COLOR::BLACK,(char*)"Temp", COLOR::WHITE, 3, 0, COLOR::WHITE);
	TextTemperatura = new CEtiquetaTft( 100, 65, 150, 30,COLOR::GREEN, (char*)"000/000", COLOR::BLACK, 3, 1, COLOR::RED);
//	TextTemperatura->SetSeparacion(5, 5);
	//nivel de ire
	LabelAire = new CEtiquetaTft( 5, 100, 200, 30, COLOR::BLACK,(char*) "Aire",COLOR::WHITE, 3, 0, COLOR::RED);
	TextAire = new CEtiquetaTft( 100, 100, 150, 30, COLOR::GREY,(char*) "00",COLOR::BLACK, 3, 0, COLOR::RED);
	// Tiempo
	LabelTiempo = new CEtiquetaTft( 5, 135, 200, 30, COLOR::BLACK,(char*) "Segs",COLOR::WHITE, 3, 0, COLOR::RED);
	TextTiempo = new CEtiquetaTft( 100, 135, 150, 30, COLOR::GREY,(char*) "00",COLOR::BLACK, 3, 0, COLOR::RED);

	LabelGuardar=new CEtiquetaTft( 10, 200, 130, 30, COLOR::GREEN,(char*)"GUARDAR", COLOR::BLACK, 3, 1, COLOR::WHITE);
	LabelCancelar=new CEtiquetaTft( 160, 200, 145, 30, COLOR::RED,(char*)"CANCELAR", COLOR::BLACK, 3, 1, COLOR::WHITE);

	Textos[0]=TextTemperatura;
	Textos[1]=TextAire;
	Textos[2]=TextTiempo;
	Seleccionado=0;
	Estado=ESTADO_EDICION_PASO::SELECIONANDO;
}

CPantallaEdicionPaso::~CPantallaEdicionPaso()
{
	// TODO Auto-generated destructor stub
}
void CPantallaEdicionPaso::SetIdPaso(int id_rampa, int id_paso)
{
	ID_Paso=id_paso;
	ID_Rampa=id_rampa;
	Temperatura=100;
	NivelAire=50;
	Segundos=10;
	CRampa rampa=	ControladorRampas.DameRampa(ID_Rampa);
	LabelRampa->SetTexto((char*)"Rampa:%s",rampa.Nombre);
	if(id_paso!=-1)
	{
		CPaso paso=ControladorPasosRampa.DamePasoRampa(ID_Paso);
		Temperatura=paso.Temperatura;
		NivelAire=paso.NivelAire;
		Segundos=paso.Segundos;
	}
}
void CPantallaEdicionPaso::OnPerillaIncremento()
{
	if(Estado==ESTADO_EDICION_PASO::SELECIONANDO)
		NavegarIncremento();
	else
		ValorIncremento();

}
void CPantallaEdicionPaso::OnPerillaDecremento()
{
	if(Estado==ESTADO_EDICION_PASO::SELECIONANDO)
		NavegarDecremento();
	else
		ValorDecremento();
}
void CPantallaEdicionPaso::OnBotonUnoClickEvent()
{
	if(ID_Paso<=0)
	{
		ControladorPasosRampa.AgregarPasoRampa(ID_Rampa, Temperatura, NivelAire, Segundos);
		ManejadorPantallas.AsignaPantallaPasosRampa(ID_Rampa);
	}
	else
	{
		ControladorPasosRampa.ActualizaPasoRampa(ID_Paso, ID_Rampa, Temperatura, NivelAire, Segundos);
		ManejadorPantallas.MuestraPantallaPaso(ID_Rampa, ID_Paso);
	}

}

void CPantallaEdicionPaso::OnBotonTresClickEvent()
{
	if(ID_Paso<=0)
		ManejadorPantallas.AsignaPantallaPasosRampa(ID_Rampa);
	else
		ManejadorPantallas.MuestraPantallaPaso(ID_Rampa, ID_Paso);
}
void CPantallaEdicionPaso::Show()
{
	//VelocidadAireInicialPotenciometro=ManejadorControles->GetNivelAire();
	CPantallaBase::Show();

	LabelTemperatura->Show();
	MuestraTemperatura();

	LabelAire->Show();
	MuestraAire();

	LabelTiempo->Show();
	MuestraTiempo();

	LabelRampa->Show();
	LabelGuardar->Show();
	LabelCancelar->Show();
}
void CPantallaEdicionPaso::NavegarIncremento()
{

	Textos[Seleccionado]->SetBackColor(COLOR::GREY);
	Textos[Seleccionado]->Show();
	Seleccionado++;
	if(Seleccionado>2)
		Seleccionado=0;
	Textos[Seleccionado]->SetBackColor(COLOR::GREEN);
	Textos[Seleccionado]->Show();
}
void CPantallaEdicionPaso::NavegarDecremento()
{
	Textos[Seleccionado]->SetBackColor(COLOR::GREY);
	Textos[Seleccionado]->Show();
	Seleccionado--;
	if(Seleccionado<0)
		Seleccionado=2;
	Textos[Seleccionado]->SetBackColor(COLOR::GREEN);
	Textos[Seleccionado]->Show();

}
void CPantallaEdicionPaso::OnBotonPerillaClickEvent()
{
	if(Estado==ESTADO_EDICION_PASO::SELECIONANDO)
	{
		Estado=ESTADO_EDICION_PASO::EDITANDO;
		Textos[Seleccionado]->SetBackColor(COLOR::WHITE);
		Textos[Seleccionado]->Show();
	}
	else
	{
		Estado=ESTADO_EDICION_PASO::SELECIONANDO;
		Textos[Seleccionado]->SetBackColor(COLOR::GREEN);
		Textos[Seleccionado]->Show();
	}
}
void CPantallaEdicionPaso::ValorIncremento()
{
	switch(Seleccionado)
	{
	case 0:
		Temperatura++;
		if(Temperatura>500)
			Temperatura=500;
		MuestraTemperatura();
		break;
	case 1:
		NivelAire++;
		if(NivelAire>100)
			NivelAire=100;
		MuestraAire();
		break;
	case 2:
		Segundos++;
		if(Segundos>600)
			Segundos=600;
		MuestraTiempo();
		break;
	}
}
void CPantallaEdicionPaso::ValorDecremento()
{
	switch(Seleccionado)
	{
	case 0:
		Temperatura--;
		if(Temperatura<0)
			Temperatura=0;
		MuestraTemperatura();
		break;
	case 1:
		NivelAire--;
		if(NivelAire<0)
			NivelAire=0;
		MuestraAire();
		break;
	case 2:
		Segundos--;
		if(Segundos<0)
			Segundos=0;
		MuestraTiempo();
		break;
	}

}

void CPantallaEdicionPaso::MuestraTemperatura()
{
	TextTemperatura->SetTexto((char*)"%d", Temperatura);
	TextTemperatura->Show();
}
void CPantallaEdicionPaso::MuestraAire()
{
	TextAire->SetTexto((char*)"%d", NivelAire);
	TextAire->Show();
}
void CPantallaEdicionPaso::MuestraTiempo()
{
	TextTiempo->SetTexto((char*)"%d", Segundos);
	TextTiempo->Show();
}
