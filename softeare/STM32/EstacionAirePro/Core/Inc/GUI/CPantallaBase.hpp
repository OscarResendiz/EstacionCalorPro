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

//clase que sirve como base para las demas pantallas del sistema
class CPantallaBase: public CRectanguloTft
{
protected:
//  CAdmiinstradorPantallasBase *AdmiinstradorPantallasBase;
	CEtiquetaTft *LabelTitulo;
	int VerTitulo = 1;
	char Titulo[100];
public:
	virtual ~CPantallaBase();
	//constructor
	CPantallaBase(int verTitulo = 1, char *titulo = "");
	//funcion que se tiene que reemplazar para verse
	virtual void Show();
	virtual void Refresca();
};

#endif /* INC_GUI_CPANTALLABASE_HPP_ */
