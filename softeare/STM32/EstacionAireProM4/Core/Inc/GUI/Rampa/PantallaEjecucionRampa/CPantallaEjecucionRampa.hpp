/*
 * CPantallaEjecucionRampa.hpp
 *
 *  Created on: Jan 10, 2025
 *      Author: W10
 */

#ifndef INC_GUI_RAMPA_PANTALLAEJECUCIONRAMPA_CPANTALLAEJECUCIONRAMPA_HPP_
#define INC_GUI_RAMPA_PANTALLAEJECUCIONRAMPA_CPANTALLAEJECUCIONRAMPA_HPP_
#include "GUI/CPantallaBase.hpp"
#include <RapaTemperatura/CControladorPasosRampa.hpp>

class CPantallaEjecucionRampa: public CPantallaBase
{
private:
	int ID_Rampa;
	int NPasos;
	int Pasos[100];
	int PasoActual;
	bool Ejecutando;
	int64_t TiempoMilis;
	int UltimoMili;
	char TextoTiempo[100];
	int16_t Segundos;

	CPaso Paso;

	CEtiquetaTft *LabelGuardar;
	CEtiquetaTft *LabelCancelar;
	CEtiquetaTft *LabelPaso;
	CEtiquetaTft *LabelTemperatura;
	CEtiquetaTft *LabelAire;
	CEtiquetaTft *LabelTiempo;
	void SegundosATexto(int tiempoSegundos);
	void FinEjecucion();
	void PasoTerminado();
	void MuestraDatos();
	void ActualizaEstacion();
public:
	CPantallaEjecucionRampa();
	virtual ~CPantallaEjecucionRampa();
	void SetIDRampa(int id_rampa);
	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonTresClickEvent();
	virtual void Refresca();
	virtual void Show();
	virtual void SetEstacion(CEstacionBase *estacion);
};

#endif /* INC_GUI_RAMPA_PANTALLAEJECUCIONRAMPA_CPANTALLAEJECUCIONRAMPA_HPP_ */
