/************************************************************************************************
Company:
Microside Technology Inc.

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/**************************************************************************
Esta práctica consiste en realizar una medicion de distancia a través de un 
sensor ultrasonico, e imprimir la lectura en una pantalla LCD
**************************************************************************/

#include  <18F45K50.h>                          // Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay(internal=48MHz)                    // Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)      // Asigna los vectores de reset e interrupción para la versión con Bootloader
#org 0x0000,0x1FFF {}                       // Reserva espacio en memoria para el Bootloader 

//CONFIGURACION DE PINES LCD
#define LCD_RS PIN_B0      //CONTROL del LCD
#define LCD_RW PIN_B1
#define LCD_E  PIN_B2
#define LCD_DB4 PIN_B3    //DATOS del LCD (4 lineas)
#define LCD_DB5 PIN_B4
#define LCD_DB6 PIN_B5
#define LCD_DB7 PIN_B6
#include "flex_lcd.h"     //LIBRERIA LCD
#define trig pin_C1     // Conectar al entrenador el pin "TRIGGER" del sensor ultrasónico
#define echo pin_C0     // Conectar al entrenador el pin "ECHO" del sensor ultrasónico

int16 distancia, vtimer1;  // Variables para calculo de distancia y valor de tiempo de TIMER1

float tiempo;    //variable para calcular tiempo en segundos
float const usxtick = 0.6;  //variable con valor por cada incremento en el TIMER1

void main()
{
   output_low (echo);
   setup_timer_1 (T1_INTERNAL|T1_DIV_BY_8); // Se configura TIMER1 para medir tiempo
   lcd_init ();  //Inicialización del lcd.
   
   while (1)
   {
      output_high (trig); // Envía pulso alto al pin TRIGGER del sensor
      delay_us (100);  // Mantiene pulso 100uS.
      output_low (trig); // Desactiva pulso
      delay_us (350);
      while ( ! input (echo)){} // Espera por estado alto del pin ECHO del sensor ultrasónico
      set_timer1 (0); // Ajusta el Timer1 a 0
      while (input (echo)){} // Espera por estado bajo del pin ECHO del sensor ultrasónico
      vtimer1 = get_timer1 (); // Obtiene el tiempo que se mantuvo en alto el pulso del pin TRIGGER leyendo el valor de Timer1
      tiempo = vtimer1 * usxtick; //Calcula tiempo en Segs
      distancia = vtimer1 * 0.012 + 1.093; // Calcula la distancia en cm
      
                  
      delay_ms(200);            
      printf(lcd_putc,"\fDistancia \n%Lu cm",distancia);      //Envia valor de distancia hacia un LCD conectado al PIC   
             
   }
}

