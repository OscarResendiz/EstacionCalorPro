/*
 * CPantallaMemoria.hpp
 *
 *  Created on: Sep 27, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAMEMORIA_CPANTALLAMEMORIA_HPP_
#define INC_GUI_PANTALLAMEMORIA_CPANTALLAMEMORIA_HPP_
#include "GUI/PantallaManual/CPantallaManual.hpp"
#include "ManejadorControles/CManejadorEventosControles.hpp"
#include "Estaciones/CEstacionBase.hpp"

class CPantallaMemoria: public CPantallaManual
{
private:
	int NumeroMemoria;
	int VelocidadAire=0;
	CEtiquetaTft *LabelMemoria;
	int VelocidadAireInicialPotenciometro;
	int DiferenciaAire=5;
	bool CambioNIvelAire=false;
	virtual void OnBotonCuatroClickEvent();
	virtual void GuardaTemperatura();
	void LeeDatosMemoria();
protected:
	virtual void LeeDatosEstacion();
	virtual void MuestraInformacion(bool forzar);
public:
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	CPantallaMemoria(CEstacionBase *estacion);
	CPantallaMemoria();
	virtual ~CPantallaMemoria();
	virtual void Show();
	void SetMemoria(int numeroMemoria);
};

#endif /* INC_GUI_PANTALLAMEMORIA_CPANTALLAMEMORIA_HPP_ */
