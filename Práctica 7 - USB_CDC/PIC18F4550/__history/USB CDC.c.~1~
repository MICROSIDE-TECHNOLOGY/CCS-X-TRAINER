/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
--------------------------------------------------------------------------------
Implementar comunicación USB (CDC) para enviar un comando simple para prender y
apagar un LED incluido en la tarjeta X-TRAINER, y un segundo comando para
preguntar el estado de un botón.
--------------------------------------------------------------------------------
*/

 
#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versión con bootloader

#include <usb_cdc.h>                            //Libreria USB-CDC

#define LED PIN_A1                              //Pin donde está conectado el LED del X-TRAINER
#define Boton PIN_A2                            //Pin donde está conectado el BOTON del X-TRAINER

void main(void)
  {

      set_tris_a(0b11111111);
      set_tris_b(0b11111100);                   //Configura puerto B (1= entrada 0= salida )
      usb_cdc_init();                           // Configuramos al puerto virtual.
      usb_init();                               // Inicializamos el stack USB.

      while(!usb_cdc_connected()) {}            // espera a detectar una transmisión de la PC (Set_Line_Coding)
       do{
               usb_task();              
                if(usb_enumerated())
                    {

                      char Caracter =usb_cdc_getc();                     //Guarda el caracter

                      if (Caracter == '0')

                         {

                            output_low (LED);                            //Apaga el LED

                            printf(usb_cdc_putc,"LED apagado\n"); //Envia un texto del estado del LED

                         }

 
                     else if (Caracter == '1')

                         {

                            output_HIGH (LED);                             //Enciende el LED

                            printf(usb_cdc_putc,"LED encendido\n"); //Envia un texto del estado del LED

                         }

                      else if (Caracter == '?')


                        {

                            if (1 == input (Boton))                 //Pregunta el estado del botón
                               {

                                 printf(usb_cdc_putc,"0\n"); //Envía un 0 si el botón no está presionado

                                }
                                
                          else
                                 {
                                 
                                  printf(usb_cdc_putc,"1\n"); //Envía un 1 si el botón está presionado
                                 
                                 }

                      }

              }
       }while (TRUE);                                       // bucle infinito.
}
