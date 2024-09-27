/*
 * ManejadorPantallas.h
 * clase que se encarga de controlar el manejo de las pantallas
 *  Created on: Sep 19, 2024
 *      Author: W10
 */

#ifndef INC_GUI_MANEJADORPANTALLAS_HPP_
#define INC_GUI_MANEJADORPANTALLAS_HPP_
#include<stdio.h>
#include "GUI/PantallaManual/CPantallaManual.hpp"
#include <GUI/PantallaMenuPrincipal/CMenuPrincipal.h>
#include "Estaciones/CEstacionBase.hpp"
#include <ManejadorControles/CManejadorControles.hpp>
#include <GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.hpp>

class CManejadorPantallas
{
private:
	CEstacionBase* Estacion=nullptr;
	//pantallas
	CPantallaBase* PantallaActual=nullptr;
	CPantallaManual *pantallaManual=nullptr;
	CMenuPrincipal* menuPrincipal=nullptr;
	CManejadorControles *ManejadorControles;
	CConfigurarPantallaMemoria *ConfigurarPantallaMemoria;
	bool CambioPantalla;

	void AsignaPantallaActual(CPantallaBase* pantalla);
public:
	CManejadorPantallas();
	virtual ~CManejadorPantallas();
//	 CManejadorPantallas* DameControlador();
	void MuestraPantallaManual();
	void MuestraMenuPrincipal();
	void SetEstacion(CEstacionBase* estacion);
	void SetManejadorControles(CManejadorControles* manejador);
	void RefrescaPantalla();
	void MuestraPantallaConfiguracionMemoria(int meoria);
};
extern CManejadorPantallas ManejadorPantallas;
#endif /* INC_GUI_MANEJADORPANTALLAS_H_ */
