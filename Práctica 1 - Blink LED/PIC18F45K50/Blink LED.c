/************************************************************************************************
Company:
Microside Technology Inc.

File Name:
Blink_LED.mcppi

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

#include <18F45K50.h>                           //Incluye el microcontrolador con el que se va a trabajar 
#use delay(internal=48Mhz)                      //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignaci�n de los vectores de reset e interrupci�n
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versi�n con bootloader
#define LED PIN_A4                              //Pin donde est� conectado el LED de X-TRAINER

void main(void)
{
     set_tris_a(0XFD);                          //Pin RA4 como salida

     while(1)
           {
                  output_HIGH (LED);             //Cambio de estado en el pin RA4
                  delay_ms (500);                //Retardo 
                  output_LOW (LED);              //Cambio de estado en el pin RA4
                  delay_ms (500) ;               //Retardo
           }
}
