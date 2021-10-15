/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/


/*

Esta práctica consiste en realizar un control DAC para variar el voltaje de una
salida analogica y visualizarlo en un LED.

———————Registros para configurar el modulo DAC——————-
VREFCON1: Registro de configuración de voltajes de referencia
BIT7 <DACEN> 1=DAC ACTIVO, 0=DAC DESACTIVO
BIT6 <DACLPS> 0=NEGATIVA REFERENCIA, 1=POSITIVA REFERENCIA
BIT5 <DACOUT> 0=PIN DE SALIDA DESACTIVADO, 1=PIN DE SALIDA ACTIVADO
BIT4 <NO IMPLEMENTADO>
BIT3,BIT2 <DACPSS> FUENTE POSITIVA
00 = VDD
01 = VREF +
10 = FVR (Referencia de Voltaje Fijo)
11 = Reservado
BIT1 <NO IMPLEMENTADO>
BIT0 <DACNSS> 0=VSS, 1= -VREF
VREFCON2 El valor del DAC se carga en este registro; DAC 5 bits (0-31 decimal)
*/

#include <18F45K50.h>                          //Incluye el microcontrolador con el que se va a trabajar 
#use delay(internal=48MHz)                     //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)        //Asigna los vectores de reset e interrupción para la versión con bootloader
#org 0x0000,0x1FFF {}                          //Reserva espacio en memoria para el bootloader

#BYTE VREFCON1=0XF7C                           //Posición del registro en la memoria del pic18f45k50
#BYTE VREFCON2=0XF7B

signed INT VALOR;


void main()
{
      VREFCON1 = 0b10100000;                   //Registro de configuración de voltajes de referencia de DAC
      set_tris_b (0x00);                       //Configuración del puerto B como salidas digitales

      while (true)

          {
                 for (VALOR = 0; VALOR < 32; VALOR++)

                   {

                       VREFCON2 = VALOR;       //Valor que se carga al DAC. 
                       output_b (VALOR);       //Se pasa el valor al puerto B
                       delay_ms (500);         //Retardo

                    }

                   delay_ms (2000);            //Retardo

                  for (VALOR = 31; VALOR >= 0; VALOR--)

                     {
                          VREFCON2 = VALOR;     //Valor que se carga al DAC.
                          output_b (VALOR);     //Se pasa el valor al puerto B
                          delay_ms (500);       //Retardo
                }

              delay_ms (2000);                  //Retardo
       }
}
