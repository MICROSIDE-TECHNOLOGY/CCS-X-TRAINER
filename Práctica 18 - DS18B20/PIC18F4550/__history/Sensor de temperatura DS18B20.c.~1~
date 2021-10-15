/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
------------------------------------------------------------------------------
Esta práctica consiste en realizar la medición de temperatura por medio de un
sensor DS18B20 e imprimir la lectura en una pantalla LCD
------------------------------------------------------------------------------
*/

#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versión con bootloader

/*
------------------------------------------------------------------------------
CONFIGURACION DE PINES LCD
------------------------------------------------------------------------------
*/

#define LCD_RS PIN_B0                           //CONTROL del LCD
#define LCD_RW PIN_B1
#define LCD_E PIN_B2
#define LCD_DB4 PIN_B3                          //DATOS del LCD (4 líneas)
#define LCD_DB5 PIN_B4
#define LCD_DB6 PIN_B5
#define LCD_DB7 PIN_B6



#define DS1820_PIN PIN_A0                       //Se define pin como entrada digital para leer datos del sensor DS18B20
#define ONE_WIRE_PIN DS1820_PIN


#include<1wire.c>                               //Se incluyen las librerías correspondientes para el manejo del protocolo 1WIRE
#include<ds1820.c>                              //Se incluye la librería del driver para el manejo del sensor DS18B20

#include "flex_lcd.h"                           //LIBRERÍA LCD

float temperatura;                              //Variable


void main(void)

{
    port_b_pullups(0xff);
    lcd_init();                                 // Comandos de inicialización del lcd.
    delay_ms(50);


    while (TRUE)

        {
           temperatura = ds1820_read();                             //Lee el sensor
           printf(lcd_putc,"\fTemperatura \n%3.1fC", temperatura);  //Imprime en display
           delay_ms(1000);

       }

}
