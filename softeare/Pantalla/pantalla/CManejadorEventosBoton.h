#ifndef CMANEJADOREVENTOSBOTON_H
#define CMANEJADOREVENTOSBOTON_H
//clase que se usa cmo interface para avisar de los eventos del boton
class CManejadorEventosBoton
{
  public:
  virtual void OnBotonClickEvent(int idBoton, int tiempoClick)
  {

  }
  virtual void OnBotonPresionadoEvent(int idBoton)
  {

  }
  virtual void OnBotonSueltoEvent(int idBoton)
  {

  }
  virtual void OnBotonPresionadoLargoEvent(int idBoton)
  {

  }

};
#endif