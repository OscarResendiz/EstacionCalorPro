#include <SPI.h>           // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"  // Hardware-specific library
#include <MCUFRIEND_kbv.h>
#include "CPantallaBase.h"  //clase base para trabajar con pantallas
#include "CPantallaManual.h"
#include "CPantallaMemoria.h"
#include "CestacionVirtual.h"
#include "CComponenteBaseTft.h"
#include "CRectanguloTft.h"
#include "CEtiquetaTft.h"
#include "Adafruit_ILI9341.h"
#include "CManejadorControlesBase.h"
#include "CPantallaMenuPrincipal.h"
#include "CAdministradorPantallas.h"
#include "CAdmiinstradorPantallasBase.h"
// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10


Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
CestacionVirtual estacion;


//unsigned long testText() ;
void setup() {
  Serial.begin(9600);
  
  //inicializo la pantalla
  tft.begin();
  tft.fillScreen(BLACK);
   //tft.setRotation(3);
//   AdministradorPantallas.Setup(&tft, &estacion);
//  CPantallaManual p = CPantallaManual(&tft, &estacion);
//  CPantallaManual p1 = CPantallaManual(&tft, &estacion);
//  CPantallaMenuPrincipal p=CPantallaMenuPrincipal();//&tft, &estacion);
//p.SetTft(&tft);
  //    p.SetEstacion(&estacion);

//  Serial.println("aaa");
//  p.Show();
//AdministradorPantallas.ShowMenuPrincipal();
//AdministradorPantallas.ShowMenuPrincipal();
  Serial.println("fin de setup");
//  CPantallaManual pantallaManual;
  //pantallaManual.SetTft(&tft);
//  pantallaManual.SetEstacion(&Estacion);
  CPantallaManual pantallaManual=CPantallaManual(&tft, &estacion);
  pantallaManual.Show();

}

void loop() {
  estacion.Procesa();
  delay(1);
}
