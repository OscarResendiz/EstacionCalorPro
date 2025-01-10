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
#include <GUI/Rampa/PantallaMenuRampa/CPantallaMenuRampa.hpp>
#include <GUI/Rampa/PantallaRampa/CPantallaRampa.hpp>
#include <GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.hpp>
#include <GUI/Rampa/PantallaEditorNombre/CPantallaEditorNombre.hpp>
#include <GUI/Rampa/PantallaPasosRampa/CPantallaPasosRampa.hpp>
#include <GUI/Rampa/PantallaEliminarRampa/CPantallaEliminarRampa.hpp>
#include <GUI/Rampa/PantallaEdicionPaso/CPantallaEdicionPaso.hpp>
#include <GUI/Rampa/PantallaPaso/CPantallaPaso.hpp>
#include <GUI/Rampa/PantallaEliminarPaso/CPantallaEliminarPaso.hpp>
#include <GUI/Rampa/PantallaEjecucionRampa/CPantallaEjecucionRampa.hpp>

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
	CPantallaEditorNombre *PantallaEditorNombre;
	CPantallaPasosRampa *PantallaPasosRampa;
	CPantallaEliminarRampa *PantallaEliminarRampa;
	CPantallaEdicionPaso *PantallaEdicionPaso;
	CPantallaPaso *PantallaPaso;
	CPantallaEliminarPaso *PantallaEliminarPaso;
	CPantallaEjecucionRampa *PantallaEjecucionRampa;
	bool CambioPantalla=false;
	void AsignaPantallaActual(CPantallaBase* pantalla);
	void CambiaPantalla();
	char Nombre[100];
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
	void MuestraPantallaEditorNombre(int id_Rampa);
	void AsignaPantallaPasosRampa(int id_rampa);
	void MuestraPantallaEliminarRampa(int id_rampa);
	void MuestraPantallaEdicionPaso(int id_rampa,int id_paso);
	void MuestraPantallaPaso(int id_rampa,int id_paso);
	void MuestraPantallaEliminarPaso(int id_rampa,int id_paso);
	void MuestraPantallaEjecucionRampa(int id_rampa);
};
extern CManejadorPantallas ManejadorPantallas;
#endif /* INC_GUI_MANEJADORPANTALLAS_H_ */
