/************************************************************************************************
Company:
Microside Technology Inc.

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
---------------------------------------------------------------------------
Esta pr�ctica consiste en variar la velocidad de un motor por medio de un sensor
SHARP usando los m�dulos PWM y ADC.
---------------------------------------------------------------------------
*/

#include <18F45K50.h>                             //Incluye el microcontrolador con el que se va a trabajar 
#device ADC=8                                     // Configura el ADC a 8 bits
#use delay(internal=48MHz)                        // Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)           // Asigna los vectores de reset e interrupci�n para la versi�n con bootloader
#org 0x0000,0x1FFF {}                             // Reserva espacio en memoria para el bootloader

int VALOR_ADC;                                    //Variable para almacenar el valor le�do del ADC

void main(void)
{
    setup_timer_2 (T2_DIV_BY_16, 254, 16);                       //Configura Timer2
    setup_ccp1 (CCP_PWM|CCP_SHUTDOWN_AC_L|CCP_SHUTDOWN_BD_L);    //Configura el m�dulo CCP para uso del PWM
    setup_adc_ports (sAN0);                                      //Configura solo el puerto A0 como entrada anal�gica
    setup_adc (ADC_CLOCK_INTERNAL);

     while (1)
          {
               set_adc_channel (0);                               //Selecciona el canal 0 para la conversi�n
               VALOR_ADC = read_adc ()*1.53;                      //Lee el valor del ADC y lo guarda en la variable
               set_pwm1_duty (VALOR_ADC);                         
          }
}
