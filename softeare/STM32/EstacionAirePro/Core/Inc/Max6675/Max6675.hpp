/*
 * max6675.h
 *
 *  Created on: Apr 9, 2023
 *      Author: Alcides Ramos
 */

#ifndef LIBRERIAS_MAX6675_H_
#define LIBRERIAS_MAX6675_H_
#include "Delays/delays.hpp"
#include <Constantes.hpp>
class MAX6675
{
private:
	GPIO_TypeDef *DAT_MAX_GPIO_Port;
	GPIO_TypeDef *CK_MAX_GPIO_Port;
	GPIO_TypeDef *CS_MAX_GPIO_Port;
	uint16_t DAT_MAX_Pin;
	uint16_t CK_MAX_Pin;
	uint16_t CS_MAX_Pin;
	int TiempoTranscurrido;
	float UltimaTemperatura;
public:
	MAX6675();
	void Init();
	void SetConfigDatPin(GPIO_TypeDef *portDat, uint16_t pinDat);
	void SetConfigCkPin(GPIO_TypeDef *portCk, uint16_t pinCk);
	void SetConfigCsPin(GPIO_TypeDef *portCs, uint16_t pinCs);
	uint8_t MAX6675_pulso();
	float MAX6675_lee();
};
#endif /* LIBRERIAS_MAX6675_H_ */
