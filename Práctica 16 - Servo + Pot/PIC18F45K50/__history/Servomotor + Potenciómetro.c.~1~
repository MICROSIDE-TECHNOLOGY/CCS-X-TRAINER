/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/


/*
---------------------------------------------------------------------------
Controlar la posición de un servomotor por medio de un potenciometro
utilizando los modulos PWM y ADC
---------------------------------------------------------------------------
*/

#include <18F45K50.h>                                  //Incluye el microcontrolador con el que se va a trabajar 
#device ADC=10                                         // Configura el ADC
#use delay(internal=48MHz)                             // Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)                // Asigna los vectores de reset e interrupción para la versión con bootloader

#org 0x0000,0x1FFF {}                                  // Reserva espacio en memoria para el bootloader

int16 Duty;                                            //variable para ajustar el valor del PWM
int1 SUBE;

#int_TIMER0

void TIMER0_isr()

{
output_high( PIN_C2);                                 
SUBE=1;
set_timer0(5780);                                    

}

void main()

{

  set_tris_c (0xFB);                                 //salida de pulsos
  setup_timer_0 (T0_INTERNAL|T0_DIV_4);
  enable_interrupts (int_TIMER0) ;
  enable_interrupts (GLOBAL) ;
  setup_adc_ports (sAN0);                            //configuracion deL canal ADC en A0
  setup_adc (ADC_CLOCK_INTERNAL);
  set_adc_channel (0);                               //conversion analogica por canal 0

    while(1)

         {

                if (SUBE == 1)

               {
                    delay_us (DUTY);
                    output_low (PIN_C2) ;
                     SUBE = 0;
                 }

                  if (SUBE == 0)
                      {
                          DUTY = read_adc ();              //lectura del potenciometro
                          DUTY = DUTY * 2;                 //ajuste de rango
                          DUTY += 500;
                          }

                           while (SUBE == 0) ;

                }

}
