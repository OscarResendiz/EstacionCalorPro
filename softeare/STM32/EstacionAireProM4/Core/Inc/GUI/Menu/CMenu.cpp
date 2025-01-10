/*
 * CMenu.cpp
 *
 *  Created on: Sep 20, 2024
 *      Author: W10
 */

#include <GUI/Menu/CMenu.hpp>
#include "GUI/CRectanguloTft.hpp"

CMenu::CMenu(int xi, int yi, int ancho, int alto,int backColor, int contorno, int colorContorno):
	CRectanguloTft(xi,yi,ancho,alto,backColor,contorno,colorContorno)
{
	// TODO Auto-generated constructor stub
	Opciones=NULL;
	ItemInicial=NULL;
	ItemsXPagina=alto/(AnchoItem+5);
}

CMenu::~CMenu()
{
	// TODO Auto-generated destructor stub
}

void CMenu::Show()
{
//	int y;
	CRectanguloTft::Show();
	CMenuItem* tmp=ItemInicial;
	while(tmp!=NULL)
	{
//		y=tmp->DamePosicionY()+tmp->DameAltura();
		//Si cabe en altura, lo muestro
		if(SePuedeMostrar(tmp)==false)
		{
			return;
		}
		tmp->Show();
		tmp=tmp->DameSiguiente();
	}
}

void CMenu::AsignaColoresItems(int colorTexto, int colorFondo, int colorTextoResaltado, int solorFondoResaltado)
{
	ColorTexto=colorTexto;
	ColorFondo=colorFondo;
	ColoTextoSeleccionado=colorTextoResaltado;
	ColorFondoSeleccionado=solorFondoResaltado;
}

CMenuItem* CMenu::CreaItem(char* texto, int identificador,bool seleccionado)
{
	CEtiquetaTft* etiquetaTmp=new CEtiquetaTft(Xi, Yi, Ancho, AnchoItem, ColorFondo,texto, ColorTexto, 3, 0, ColorFondo);
	CMenuItem* tmp=new CMenuItem(etiquetaTmp,identificador,seleccionado);
	tmp->AsignaColores(ColorTexto, ColorFondo, ColoTextoSeleccionado, ColorFondoSeleccionado);
	return tmp;
}

void CMenu::AgregaItem(char* texto, int identificador,bool seleccionado)
{
	CMenuItem* tmp=CreaItem(texto,identificador,seleccionado);
	if(Opciones==NULL)
	{
		Opciones=tmp;
		Opciones->Selecciona(true);
		Seleccionado=Opciones;
		ItemInicial=Opciones;
		return;
	}
	Opciones->AgregaAlFinal(tmp);
	CalaculaPosicionItems(Opciones);
	CalculaPaginas();
}
void CMenu::CalaculaPosicionItems(CMenuItem* raiz)
{
	if(raiz==NULL)
		return;
	raiz->CalculaPosicionY(Yi+5);
}
bool CMenu::SePuedeMostrar(CMenuItem *item)
{
	int y=item->DamePosicionY()+item->DameAltura();
	//Si cabe en altura, lo muestro
	if(y> Yi+Alto)
		return false;
	return true;
}
void CMenu::OnSeleccionaSiguiente()
{
	if(Opciones==NULL)
		return;
	CMenuItem* tmp=Seleccionado;
	CMenuItem* siguiente;
	//me muevo hasta encontrar el que esta seleccionado
	while(tmp!=NULL)
	{
		if(tmp->EstaSeleccionado())
		{
			siguiente=tmp->DameSiguiente();
			if(siguiente==NULL)
				return;
			tmp->Selecciona(false);
			siguiente->Selecciona(true);
			Seleccionado=siguiente;
			if(SePuedeMostrar(siguiente))
			{
				tmp->Show();
				siguiente->Show();
				return;
			}
			else
			{
				//hago una paginacion hacia abajo
				CalaculaPosicionItems(siguiente);
				ItemInicial=siguiente;
				Show();
				return;
			}
		}
		tmp=tmp->DameSiguiente();
	}

}
void CMenu::OnSeleccionaAnterior()
{
	if(Opciones==NULL)
		return;
	CMenuItem* tmp=Seleccionado;
	CMenuItem* anterior;
	while(tmp!=NULL)
	{
		if(tmp->EstaSeleccionado())
		{
			anterior=tmp->DameAnterior();
			if(anterior==NULL)
				return;
			tmp->Selecciona(false);
			anterior->Selecciona(true);
			Seleccionado=anterior;
			if(EstaInicioPagina(tmp)==false)
			{
				tmp->Show();
				anterior->Show();
				return;
			}
			else
			{
				//hago una paginacion hacia arriba
				//regreso ItemsXPagina para calcular la pagina
				int itemsContados=ItemsXPagina;
				while(tmp!=NULL && itemsContados>0)
				{
					anterior=tmp->DameAnterior();
					itemsContados--;
					if(anterior==NULL)
						break;
					tmp=anterior;
				}
				CalaculaPosicionItems(tmp);
				ItemInicial=tmp;
				Show();
				return;
			}
		}
		tmp=tmp->DameAnterior();
	}

}
void CMenu::OnClickSeleccionado()
{
	if(Manejador==NULL)
		return;
	if(Seleccionado==NULL)
		return;
	Manejador->OnMenuEvent(Seleccionado->DameIdentificador());
}
void CMenu::CalculaPaginas()
{
	LimpiaPaginas();
	int conteoItems=0;
	int numeroPagina=0;
	Paginas[numeroPagina]=Opciones;
	CMenuItem* tmp=Opciones;
	while(tmp!=NULL)
	{
		if(conteoItems%ItemsXPagina==0)
		{
			Paginas[numeroPagina]=tmp;
			numeroPagina++;
		}
		conteoItems++;
		tmp=tmp->DameSiguiente();
	}
}

