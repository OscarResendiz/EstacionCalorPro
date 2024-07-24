#ifndef CESTACIONVIRTUAL_H
#define CESTACIONVIRTUAL_H
#include "CEstacionBase.h"
#include "max6675.h"
#include "CManejadorEventosBoton.h"
#include "CManejadorBoton.h"
#include "CEncoder.h"
#include "CManejadorEventosEncoder.h"
// CONFIGURACION DE LOS PINES UTILIZADOS PARA LA COMUNICACIÓN CON EL MAX6675

//clase que representa una estacion de calor virtual para hacer pruebas
class CestacionVirtual: public CEstacionBase,CManejadorEventosBoton,CManejadorEventosEncoder
{
  private:
  int TemperaturaMaxima=500;
  int TemperaturaEspecificada=100;
  int temperaturaAnterior=0;
  int temperaturaRealAnterior=0;
  int AireAnterior=0;
  protected:
  int CONFIG_TCSCK_PIN=      8;
  int CONFIG_TCCS_PIN=       11;
  int CONFIG_TCDO_PIN =      12;
  int PortAire=A0;
  // OBJETO UTILIZADO PARA LA COMUNICACION CON EL MAX6675
  MAX6675 *thermocouple;
  CManejadorBoton BotonMemoria1=CManejadorBoton(this,BOTON_MEMORIA1,PD7);
  CManejadorBoton BotonMemoria2=CManejadorBoton(this,BOTON_MEMORIA2,PD6);
  CManejadorBoton BotonMemoria3=CManejadorBoton(this,BOTON_MEMORIA3,PD5);
  CManejadorBoton BotonManual=CManejadorBoton(this,BOTON_MANUAL,PD4);
  CEncoder Encoder=CEncoder(this,1,A1,PD2,PD3);
//  CManejadorBoton BotonPerilla=CManejadorBoton(this,BOTON_PERILLA,PD3);
  public:
  CestacionVirtual()
  :CEstacionBase()
  {
    thermocouple=new MAX6675(CONFIG_TCSCK_PIN, CONFIG_TCCS_PIN, CONFIG_TCDO_PIN);
  }
   //regresa la tenperatura actual de la estacion
  virtual int GetTemperaturaReal()
  {
    int temperatura= thermocouple->readCelsius()*.59;
    return temperatura;
  }
   //establece la temperatura que se quiere alcanzar
  virtual void SetTemperatura(int temperatura)
  {
    TemperaturaEspecificada=temperatura;
    TemperaturaEvent(TemperaturaEspecificada);
  }
  // regresa la temperatura seteada
  virtual int GetTemperatura()
  {
    return TemperaturaEspecificada;
  }
  //establece el nivel de aire
  virtual void SetNivelAire(int nivel)
  {

  } 
  //regresa el nivel de aire setado
  virtual int GetNivelAire() 
  {
    return map(analogRead(PortAire), 0, 1023, 100, 0); 
  }
   //regresa 1 si esta activo y 0 si esta en reposo
  virtual int GetEstado()
  {
    return 0;
  }
  virtual void Procesa()
  {
    ProcesaTemperatura();
    ProcesaTemperaturaReal();
    procesaAire();
    ProcesaBotones();
  }
  private:
  //verifica el nivel de temperatura seleccinada por el usuario
  void ProcesaTemperatura()
  {
      //leo la temperatura
      int temp=GetTemperatura();
      //veo si cambio
      if(temperaturaAnterior!=temp)
      {
        temperaturaAnterior=temp;
          //aviso que cambio la temperatura
          TemperaturaEvent(temperaturaAnterior);
      }
  }
  //verifica elnivel de aire
  void procesaAire()
  {
      int aire=GetNivelAire();
      if(AireAnterior!=aire)
      {
        AireAnterior=aire;
        NivelAireEvent(AireAnterior);
      }
  }
  void ProcesaTemperaturaReal()
  {
      int temperatura=GetTemperaturaReal();
      if(temperaturaRealAnterior!=temperatura)
      {
        temperaturaRealAnterior=temperatura;
        TemperaturaRealEvent(temperaturaRealAnterior);
      }
  }
  void ProcesaBotones()
  {
    BotonMemoria1.Procesa();
    BotonMemoria2.Procesa();
    BotonMemoria3.Procesa();
    BotonManual.Procesa();
    Encoder.Procesa();
  }
  //eventos de CManejadorEventosBoton
  virtual void OnBotonClickEvent(int idBoton, int tiempoClick)
  {
    switch(idBoton)
    {
      case BOTON_MEMORIA1:
        BotonUnoClickEvent(tiempoClick);
      break;
      case BOTON_MEMORIA2:
        BotonDosClickEvent(tiempoClick);
      break;
      case BOTON_MEMORIA3:
        BotonTresClickEvent(tiempoClick);
      break;
      case BOTON_MANUAL:
        BotonCuatroClickEvent(tiempoClick);
      break;
    }
  }
  virtual void OnBotonPresionadoEvent(int idBoton)
  {
    switch(idBoton)
    {
      case BOTON_MEMORIA1:
        BotonUnoPresionadoEvent();
      break;
      case BOTON_MEMORIA2:
        BotonDosPresionadoEvent();
      break;
      case BOTON_MEMORIA3:
        BotonTresPresionadoEvent();
      break;
      case BOTON_MANUAL:
        BotonCuatroPresionadoEvent();
      break;
    }

  }
  virtual void OnBotonSueltoEvent(int idBoton)
  {
    switch(idBoton)
    {
      case BOTON_MEMORIA1:
        BotonUnoSueltoEvent();
      break;
      case BOTON_MEMORIA2:
        BotonDosSueltoEvent();
      break;
      case BOTON_MEMORIA3:
        BotonTresSueltoEvent();
      break;
      case BOTON_MANUAL:
        BotonCuatroSueltoEvent();
      break;
    }
  }
  //eventros del encoder
  virtual void OnIncrementoEncoder(int id_Encoder)
  {
    EncoderIncremento();
  }
  virtual void OnDecrementoEncoder(int id_Encoder)
  {
    EncoderDecremento();
  }
  virtual void OnBotonEncoderClickEvent(int id_Encoder, int tiempoClick)
  {
        BotonPerillaClickEvent(tiempoClick);
  }
  virtual void OnBotonEncoderPresionadoEvent(int id_Encoder)
  {
        BotonPerillaPresionadoEvent();
  }
  virtual void OnBotonEncoderPresionadoLargoEvent(int id_Encoder)
  {
        BotonPerillaPresionadoLargoEvent();
  }
  virtual void OnBotonEncoderSueltoEvent(int id_Encoder)
  {
        BotonPerillaSueltoEvent();
  }
  virtual void IncrementaTemperatura()
  {
    if(TemperaturaEspecificada<TemperaturaMaxima)
    {
      TemperaturaEspecificada++;
      TemperaturaEvent(TemperaturaEspecificada);
    }
  }
  virtual void DecrementaTemperatura()
  {
    if(TemperaturaEspecificada>0)
    {
      TemperaturaEspecificada--;
      TemperaturaEvent(TemperaturaEspecificada);
    }
  }

};
#endif