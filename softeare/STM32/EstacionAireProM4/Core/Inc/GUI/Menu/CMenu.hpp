/*
 * CMenu.hpp
 * clase que representa un menu con opciones seleccionables
 *  Created on: Sep 20, 2024
 *      Author: W10
 */

#ifndef INC_GUI_MENU_CMENU_HPP_
#define INC_GUI_MENU_CMENU_HPP_
#include "GUI/CRectanguloTft.hpp"
#include "GUI/Menu/CMenuItem.hpp"
#include <GUI/Menu/CManejadorEventoMenu.hpp>


#define MaximoPaginas 10
class CMenu: public CRectanguloTft
{
private:
	CMenuItem* Opciones;
	CMenuItem* ItemInicial;
	CMenuItem* Seleccionado;
	int ColorTexto;
	int ColorFondo;
	int ColoTextoSeleccionado;
	int ColorFondoSeleccionado;
	int ItemsXPagina;
	int AnchoItem=25;
	CMenuItem* Paginas[MaximoPaginas]; //se va a manejar un maximo de 10 paginas
	CManejadorEventoMenu* Manejador;

	CMenuItem* CreaItem(char* texto, int identificador,bool seleccionado);
	CMenuItem* CreaItem(char* texto, int identificador,int x, int y,int ancho, int alto,bool seleccionado);
	CMenuItem* CreaItem(char* texto, int identificador,int x, int y,int ancho, int alto,int colorFondo,int colorTexto,bool seleccionado);
	void CalaculaPosicionItems(CMenuItem* raiz);
	void CalculaPaginas();
	void LimpiaPaginas();
	bool EstaInicioPagina(CMenuItem* item);

public:
	CMenu(int xi = 0, int yi = 0, int ancho = 0, int alto = 0,	int backColor = COLOR::BLACK, int contorno = 0, int colorContorno =	COLOR::WHITE);
	virtual ~CMenu();
	void Show();
	void AsignaColoresItems(int colorTexto, int colorFondo, int colorTextoResaltado, int solorFondoResaltado);
	void AgregaItem(char* texto, int identificador,bool seleccionado=false);
	void AgregaItem(char* texto, int identificador,int x, int y,int ancho, int alto,bool seleccionado=false);
	void AgregaItem(char* texto, int identificador,int x, int y,int ancho, int alto,int colorFondo,int colorTexto,bool seleccionado=false);
	void OnSeleccionaSiguiente();
	void OnSeleccionaAnterior();
	void OnClickSeleccionado();
	bool SePuedeMostrar(CMenuItem *item);
	void AsignaManejadorEventosMenu(CManejadorEventoMenu *manejador);
	void SetPosicion(int x, int y);
	void BorrarItemns();
};

#endif /* INC_GUI_MENU_CMENU_HPP_ */
