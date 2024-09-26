/*
 * CFlash.hpp
 *
 *  Created on: Sep 23, 2024
 *      Author: W10
 */

#ifndef INC_EEPROM_CEEPROM_HPP_
#define INC_EEPROM_CEEPROM_HPP_

class CEEProm
{
public:
	CEEProm();
	virtual ~CEEProm();
	void Guardar(int clave, int valor);
	int Leer(int clave);
};

#endif /* INC_EEPROM_CEEPROM_HPP_ */
