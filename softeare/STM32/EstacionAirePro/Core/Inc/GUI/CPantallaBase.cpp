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
	VerTitulo = verTitulo;
	strcpy(Titulo, titulo);
	setRotation(3);  //ROTACION::HORIZONTAL); //en horizontal
	int ancho = width();
	int alto = height();
	Redimenciona(ancho, alto);
	LabelTitulo = new CEtiquetaTft( Xi, Yi, ancho, 30, COLOR::BLUE, Titulo,	COLOR::WHITE, 3, 0, COLOR::BLUE);
}
//funcion que se tiene que reemplazar para verse
void CPantallaBase::Show()
{
	//dibujo el fondo
	CRectanguloTft::Show();
	//dibujo el titulo
	LabelTitulo->Show();
}
