/*
 * SensorMagnetico.h
 *
 *  Created on: Aug 23, 2024
 *      Author: W10
 */

#ifndef INC_SENSORMAGNETICO_SENSORMAGNETICO_H_
#define INC_SENSORMAGNETICO_SENSORMAGNETICO_H_
#include "stm32f1xx.h"
#include "SensorMagnetico/CManejadorEventoSensorMagnetico.hpp"
class SensorMagnetico
{
private:
	GPIO_TypeDef * GPIO_Port;
	uint16_t Gpio_Pin;
	CManejadorEventoSensorMagnetico *Manejador = NULL;
	  int Estado = 1;  //1 es abierto 0 es presionado
	  int PreEstado = 1;
	  int ReboteMilis = 0;

public:
	SensorMagnetico();
	virtual ~SensorMagnetico();
	void Configurar(GPIO_TypeDef *puerto, uint16_t pin);
	void Init();
	void AsignaManejadorEventos(CManejadorEventoSensorMagnetico * manejador);
	void Procesa();
	int Leer();

};

#endif /* INC_SENSORMAGNETICO_SENSORMAGNETICO_H_ */
