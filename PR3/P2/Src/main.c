/*
  ******************************************************************************
  * @title   	Practica 3 - Ejercicio 2
  * @author  	Luciano M. Smith
  * @brief	Programa que secuencia leds con retardos no bloqueantes
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
  */

#include "main.h"
#include "API_delay.h"		// modulo con las funciones de delay

// tiempos de parpadeo

#define timeLed 200

// inicio de estructuras de delay

delay_t dLed;

// estructura principal

int main(void)
{
  // inicialización de la capa de abstracción de hardware

  HAL_Init();

  // inicialización de los delays

  delayInit(&dLed, timeLed);

  int i = 0;			// control de la secuencia de leds
  bool enc = false;		// indicador de led encendido

  // inicialización de los leds on-board

  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);

  // bucle infinito

  while (1) {

	  if (delayRead(&dLed)) {
		  if (enc) {

			  BSP_LED_Off(i);				// apaga el led i

			  enc = false;

			  i++;							// va al siguiente led
			  if (i>2) i=0;

		  } else {

			  BSP_LED_On(i);				// enciende el led i
			  enc = true;

		  }
	  }


  }

}



