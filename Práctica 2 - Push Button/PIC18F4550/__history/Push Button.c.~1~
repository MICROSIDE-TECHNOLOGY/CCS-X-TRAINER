/*
   AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
   FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
 Implementar el control de encendido y apagado de un LED mediante
 un botón pulsador.
---------------------------------------------------------------------------
*/

#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versión con bootloader

#define LED PIN_A1                              //Asigna el pin A1 al LED del X-TRAINER
#define BOTON PIN_A2                            //Asigna el pin A2 al boton BOOT del X-TRAINER

void SisInit (void)

 {
     set_tris_a (0b11111101);                   //Pin A1 como salida
 }

void main (void)
 {
   SisInit ();

   while (1)                                     //Ciclo repetitivo
   
   {
    if (0 == input (BOTON))                      //Lee el estado del boton
      {
       output_high (LED);                        //Si se presiona el boton enciende el LED
      }

     else

     {
      output_low (LED);                          //De lo contrario el LED se apaga
     }

   }

}
