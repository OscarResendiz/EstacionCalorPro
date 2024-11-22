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
#include <GUI/PantallaMemoria/CPantallaMemoria.hpp>
#include <GUI/PantallaCalibracion/CPantallaCalibracion.hpp>
#include <GUI/PantallaMenuRampa/CPantallaMenuRampa.hpp>
#include <GUI/PantallaRampa/CPantallaRampa.hpp>
#include <GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.hpp>

class CManejadorPantallas
{
private:
	CEstacionBase* Estacion=nullptr;
	//pantallas
	CPantallaBase* PantallaPendinteCambiar=nullptr;
	CPantallaBase* PantallaActual=nullptr;
	CPantallaBase* PantallaAnterior=nullptr;
	CPantallaManual *pantallaManual=nullptr;
	CMenuPrincipal* menuPrincipal=nullptr;
	CPantallaMenuRampa* menuRampa=nullptr;
	CManejadorControles *ManejadorControles;
	CConfigurarPantallaMemoria *ConfigurarPantallaMemoria;
	CPantallaMemoria *PantallaMemoria;
	CPantallaCalibracion *PantallaCalibracion;
	CPantallaRampa *PantallaRampa;
	CPantallaInicializaMemoria *PantallaInicializaMemoria;

	bool CambioPantalla=false;

	void AsignaPantallaActual(CPantallaBase* pantalla);
	void CambiaPantalla();
public:
	CManejadorPantallas();
	virtual ~CManejadorPantallas();
	void MuestraPantallaManual();
	void MuestraMenuPrincipal();
	void SetEstacion(CEstacionBase* estacion);
	void SetManejadorControles(CManejadorControles* manejador);
	void RefrescaPantalla();
	void MuestraPantallaConfiguracionMemoria(int meoria);
	void MuestraPantallaMemoria(int memoria);
	void MuestraPantallaAnterior();
	void MuestraCPantallaCalibracion();
	void MuestraMenuRampa();
	void MuestraPantallaRampa(int nrampa);
	void MuestraPantallaInicializaMemoria();
};
extern CManejadorPantallas ManejadorPantallas;
#endif /* INC_GUI_MANEJADORPANTALLAS_H_ */