void CMenu::LimpiaPaginas()
{
	for(int i=0;i<MaximoPaginas;i++)
	{
		Paginas[i]=NULL;
	}
}

bool CMenu::EstaInicioPagina(CMenuItem* item)
{
	for(int i=0;i<MaximoPaginas;i++)
	{
		if(Paginas[i]==item)
			return true;
	}
	return false;

}
void CMenu::AsignaManejadorEventosMenu(CManejadorEventoMenu *manejador)
{
	Manejador=manejador;
}

void CMenu::AgregaItem(char* texto, int identificador,int x, int y,int ancho, int alto,bool seleccionado)
{
	CMenuItem* tmp=CreaItem(texto,identificador,Xi+x,Yi+y,ancho, alto,seleccionado);
	if(Opciones==NULL)
	{
		Opciones=tmp;
		Opciones->Selecciona(true);
		Seleccionado=Opciones;
		ItemInicial=Opciones;
		return;
	}
	Opciones->AgregaAlFinal(tmp);
}
CMenuItem* CMenu::CreaItem(char* texto, int identificador,int x, int y,int ancho, int alto,bool seleccionado)
{
	CEtiquetaTft* etiquetaTmp=new CEtiquetaTft(x, y, ancho, alto, ColorFondo,texto, ColorTexto, 3, 0, ColorFondo);
	CMenuItem* tmp=new CMenuItem(etiquetaTmp,identificador,seleccionado);
	tmp->AsignaColores(ColorTexto, ColorFondo, ColoTextoSeleccionado, ColorFondoSeleccionado);
	return tmp;
}
void CMenu::SetPosicion(int x, int y)
{
	Xi=x;
	Yi=y;
}
void CMenu::AgregaItem(char* texto, int identificador,int x, int y,int ancho, int alto,int colorFondo,int colorTexto,bool seleccionado)
{
	CMenuItem* tmp=CreaItem(texto,identificador,Xi+x,Yi+y,ancho, alto,colorFondo,colorTexto,seleccionado);
	if(Opciones==NULL)
	{
		Opciones=tmp;
		Opciones->Selecciona(true);
		Seleccionado=Opciones;
		ItemInicial=Opciones;
		return;
	}
	Opciones->AgregaAlFinal(tmp);

}
CMenuItem* CMenu::CreaItem(char* texto, int identificador,int x, int y,int ancho, int alto,int colorFondo,int colorTexto,bool seleccionado)
{
	CEtiquetaTft* etiquetaTmp=new CEtiquetaTft(x, y, ancho, alto, colorFondo,texto, colorTexto, 3, 0, ColorFondo);
	CMenuItem* tmp=new CMenuItem(etiquetaTmp,identificador,seleccionado);
	tmp->AsignaColores(colorTexto, colorFondo, ColoTextoSeleccionado, ColorFondoSeleccionado);
	return tmp;

}

void CMenu::BorrarItemns()
{

	CMenuItem *tmp=Opciones;
	CMenuItem *tmp2;
	while(tmp!=NULL)
	{
		tmp2=tmp->DameSiguiente();
		delete tmp;
		tmp=tmp2;
	}
	Opciones=NULL;
}
