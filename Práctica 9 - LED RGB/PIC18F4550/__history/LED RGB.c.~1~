/* 
 AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
 FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
Esta práctica consiste en realizar un control PWM
para el control de un LED RGB
---------------------------------------------------------------------------
*/

#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versión con bootloader

#define LEDR PIN_B0                             //Pin donde está conectado el LED rojo
#define LEDV PIN_B1                             //Pin donde está conectado el LED verde
#define LEDA PIN_B2                             //Pin donde está conectado el LED azul

unsigned int16 Duty=0;                          //Variable para guardar el valor para PWM

void SisInit(void)

{
   setup_timer_2 (T2_DIV_BY_16, 254, 1);                        //Configura Timer2, periodo ajustado a 342uS
   setup_ccp1 (CCP_PWM|CCP_SHUTDOWN_AC_L|CCP_SHUTDOWN_BD_L);    //Configura el módulo CCP para uso del PWM
}

void Set_PWM (void)

{

  // int i;                                                       //Declaramos variable
   for (Duty = 255; Duty > 0; Duty--)                             // Ciclo para disminuir el valor de la variable

   {
    set_pwm1_duty (Duty);                                         // Guarda la salida PWM en la variable
    delay_ms (5);                                                 // Retardo
    }

    for (Duty = 0; Duty < 255; Duty++)                            // Ciclo para aumentar el valor de la variable

    {
     set_pwm1_duty (Duty);                                        // Guarda la salida PWM en la variable
     delay_ms (5);                                                // Retardo
   }

}

void main()

{

   SisInit();

    while (1)                                                   // Ciclo infinito

     {

       output_high (LEDR) ;
       output_low (LEDV) ;
       output_low (LEDA) ;

       Set_PWM ();                                              // Convocamos la función

       output_low (LEDR) ;
       output_high (LEDV) ;
       output_low (LEDA) ;

       Set_PWM ();                                              // Convocamos la función

       output_low (LEDR) ;
       output_low (LEDV) ;
       output_high (LEDA) ;

       Set_PWM ();                                              // Convocamos la función

     }

}
