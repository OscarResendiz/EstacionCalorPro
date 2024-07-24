#ifndef CMANEJADORCONTROLESBASE_H
#define CMANEJADORCONTROLESBASE_H
//interface que maneja los eventos relacionados con la temperatura de la estacion de calor tanto real como especificada por el usuario
class CManejadorControlesBase
{
  public:
  virtual void OnTemperaturaEvent(int temperatura)
  {

  }
  virtual void OnTemperaturaRealEvent(int temperatura)
  {
    
  }
  virtual void OnNivelAireEvent(int aire)
  {

  }
  //eventros del boton uno
  virtual void OnBotonUnoClickEvent(int tiempoClick)
  {

  }
  virtual void OnBotonUnoPresionadoEvent()
  {

  }
  virtual void OnBotonUnoPresionadoLargoEvent()
  {

  }
  virtual void OnBotonUnoSueltoEvent()
  {

  }
  //eventros del boton dos
  virtual void OnBotonDosClickEvent(int tiempoClick)
  {

  }
  virtual void OnBotonDosPresionadoEvent()
  {

  }
  virtual void OnBotonDosPresionadoLargoEvent()
  {

  }
  virtual void OnBotonDosSueltoEvent()
  {

  }
  //eventros del boton tres
  virtual void OnBotonTresClickEvent(int tiempoClick)
  {

  }
  virtual void OnBotonTresPresionadoEvent()
  {

  }
  virtual void OnBotonTresPresionadoLargoEvent()
  {

  }
  virtual void OnBotonTresSueltoEvent()
  {

  }
  //eventros del boton Cuatro
  virtual void OnBotonCuatroClickEvent(int tiempoClick)
  {

  }
  virtual void OnBotonCuatroPresionadoEvent()
  {

  }
  virtual void OnBotonCuatroPresionadoLargoEvent()
  {

  }
  virtual void OnBotonCuatroSueltoEvent()
  {

  }
  //eventros del boton Perilla
  virtual void OnBotonPerillaClickEvent(int tiempoClick)
  {

  }
  virtual void OnBotonPerillaPresionadoEvent()
  {

  }
  virtual void OnBotonPerillaPresionadoLargoEvent()
  {

  }
  virtual void OnBotonPerillaSueltoEvent()
  {

  }
  //eventos del Encoder
  virtual void OnPerillaIncremento()
  {

  }
  virtual void OnPerillaDecremento()
  {
    
  }
  };
#endif