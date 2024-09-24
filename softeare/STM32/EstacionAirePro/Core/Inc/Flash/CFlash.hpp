/*
 * CFlash.hpp
 *
 *  Created on: Sep 23, 2024
 *      Author: W10
 */

#ifndef INC_FLASH_CFLASH_HPP_
#define INC_FLASH_CFLASH_HPP_

class CFlash
{
public:
	CFlash();
	virtual ~CFlash();
	void Guardar(int clave, int valor);
	int Leer(int clave);
};

#endif /* INC_FLASH_CFLASH_HPP_ */
