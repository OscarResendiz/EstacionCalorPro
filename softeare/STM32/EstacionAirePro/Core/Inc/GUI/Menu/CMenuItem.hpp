/*
 * CMenuItem.hpp
 * representa una opcion del menu
 *  Created on: Sep 20, 2024
 *      Author: W10
 */

#ifndef INC_GUI_MENU_CMENUITEM_HPP_
#define INC_GUI_MENU_CMENUITEM_HPP_

#include <GUI/CEtiquetaTft.hpp>

class CMenuItem
{
private :
	CEtiquetaTft* Etiqueta;
	CMenuItem* Siguiente;
	CMenuItem* Anterior;
	int Identificador;
	int ColorTexto;
	int ColorFondo;
	int ColoTextoSeleccionado;
	int ColorFondoSeleccionado;
	bool Seleccionado;
public:
	CMenuItem(CEtiquetaTft* etiqueta,int identificador, bool seleccionado=0);
	virtual ~CMenuItem();
	void AgregaAlFinal(CMenuItem* siguiente);
	void Show();
	void AsignaColores(int colorTexto, int colorFondo, int colorTextoResaltado, int solorFondoResaltado);
	void Selecciona(bool valor);
	void CalculaPosicionY(int posicion);
	CMenuItem* DameSiguiente();
	CMenuItem* DameAnterior();
	int DamePosicionY();
	int DameAltura();
	bool EstaSeleccionado();
	void AsignaAnterior(CMenuItem* anterior);
	int DameIdentificador();

};

#endif /* INC_GUI_MENU_CMENUITEM_HPP_ */
