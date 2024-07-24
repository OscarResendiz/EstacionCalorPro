#ifndef CENCODER_H
#define CENCODER_H
#include "CManejadorBoton.h"
#include "CManejadorEventosBoton.h"
#include "CManejadorEventosEncoder.h"
#define ID_CLK 1
#define ID_DT 2
#define ID_BOTON 3
class CEncoder : CManejadorEventosBoton {
private:
  int PinClk;
  int PinDt;
  int PinBoton;
  CManejadorBoton *Boton;
  CManejadorEventosEncoder *Manejador;
  int ID_Encoder;
  //---------------------------------
  int CLK_status = 0;
  int DT_status = 0;
  int CLK_Rebotes = 0;
  int DT_Rebotes = 0;
  int CLK_PreStatus = 0;
  int DT_PreStatus = 0;
  int CLK_statusAnterior;
  int DT_statusAnterior;
  int estado;
public:
  CEncoder(CManejadorEventosEncoder *manejador, int id_Encoder, int clk, int dt, int btn) {
    Manejador = manejador;
    PinClk = clk;
    PinDt = dt;
    PinBoton = btn;
    ID_Encoder = id_Encoder;
    Boton = new CManejadorBoton(this, ID_BOTON, PinBoton);
    CLK_statusAnterior = digitalRead(PinClk);
  }
  virtual void OnBotonSueltoEvent(int idBoton) {
    if (Manejador == NULL) {
      return;
    }
    switch (idBoton) {
      case ID_BOTON:
        Manejador->OnBotonEncoderSueltoEvent(ID_Encoder);
        break;
    }
  }
  virtual void OnBotonPresionadoEvent(int idBoton) {
    if (Manejador == NULL) {
      return;
    }
    switch (idBoton) {
      case ID_BOTON:
        Manejador->OnBotonEncoderPresionadoEvent(ID_Encoder);
        break;
    }
  }
  virtual void OnBotonClickEvent(int idBoton, int tiempoClick) {

    switch (idBoton) {
      case ID_BOTON:
        Manejador->OnBotonEncoderClickEvent(ID_Encoder, tiempoClick);
        break;
    }
  }
  virtual void Procesa() {
    Boton->Procesa();
    leeEncoder();
  }
  void leeEncoder() {
    CLK_status = digitalRead(PinClk);
    if (CLK_status != CLK_statusAnterior && CLK_status == 1) {
      if (digitalRead(PinDt) != CLK_status) {
        incrementa();
      } else {
        decrementa();
      }
    }
    CLK_statusAnterior = CLK_status;
  }
    void incrementa() {
    Manejador->OnIncrementoEncoder(ID_Encoder);
  }
  void decrementa() {
    Manejador->OnDecrementoEncoder(ID_Encoder);
  }
};
#endif
