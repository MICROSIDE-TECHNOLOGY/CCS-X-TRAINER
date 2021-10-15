/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
La práctica consiste en controlar el encendido y apagado del LED incluido
en la tarjeta X-TRAINER
---------------------------------------------------------------------------
*/

#include <18F45K50.h>                          //Incluye el microcontrolador con el que se va a trabajar 
#use delay(internal=48Mhz)                     //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)        //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                          //Reserva espacio en la memoria para la versión con bootloader
#define LED PIN_A1                             //Pin donde está conectado el LED de X-TRAINER

void SisInit(void)
  {
      set_tris_a(0XFD);                        //Pin RA1 como salida
  }

void main(void)
  {
     SisInit ();

     while(1)
           {
                  output_HIGH (LED);             //Cambio de estado en el pin RA1
                  delay_ms (500);                //Retardo 
                  output_LOW (LED);              //Cambio de estado en el pin RA1
                  delay_ms (500) ;               //Retardo
           }
}
