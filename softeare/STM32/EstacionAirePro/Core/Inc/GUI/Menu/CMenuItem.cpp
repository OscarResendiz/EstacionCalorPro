/*
 * CMenuItem.cpp
 *
 *  Created on: Sep 20, 2024
 *      Author: W10
 */

#include <GUI/Menu/CMenuItem.hpp>

CMenuItem::CMenuItem(CEtiquetaTft* etiqueta,int identificador,bool seleccionado)
{
	// TODO Auto-generated constructor stub
	Etiqueta=etiqueta;
	Siguiente=NULL;
	Anterior=NULL;
	Identificador=identificador;
	Seleccionado=seleccionado;
}

CMenuItem::~CMenuItem()
{
	// TODO Auto-generated destructor stub
}

void CMenuItem::AgregaAlFinal(CMenuItem* siguiente)
{
	if(Siguiente==NULL)
	{
		Siguiente=siguiente;
		siguiente->Anterior=this;
		return;
	}
	Siguiente->AgregaAlFinal(siguiente);
}

void CMenuItem::Show()
{
	if(Seleccionado)
	{
		Etiqueta->SetColorTexto(ColoTextoSeleccionado);
		Etiqueta->SetBackColor(ColorFondoSeleccionado);
	}
	else
	{
		Etiqueta->SetColorTexto(ColorTexto);
		Etiqueta->SetBackColor(ColorFondo);
	}
	Etiqueta->Show();
}
void CMenuItem::AsignaColores(int colorTexto, int colorFondo, int colorTextoResaltado, int solorFondoResaltado)
{
	ColorTexto=colorTexto;
	ColorFondo=colorFondo;
	ColoTextoSeleccionado=colorTextoResaltado;
	ColorFondoSeleccionado=solorFondoResaltado;
}
void CMenuItem::Selecciona(bool valor)
{
	Seleccionado=valor;
}

void CMenuItem::CalculaPosicionY(int posicion)
{
	int x=Etiqueta->DamePosicionX();
	Etiqueta->CambiaPosicion(x, posicion);
	if(Siguiente==NULL)
		return;
	int y=Etiqueta->DameAlto()+posicion+5;
	Siguiente->CalculaPosicionY(y);
}
CMenuItem* CMenuItem::DameSiguiente()
{
	return Siguiente;
}
int CMenuItem::DamePosicionY()
{
	return Etiqueta->DamePosicionY();
}
int CMenuItem::DameAltura()
{
	return Etiqueta->DameAlto();
}
bool CMenuItem::EstaSeleccionado()
{
	return Seleccionado;
}
CMenuItem* CMenuItem::DameAnterior()
{
	return Anterior;
}

void CMenuItem::AsignaAnterior(CMenuItem* anterior)
{
	Anterior=anterior;
}
int CMenuItem::DameIdentificador()
{
	return Identificador;
}
