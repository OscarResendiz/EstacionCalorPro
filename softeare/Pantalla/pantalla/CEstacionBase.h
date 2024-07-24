//clase base que representa una estacion de calor generica y hay que sobrecargarla para estaciones funcionales
#ifndef CESTACIONBASE_H
#define CESTACIONBASE_H
#include "CPantallaBase.h" //clase base para trabajar con pantallas
#include "CManejadorControlesBase.h"
class CEstacionBase
{
  protected:
  //eventos
  CManejadorControlesBase *ManejadorControles=NULL;
  public:
  CEstacionBase()
  {

  }
  virtual int GetTemperaturaReal() //regresa la tenperatura actual de la estacion
  {

  }
  virtual void SetTemperatura(int temperatura) //establece la temperatura que se quiere alcanzar
  {

  }
  virtual int GetTemperatura()// regresa la temperatura seteada
  {

  }
  virtual void SetNivelAire(int nivel) //establece el nivel de aire
  {

  }
  virtual int GetNivelAire() //regresa el nivel de aire setado
  {

  }
  virtual int GetEstado() //regresa 1 si esta activo y 0 si esta en reposo
  {

  }
  //para que la misma estacion incremente la temperatura
  virtual void IncrementaTemperatura()
  {

  }
  //para que la misma estacion decremente la temeperatura
  virtual void DecrementaTemperatura()
  {

  }
  // asigna el evento que sellamara cuando cambie la temperatura que el usuario especifica
  virtual void SetManejadorControles(CManejadorControlesBase * obj)
  {
    ManejadorControles=obj;
  }
  //funcion que se debera llamar para controlar la estacion de calor
  virtual void Procesa()
  {

  }
  protected:
  virtual void TemperaturaEvent(int temperatura)
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnTemperaturaEvent(temperatura);
  }
  virtual void NivelAireEvent(int aire)
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnNivelAireEvent(aire);
  }
  virtual void TemperaturaRealEvent(int temperatura)
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnTemperaturaRealEvent(temperatura);

  }
  //eventros del boton uno
  virtual void BotonUnoClickEvent(int tiempoClick)
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonUnoClickEvent(tiempoClick);

  }
  virtual void BotonUnoPresionadoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonUnoPresionadoEvent();

  }
  virtual void BotonUnoPresionadoLargoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonUnoPresionadoLargoEvent();

  }
  virtual void BotonUnoSueltoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonUnoSueltoEvent();

  }
  //eventros del boton dos
  virtual void BotonDosClickEvent(int tiempoClick)
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonDosClickEvent(tiempoClick);

  }
  virtual void BotonDosPresionadoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonDosPresionadoEvent();

  }
  virtual void BotonDosPresionaLargodoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonDosPresionadoLargoEvent();

  }
  virtual void BotonDosSueltoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonDosSueltoEvent();

  }
  //eventros del boton tres
  virtual void BotonTresClickEvent(int tiempoClick)
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonTresClickEvent(tiempoClick);

  }
  virtual void BotonTresPresionadoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonTresPresionadoEvent();

  }
  virtual void BotonTresPresionaLargodoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonTresPresionadoLargoEvent();

  }
  virtual void BotonTresSueltoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonTresSueltoEvent();

  }
  //eventros del boton Cuatro
  virtual void BotonCuatroClickEvent(int tiempoClick)
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonCuatroClickEvent(tiempoClick);

  }
  virtual void BotonCuatroPresionadoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonCuatroPresionadoEvent();

  }
  virtual void BotonCuatroPresionaLargodoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonCuatroPresionadoLargoEvent();
  }
  virtual void BotonCuatroSueltoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonCuatroSueltoEvent();

  }
  //eventros del boton Perilla
  virtual void BotonPerillaClickEvent(int tiempoClick)
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonPerillaClickEvent(tiempoClick);

  }
  virtual void BotonPerillaPresionadoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonPerillaPresionadoEvent();

  }
  virtual void BotonPerillaPresionadoLargoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonPerillaPresionadoLargoEvent();

  }
  virtual void BotonPerillaSueltoEvent()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnBotonPerillaSueltoEvent();
  }
//eventos del encoder
  virtual void EncoderIncremento()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnPerillaIncremento();

  }
  virtual void EncoderDecremento()
  {
    if(ManejadorControles==NULL)
      return;
      ManejadorControles->OnPerillaDecremento();

  }
};
#endif