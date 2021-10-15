/************************************************************************************************
Company:
Microside Technology Inc.

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/
/**************************************************************************
Esta practica consiste en realizar un control PWM
para regular la luminosidad de un led
**************************************************************************/

#include <18F45K50.h>                    //Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay(internal=48MHz)              //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)//Asigna los vectores de reset e interrupción para la versión con bootloader
#org 0x0000,0x1FFF {}                 //Reserva espacio en memoria para el bootloader

unsigned int16 Duty=0;         //Variable para guardar el valor para PWM

void main()
{
   setup_timer_2 (T2_DIV_BY_16, 254, 1); //Configura Timer2, periodo ajustado a 342uS
   setup_ccp1 (CCP_PWM|CCP_SHUTDOWN_AC_L|CCP_SHUTDOWN_BD_L); //Configura el módulo CCP para uso del PWM

   while (TRUE)
   {
      
      for (Duty = 0; Duty < 255; Duty++)
      {
         set_pwm1_duty (Duty); //Asigna el valor del Duty al PWM
         delay_ms (5); //Retardo de 5ms
      }

      
      for (Duty = 255; Duty > 0; Duty--) // Ciclo para disminuir el valor de la variable
      {
         set_pwm1_duty (Duty); //Asigna el valor del Duty al PWM
         delay_ms (5); // Retardo de 5ms
      }
   }
}

