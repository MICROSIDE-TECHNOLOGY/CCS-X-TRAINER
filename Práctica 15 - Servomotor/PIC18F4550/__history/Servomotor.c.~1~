/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
Controlar la posicíon de un servo por medio del módulo PWM interno
---------------------------------------------------------------------------
*/

#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versión con bootloader

int16 DUTY;                                     //variable para ajustar el valor del PWM
int1 SUBE;
int i;

void SisInit()
{
  set_tris_c(0xFB);                                 // C2 salida
  setup_timer_0(T0_INTERNAL|T0_DIV_4);
  enable_interrupts(INT_TIMER0);
  enable_interrupts(GLOBAL);

}

#int_TIMER0

 
void TIMER0_isr(){
output_high(PIN_C2);                              //Salida Pin_C2
SUBE=1;
set_timer0(5780);                                

}

void main()
{
        SisInit();
        while(1)
              {

                    for(i=0;i<255;i++)
                         {
                             if(SUBE==1)
                             {
                                delay_us(500);     //0°
                                 output_low( PIN_C2);
                                 SUBE=0;
                              }
                                while(SUBE==0);
                            }

                      for(i=0;i<255;i++)
                           {
                              if(SUBE==1)
                               {
                                  delay_us(1500);  //90°
                                   output_low( PIN_C2);
                                   SUBE=0;
                                }
                                while(SUBE==0);
                          } 

                        for(i=0;i<255;i++)
                               {
                                  if(SUBE==1)
                                  {
                                      delay_us(2500); //180°
                                      output_low( PIN_C2);
                                       SUBE=0;
                                   }
                                  while(SUBE==0);
                                    }

                 }
}
