/*
 * CPantallaEditorNombre.hpp
 *
 *  Created on: Jan 3, 2025
 *      Author: W10
 */

#ifndef INC_GUI_RAMPA_PANTALLAEDITORNOMBRE_CPANTALLAEDITORNOMBRE_HPP_
#define INC_GUI_RAMPA_PANTALLAEDITORNOMBRE_CPANTALLAEDITORNOMBRE_HPP_
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>
#include "ManejadorControles/CManejadorEventosControles.hpp"
#include <GUI/Menu/CMenuItem.hpp>
#include <GUI/Menu/CManejadorEventoMenu.hpp>

enum EDITOR_TECLAS
{
	TECLA_0,
	TECLA_1,
	TECLA_2,
	TECLA_3,
	TECLA_4,
	TECLA_5,
	TECLA_6,
	TECLA_7,
	TECLA_8,
	TECLA_9,
	TECLA_A,
	TECLA_E,
	TECLA_I,
	TECLA_O,
	TECLA_U,
	TECLA_B,
	TECLA_C,
	TECLA_D,
	TECLA_F,
	TECLA_G,
	TECLA_H,
	TECLA_J,
	TECLA_K,
	TECLA_L,
	TECLA_M,
	TECLA_N,
	TECLA_P,
	TECLA_Q,
	TECLA_R,
	TECLA_S,
	TECLA_T,
	TECLA_V,
	TECLA_W,
	TECLA_X,
	TECLA_Y,
	TECLA_Z,
	TECLA_DELETE,
	TECLA_ACEPTAR,
	TECLA_CANCELAR,
	TECLA_TABULADOR

};
class CPantallaEditorNombre: public CPantallaMenuBase//, CManejadorEventoMenu
{
private:
	CEtiquetaTft *LabelNombre;
	CEtiquetaTft *TextNombre;
	CMenuItem* Opciones;
	int const MAXTEXT=15;
	char Texto[16];
	int PosicionTexto=0;
	int ID_Rampa;
	void GuardaNombreRampa();
public:
	CPantallaEditorNombre(int id_Rampa);
	virtual ~CPantallaEditorNombre();
	virtual void Show();
	virtual void Refresca();
	virtual void OnMenuEvent(int identificador);
	void AsignaID(int id_Rampa);
	virtual void Seleccionada();
	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonTresClickEvent();
	virtual void OnBotonCuatroClickEvent();

};

#endif /* INC_GUI_RAMPA_PANTALLAEDITORNOMBRE_CPANTALLAEDITORNOMBRE_HPP_ */
