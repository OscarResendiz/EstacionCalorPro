/*
 * EventosEncoder.hpp
 *Clase que sirve como interface para procesar los eventos del encoder
 *  Created on: Jul 19, 2024
 *      Author: W10
 */

#ifndef INC_ENCODER_EVENTOSENCODER_HPP_
#define INC_ENCODER_EVENTOSENCODER_HPP_

class CManejadorEventosEncoder
{
public:
	CManejadorEventosEncoder();
	virtual ~CManejadorEventosEncoder();
	virtual void OnIncrementoEncoder(int id_Encoder);
	virtual void OnDecrementoEncoder(int id_Encoder);
	virtual void OnBotonEncoderClickEvent(int id_Encoder);
};

#endif /* INC_ENCODER_EVENTOSENCODER_HPP_ */
