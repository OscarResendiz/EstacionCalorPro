/*
 * CControlProgreso.hpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#ifndef INC_RAPATEMPERATURA_CCONTROLPROGRESO_HPP_
#define INC_RAPATEMPERATURA_CCONTROLPROGRESO_HPP_

class CControlProgreso
{
public:
	CControlProgreso();
	virtual ~CControlProgreso();
	virtual void OnProgreso(int valor, int maximo);
	virtual void OnMensaje(char *texto);
	virtual void OnFinProgreso();
};

#endif /* INC_RAPATEMPERATURA_CCONTROLPROGRESO_HPP_ */
