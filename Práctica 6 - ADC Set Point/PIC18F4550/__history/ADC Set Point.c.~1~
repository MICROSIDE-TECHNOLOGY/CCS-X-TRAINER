/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
Implementar una lectura analógica de un potenciómetro, si el valor del ADC supera
un Set Point, el LED encenderá.
---------------------------------------------------------------------------
*/


#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#DEVICE ADC=8                                   //Configura el ADC a 8 bits
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asigna los vectores de reset e interrupción para la versión con bootloader
#org 0x0000,0x1FFF {}                           //Reserva espacio en memoria para el bootloader

#define LED PIN_A1                              //Pin donde está conectado el LED del X-TRAINER

int ValorPot;                                   //Variable para almacenar el valor leído del ADC

void SisInit(void)

{

setup_oscillator(OSC_8MHZ);                    //Configura oscilador interno

setup_adc_ports (AN0);                         //Configura solo el puerto A0 como entrada analógica

setup_adc (ADC_CLOCK_DIV_8);                   //Configura oscilador para la conversión

}

 

void main()

{

    SisInit();

    while (1)

  {

       set_adc_channel (0);                 //Selecciona el canal 0 para la conversión

       ValorPot = read_adc ();              //Lee el valor del ADC y lo guarda en la variable

      if (ValorPot >= 128)                  //Compara el valor de el ADC con 128

             {

                     output_HIGH (LED);     // Leds activos

             }

      else

             {

                    output_LOW (LED);       // Leds activos

             }

       }

}

 
