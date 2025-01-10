/*
 * CPantallaPaso.hpp
 *
 *  Created on: Jan 9, 2025
 *      Author: W10
 */

#ifndef INC_GUI_RAMPA_PANTALLAPASO_CPANTALLAPASO_HPP_
#define INC_GUI_RAMPA_PANTALLAPASO_CPANTALLAPASO_HPP_
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>

enum MENU_PANTALLA_PASO
{
	PANTALLA_PASO_MODIFICAR,
	PANTALLA_PASO_ELIMINAR,
	PANTALLA_PASO_SALIR
};

class CPantallaPaso:public CPantallaMenuBase
{
private:
	int ID_Paso;
	int ID_Rampa;
public:
	CPantallaPaso();
	virtual ~CPantallaPaso();
	void SetIdPaso(int id_rampa,int id_Paso);
	virtual void OnMenuEvent(int identificador);
};

#endif /* INC_GUI_RAMPA_PANTALLAPASO_CPANTALLAPASO_HPP_ */
