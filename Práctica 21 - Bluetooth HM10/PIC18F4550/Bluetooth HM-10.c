/************************************************************************************************
Company:
Microside Technology Inc.

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/
/*
---------------------------------------------------------------------------
Esta pr�ctica consiste en realizar el envio de datos por medio de un m�dulo
Bluetooth, usando el protocolo de comunicaci�n serial UART, para enviar un
comando simple para prender y apagar un LED incluido en la tarjeta X-TRAINER,
y un segundo comando para preguntar el estado de un bot�n.
---------------------------------------------------------------------------
*/

#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignaci�n de los vectores de reset e interrupci�n
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versi�n con bootloader


#USE RS232(stream=SERIE, BAUD=9600, PARITY=N, XMIT=PIN_C6, RCV=PIN_C7,BITS=8)

#define LED pin_A4
#define Boton pin_A2

     void main(void)
        {

              while(!kbhit())                    //Pregunta si hay algun dato recibido
               while (TRUE)
                     {
                       char Caracter = getc ();  //Guarda el caracter

                       if (Caracter == '0')

                            {

                               output_low (LED); //Apaga el LED
                               fprintf(SERIE,"LED APAGADO\\\\n");

                            }

                       else if (Caracter == '1')

                         {
                               output_HIGH (LED); //Enciende el LED
                               fprintf(SERIE,"LED ENCENDIDO\\\\n");

                         }

                       else if (Caracter == '?')    //Pregunta el estado del bot�n

                         {

                        if (1 == input (Boton))

                           {

                          Printf ("0");             //Env�a un 0 si el bot�n no est� presionado

                            }

                 else

                       {

                           Printf ("1");            //Env�a un 1 si el bot�n est� presionado

                       }

                }

        }
}
