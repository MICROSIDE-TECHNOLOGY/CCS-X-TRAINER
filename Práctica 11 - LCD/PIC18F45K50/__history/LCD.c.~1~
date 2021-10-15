/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
Esta práctica consiste en imprimir un mensaje, a través de una
pantalla LCD
---------------------------------------------------------------------------
*/

#include <18F45K50.h>                               //Incluye el microcontrolador con el que se va a trabajar 
#use delay(internal=48MHz)                          // Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)             // Asigna los vectores de reset e interrupción para la versión con bootloader
#org 0x0000,0x1FFF {}                               // Reserva espacio en memoria para el bootloader

/*
------------------------------------------------------------------------------
CONFIGURACION DE PINES LCD
------------------------------------------------------------------------------
*/

#define LCD_RS PIN_B0                           //CONTROL del LCD
#define LCD_RW PIN_B1
#define LCD_E PIN_B2
#define LCD_DB4 PIN_B3                          //DATOS del LCD (4 lineas)
#define LCD_DB5 PIN_B4
#define LCD_DB6 PIN_B5
#define LCD_DB7 PIN_B6

#include "flex_lcd.h"                           //LIBRERIA LCD

void main()

{
       lcd_init ();                             // Inicialización del lcd.
       delay_ms (50) ;

        while(1)

           {
                printf (lcd_putc, "   MICROSIDE");    //Entre comillas escribimos el mensaje a mostrar
                delay_ms (2000);
               
                lcd_gotoxy (1, 2);                    //Segundo renglón
                printf (lcd_putc, "   TECHNOLOGY");   //Entre comillas escribimos el mensaje a mostrar
                delay_ms (2000);

                lcd_gotoxy (1, 1);                    //regresa cursor al inicio
                lcd_init ();                          //limpia display
                delay_ms (1000);

                printf (lcd_putc, "  BIENVENIDOS");   //Entre comillas escribimos el mensaje a mostrar
                delay_ms (2000);

                lcd_init ();                          //limpia display
                delay_ms (2000);

          }

}
