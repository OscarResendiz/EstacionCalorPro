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
#include "ManejadorControles/CManejadorEventosControles.hpp"
#include <ManejadorControles/CManejadorControles.hpp>

//clase que sirve como base para las demas pantallas del sistema
class CPantallaBase: public CRectanguloTft, public CManejadorEventosControles
{
private:
	bool Visible=false;
protected:
	CEtiquetaTft *LabelTitulo;
	int VerTitulo = 1;
	char Titulo[100];
	CEstacionBase *Estacion;
	CManejadorControles *ManejadorControles;

public:
	virtual ~CPantallaBase();
	//constructor
	CPantallaBase(int verTitulo = 1, char *titulo = (char *)"");
	//funcion que se tiene que reemplazar para verse
	virtual void Show();
	virtual void Refresca();
	virtual void SetEstacion(CEstacionBase *estacion);
	virtual void SetManejadorControles(CManejadorControles *manejador);
	virtual void Ocultar();
	virtual bool EsVisible();
	virtual void SetVisible(bool visible=true);
	virtual void SetTituloPantalla(char *texto);
	virtual void Seleccionada();
};

#endif /* INC_GUI_CPANTALLABASE_HPP_ */
