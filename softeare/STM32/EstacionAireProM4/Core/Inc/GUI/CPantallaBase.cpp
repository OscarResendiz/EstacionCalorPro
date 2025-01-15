/*
 * CPantallaBase.cpp
 *
 *  Created on: Jul 24, 2024
 *      Author: W10
 */

#include <GUI/CPantallaBase.hpp>

CPantallaBase::~CPantallaBase()
{
	// TODO Auto-generated destructor stub
}

//constructor
CPantallaBase::CPantallaBase(int verTitulo, char *titulo) :
		CRectanguloTft(0, 0, 0, 0, COLOR::BLACK, 1, COLOR::BLUE)
{
	Visible=false;
	VerTitulo = verTitulo;
	strcpy(Titulo, titulo);
	setRotation(3);
	int ancho = width();
	int alto = height();
	Redimenciona(ancho, alto);
	LabelTitulo = new CEtiquetaTft( Xi, Yi, ancho, 30, COLOR::BLUE, Titulo,	COLOR::WHITE, 3, 0, COLOR::BLUE);
}
//funcion que se tiene que reemplazar para verse
void CPantallaBase::Show()
{
	//dibujo el fondo
//	CRectanguloTft::Show();
	//dibujo el titulo
	LabelTitulo->Show();
}
void CPantallaBase::Refresca()
{
}
void CPantallaBase::SetEstacion(CEstacionBase *estacion)
{
	Estacion = estacion;
	//asigno los evetos de la estacion
	Estacion->SetManejadorControles(this);
	Estacion->DesactivarCalefactor();
}
void CPantallaBase::Ocultar()
{
	CRectanguloTft::Show();
	Estacion->QuitaManejadorControles();
	Visible=false;
}
bool CPantallaBase::EsVisible()
{
	return Visible;
}
void CPantallaBase::SetVisible(bool visible)
{
	if(Visible==visible)
		return;
	Visible=visible;
}

void CPantallaBase::SetManejadorControles(CManejadorControles *manejador)
{
	ManejadorControles=manejador;
	if(ManejadorControles==NULL)
		return;
	ManejadorControles->SetManejadorControles(this);
}
void CPantallaBase::SetTituloPantalla(char *texto)
{
	strcpy(Titulo, texto);
	LabelTitulo->SetTexto(texto);

}
void CPantallaBase::Seleccionada()
{

}
