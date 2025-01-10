/*
 * CPantallaEliminarRampa.hpp
 *
 *  Created on: Jan 8, 2025
 *      Author: W10
 */

#ifndef INC_GUI_RAMPA_PANTALLAELIMINARRAMPA_CPANTALLAELIMINARRAMPA_HPP_
#define INC_GUI_RAMPA_PANTALLAELIMINARRAMPA_CPANTALLAELIMINARRAMPA_HPP_
#include "GUI/CPantallaBase.hpp"

class CPantallaEliminarRampa: public CPantallaBase
{
private:
	int ID_Rampa;
	char TextoEliminar[30];
	CEtiquetaTft *LabelGuardar;
	CEtiquetaTft *LabelCancelar;
	CEtiquetaTft *LabelMemoria;
public:
	CPantallaEliminarRampa();
	virtual ~CPantallaEliminarRampa();
	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonTresClickEvent();
	virtual void SetIdRampa(int id_rampa);
	virtual void Show();
};

#endif /* INC_GUI_RAMPA_PANTALLAELIMINARRAMPA_CPANTALLAELIMINARRAMPA_HPP_ */
