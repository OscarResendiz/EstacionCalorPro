/*
 * Principal.h
 *
 *  Created on: Jul 16, 2024
 *      Author: W10
 */

#ifndef INC_PRINCIPAL_HPP_
#define INC_PRINCIPAL_HPP_
#include "Max6675/Max6675.hpp"
#include "ControlVelocidadAire/ControlVelocidadAire.hpp"

extern MAX6675 max6675;
extern ControlVelocidadAire controlVelocidadAire;
void IncializaSistema();
void EjecutaSistema();

#endif /* INC_PRINCIPAL_HPP_ */
