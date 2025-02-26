/************************************************************************************************
Company:
Microside Technology Inc.

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/
/*
------------------------------------------------------------------------------
 Implementar comunicaci�n serial para enviar un comando simple para prender y
 apagar un LED incluido en la tarjeta X-TRAINER, y un segundo comando para
 preguntar el estado de un bot�n.
------------------------------------------------------------------------------
*/

#include <18F45K50.h>                                 //Incluye el microcontrolador con el que se va a trabajar 
#use delay(internal=48MHz)                            // Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)               // Asigna los vectores de reset e interrupci�n para la versi�n con bootloader
#org 0x0000,0x1FFF {}                                 // Reserva espacio en memoria para el bootloader

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7,STREAM=UART ) //Configuraci�n del puerto UART

#define LED PIN_A4                                         //Pin donde est� conectado el LED del X-TRAINER
#define Boton PIN_A2                                        //Pin donde est� conectado el BOTON del X-TRAINER

void main ()

  {

   while (1)

  {
   char Caracter = getc ();                                 //Guarda el caracter
   
   if (Caracter == '0')

    {
      output_low (LED);                                     //Apaga el LED
    }

     else if (Caracter == '1')

    {
     output_HIGH (LED);                                     //Enciende el LED
    }

     else if (Caracter == '?')

    {

        if (1 == input (Boton))                             //Pregunta el estado del bot�n

          {                                                                   
            Printf ("0");                                   //Env�a un 0 si el bot�n no est� presionado
          }

          else

         {
           Printf ("1");                                     //Env�a un 1 si el bot�n est� presionado
         }

      }

   }

}
