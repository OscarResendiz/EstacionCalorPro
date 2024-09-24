/*
 * CPantallaBase.hpp
 *
 *  Created on: Jul 24, 2024
 *      Author: W10
 */

#ifndef INC_GUI_CPANTALLABASE_HPP_
#define INC_GUI_CPANTALLABASE_HPP_
#include "GUI/CRectanguloTft.hpp"
#include "GUI/CEtiquetaTft.hpp"
#include "Estaciones/CEstacionBase.hpp"

//clase que sirve como base para las demas pantallas del sistema
class CPantallaBase: public CRectanguloTft,CManejadorControlesBase
{
private:
	bool Visible=false;
protected:
//  CAdmiinstradorPantallasBase *AdmiinstradorPantallasBase;
	CEtiquetaTft *LabelTitulo;
	int VerTitulo = 1;
	char Titulo[100];
	CEstacionBase *Estacion;

public:
	virtual ~CPantallaBase();
	//constructor
	CPantallaBase(int verTitulo = 1, char *titulo = "");
	//funcion que se tiene que reemplazar para verse
	virtual void Show();
	virtual void Refresca();
	virtual void SetEstacion(CEstacionBase *estacion);
	virtual void Ocultar();
	virtual bool EsVisible();
	virtual void SetVisible(bool visible=true);
};

#endif /* INC_GUI_CPANTALLABASE_HPP_ */
