/*
 * InterfaceSensorTemperatura.hpp
 *
 *  Created on: Oct 20, 2024
 *      Author: W10
 */

#ifndef INC_SENSORTEMPERATURA_INTERFACESENSORTEMPERATURA_INTERFACESENSORTEMPERATURA_HPP_
#define INC_SENSORTEMPERATURA_INTERFACESENSORTEMPERATURA_INTERFACESENSORTEMPERATURA_HPP_

class InterfaceSensorTemperatura
{
public:
	InterfaceSensorTemperatura();
	virtual ~InterfaceSensorTemperatura();
	virtual void Init();
	virtual int LeeTemepatura();

};

#endif /* INC_SENSORTEMPERATURA_INTERFACESENSORTEMPERATURA_INTERFACESENSORTEMPERATURA_HPP_ */
