/*
 * CPantallaMenuBase.hpp
 *
 *  Created on: Oct 30, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAMENUBASE_CPANTALLAMENUBASE_HPP_
#define INC_GUI_PANTALLAMENUBASE_CPANTALLAMENUBASE_HPP_
#include "GUI/CPantallaBase.hpp"
#include <GUI/Menu/CManejadorEventoMenu.hpp>
#include "GUI/Menu/CMenuItem.hpp"
#include "GUI/Menu/CMenu.hpp"

class CPantallaMenuBase:public CPantallaBase, CManejadorEventoMenu
{
protected:
	CMenu* Menu;

public:
	CPantallaMenuBase(char *titulo);
	virtual ~CPantallaMenuBase();
	void AgregaMenuItem(char *texto, int Opcion);
	virtual void AgregaMenuItem(char *texto, int Opcion, int x, int y, int ancho,int alto);
	virtual void AgregaMenuItem(char *texto, int Opcion, int x, int y, int ancho,int alto,int colorFondo, int colorTexto);
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	virtual void OnBotonPerillaClickEvent();
	virtual void Show();
	virtual void Refresca();
	virtual void BorraMenu();
};

#endif /* INC_GUI_PANTALLAMENUBASE_CPANTALLAMENUBASE_HPP_ */
