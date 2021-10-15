/************************************************************************************************
Company:
Microside Technology Inc.

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/
/*
------------------------------------------------------------------------------
Se configura el módulo CTMU para detectar cuando se toca el pad conectado
al pin A3 de X-TRAINERp8 y envia el caracter 'C' relacionado a ese pin con el sensor touch,
al mismo tiempo enciende el LED integrado, conectado en el pin A1 para mostrar cuando es tocado
el sensor.
------------------------------------------------------------------------------
*/

#include <18F45K50.h>                  //Incluye el microcontrolador con el que se va a trabajar 
#device adc=10                         //ADC a 10 bits
#use delay(internal=48MHz)             //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)//Asigna los vectores de reset e interrupción para la versión con bootloader
#org 0x0000,0x1FFF {}                  //Reserva espacio en memoria para el bootloader

#define LED pin_A4

/*
------------------------------------------------------------------------------
Configuración del módulo CTMU para que funcione como sensor de toque
-El Threshold controla la sensibilidad (0-100)
-Scantime tiempo en milisegundo para escanear el pin.
-El Pin para conectar el sensor, debe ser una entrada análogica, se asocia con un caracter,
  si hubiera más sensores a cada uno se le asigna un caracter diferente para identificarlo.
------------------------------------------------------------------------------
*/

#USE TOUCHPAD(RANGE=L, THRESHOLD=50, SCANTIME=12, PIN_A3='C')

void main()
{
   TOUCHPAD_STATE (1);               //calibra
   TOUCHPAD_STATE (0);               //regresa a estado normal
   enable_interrupts (GLOBAL);       //Habilita interrupciones
   while(TRUE)
   {
      if(TOUCHPAD_HIT() )            //Verifica si se ha tocado el sensor
      {
        
         if (TOUCHPAD_GETC()=='C')   //Verifica cúal sensor fue tocado (se identifica con un carácter)
         {
           output_bit (LED, 1);      //enciende LED
           delay_ms (80);            //espera
         }
      }

      else output_bit (LED, 0);     //apaga LED si no ha sido tocado el sensor
    }
}
