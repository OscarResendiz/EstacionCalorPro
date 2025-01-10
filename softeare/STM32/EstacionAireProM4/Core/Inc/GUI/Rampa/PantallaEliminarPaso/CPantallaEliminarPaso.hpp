/*
 * CPantallaEliminarPaso.hpp
 *
 *  Created on: Jan 9, 2025
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAELIMINARPASO_CPANTALLAELIMINARPASO_HPP_
#define INC_GUI_PANTALLAELIMINARPASO_CPANTALLAELIMINARPASO_HPP_
#include "GUI/CPantallaBase.hpp"

class CPantallaEliminarPaso: public CPantallaBase
{
private:
	int ID_Paso;
	int ID_Rampa;
	char TextoEliminar[30];
	CEtiquetaTft *LabelGuardar;
	CEtiquetaTft *LabelCancelar;
	CEtiquetaTft *LabelMemoria;
public:
	CPantallaEliminarPaso();
	virtual ~CPantallaEliminarPaso();
	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonTresClickEvent();
	virtual void SetIdPaso(int id_rampa,int id_paso);
	virtual void Show();
};

#endif /* INC_GUI_PANTALLAELIMINARPASO_CPANTALLAELIMINARPASO_HPP_ */
