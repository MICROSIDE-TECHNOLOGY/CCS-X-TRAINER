/************************************************************************************************
Company:
Microside Technology Inc.

File Name:
Blink led.c

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
---------------------------------------------------------------------------
La pr�ctica consiste en controlar el encendido y apagado del LED incluido
en la tarjeta X-TRAINER
---------------------------------------------------------------------------
*/

#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignaci�n de los vectores de reset e interrupci�n
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versi�n con bootloader

#define LED PIN_A1                              //Pin donde est� conectado el LED del X-TRAINER


void main(void)
{
     set_tris_a(0XFD);                          //Pin RA1 como salida
     
     while(1)

           {
                  output_HIGH (LED);            //Cambio de estado en el pin RA1
                  delay_ms (500);               //Retardo
                  output_LOW (LED);             //Cambio de estado en el pin RA1     
                  delay_ms (500) ;              //Retardo
           }
}

 
