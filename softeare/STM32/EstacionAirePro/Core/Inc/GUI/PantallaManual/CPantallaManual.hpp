/*
 * CPantallaManual.hpp
 *
 *  Created on: Jul 25, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAMANUAL_CPANTALLAMANUAL_HPP_
#define INC_GUI_PANTALLAMANUAL_CPANTALLAMANUAL_HPP_
#include "GUI/CPantallaBase.hpp"
#include "ManejadorControles/CManejadorControlesBase.hpp"
#include "Estaciones/CEstacionBase.hpp"

class CPantallaManual: public CPantallaBase, CManejadorControlesBase
{
private:
  int SetTemperatura = 0;
  int Temperatura = 0;
  int NivelAire = 0;
  int EstadoBoquilla = 0;
  CEstacionBase *Estacion;
  CEtiquetaTft *LabelTemperatura;
  CEtiquetaTft *LabelTemperaturas;
  CEtiquetaTft *LabelAire;
  CEtiquetaTft *LabelEstado;

public:
  CPantallaManual(CEstacionBase *estacion);
	virtual ~CPantallaManual();
	  CPantallaManual();
	  virtual void SetEstacion(CEstacionBase *estacion);
	  virtual void Show();

	private:
	  void MuestraEstado();
	  void LeeDatosEstacion() ;
	  virtual void OnTemperaturaEvent(int temperatura);
	  void MuestraTemperaturas() ;
	  void OnNivelAireEvent(int aire);
	  virtual void OnTemperaturaRealEvent(int temperatura);
	  virtual void OnBotonDosClickEvent(int tiempoClick);

	  //eventos del Encoder
	  virtual void OnPerillaIncremento() ;
	  virtual void OnPerillaDecremento() ;
	  virtual void OnBotonPerillaClickEvent(int tiempoClick);
};

#endif /* INC_GUI_PANTALLAMANUAL_CPANTALLAMANUAL_HPP_ */
