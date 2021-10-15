/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
Implementar corrimiento de 8 bits y desplegar el resultado en 8 LEDs
---------------------------------------------------------------------------
*/

#include <18F45K50.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(internal=48MHz)                       //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)          //Asigna los vectores de reset e interrupción para la versión con bootloader
#org 0x0000,0x1FFF {}                            //Reserva espacio en memoria para el bootloader

byte MI_REGISTRO;                                //Variable de 8 bits(1 byte)

int i;

void SisInit(void)

{
     set_tris_b (0x00);                          //Configura puerto B como salidas
     MI_REGISTRO = 0x0D;                         //Se inicia cargando los bits deseados
}

void main (void)

{
   SisInit();

   while (true)

       {
            MI_REGISTRO = ((MI_REGISTRO <<1)|(MI_REGISTRO>>7));     //Inicia corrimiento
            output_b (MI_REGISTRO);                                 //Pasa el valor al puerto B
            delay_ms (500);
        } 
}
