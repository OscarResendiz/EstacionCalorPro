/*
 * CPantallaMenuBase.cpp
 *
 *  Created on: Oct 30, 2024
 *      Author: W10
 */

#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>

CPantallaMenuBase::CPantallaMenuBase(char *titulo):
	CPantallaBase(1,titulo)

{
	// TODO Auto-generated constructor stub
	Menu=new CMenu(4,30,310, 210,COLOR::WHITE,1, COLOR::RED);
	Menu->AsignaManejadorEventosMenu(this);
	Menu->AsignaColoresItems(COLOR::BLACK, 0X776F, COLOR::WHITE, COLOR::BLACK);

}

CPantallaMenuBase::~CPantallaMenuBase()
{
	// TODO Auto-generated destructor stub
}

void CPantallaMenuBase::AgregaMenuItem(char *texto, int Opcion)
{
	Menu->AgregaItem(texto, Opcion);
}
void CPantallaMenuBase::OnPerillaIncremento()
{
	Menu->OnSeleccionaSiguiente();
}
void CPantallaMenuBase::OnPerillaDecremento()
{
	Menu->OnSeleccionaAnterior();
}
void CPantallaMenuBase::OnBotonPerillaClickEvent()
{
	Menu->OnClickSeleccionado();
}
void CPantallaMenuBase::Show()
{
	CPantallaBase::Show();
	Menu->Show();
	SetVisible(true);
}
void CPantallaMenuBase::Refresca()
{
	if(EsVisible()==false)
		Show();
}

