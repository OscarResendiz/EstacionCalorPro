/*
 * CManejadorEventoSensorMagnetico.h
 *
 *  Created on: Aug 23, 2024
 *      Author: W10
 */

#ifndef INC_SENSORMAGNETICO_CMANEJADOREVENTOSENSORMAGNETICO_H_
#define INC_SENSORMAGNETICO_CMANEJADOREVENTOSENSORMAGNETICO_H_

class CManejadorEventoSensorMagnetico
{
public:
	CManejadorEventoSensorMagnetico();
	virtual ~CManejadorEventoSensorMagnetico();
	virtual void OnSensorMagneticoChange(int estado);
};

#endif /* INC_SENSORMAGNETICO_CMANEJADOREVENTOSENSORMAGNETICO_H_ */
