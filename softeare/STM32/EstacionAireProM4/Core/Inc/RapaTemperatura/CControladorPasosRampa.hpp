/*
 * CControladorPasosRampa.hpp
 *
 *  Created on: Jan 8, 2025
 *      Author: W10
 */

#ifndef INC_RAPATEMPERATURA_CCONTROLADORPASOSRAMPA_HPP_
#define INC_RAPATEMPERATURA_CCONTROLADORPASOSRAMPA_HPP_
#include <RapaTemperatura/CPaso.hpp>
#include <EPROM/CEprom.hpp>

class CControladorPasosRampa
{
private:
	int  NUMERO_MAXIMO_PASOS=2000;
	int BytesPaso=7;
	int DireccionUltimoID_Paso;
	uint16_t UltimoID_Paso;
	int DireccionTablaPasos;
//	int tmpPasos[100];
//	int posicionPasoActual;
	void OrdenaPasos(int npasos);
	CPaso LeePasoMemoria(int direccion);

public:
	CControladorPasosRampa();
	virtual ~CControladorPasosRampa();
	bool AgregarPasoRampa(int ID_Rampa,uint16_t Temperatura,uint8_t NivelAire,uint8_t Segundos);
	int DameSiguienteID_Paso();
	bool ActualizaPasoRampa(int ID_Paso,int ID_Rampa,uint16_t Temperatura,uint8_t NivelAire,uint8_t Segundos);
	bool EliminaPasoRampa(int ID_Paso);
	CPaso DamePasoRampa(int ID_Paso);
	int DameNumeroPasosRampa(int ID_Rampa);
	CPaso DameSiguientePaso(int id_rampa, int id_pasActual);
	void SetDireccionUltimoID_Paso(int ultimoID);
	void SetDireccionTablaPasos(int direccion);
	void SetNumeroMaximoPasos(int valor);
	int GetNumeroMaximoPasos();
	int GetDireccionTablaPasos();
	int GetBytesXPaso();
	void GuardaPasoMemoria(int direccion, CPaso *paso);
	void SetUltimoIDPado(uint8_t id);
	bool EliminaPasosRampa(int ID_Rampa);
};
extern CControladorPasosRampa ControladorPasosRampa;

#endif /* INC_RAPATEMPERATURA_CCONTROLADORPASOSRAMPA_HPP_ */
