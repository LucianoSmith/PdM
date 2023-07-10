/*
  ******************************************************************************
  * @title   	Practica 3 - Ejercicio 1
  * @author  	Luciano M. Smith
  * @brief		Programa que parpadea leds a distintas velocidades sin bloquear
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
  */

#include "main.h"
#include "API_delay.h"		// modulo con las funciones de delay

// tiempos de parpadeo

#define timeOff 500
#define timeOn 200
#define timeBig 999

// inicio de estructuras de delay

delay_t dOn;
delay_t dOff;

// estructura principal

int main(void)
{
  // inicialización de la capa de abstracción de hardware

  HAL_Init();

  // inicialización de los delays

  delayInit(&dOn, timeOn);
  delayInit(&dOff, timeOff);

  int i = 0;

  // inicialización de los leds on-board

  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);

  // bucle infinito

  while (1) {

	  if (delayRead(&dOff)) {

		  BSP_LED_On(i);				// enciende el led i

		  delayTurn( &dOff, false);		// apaga el timer off

		  delayTurn( &dOn, true);		// inicia el timmer On

	  }
	  if (delayRead(&dOn)) {

		  BSP_LED_Off(i);				// apaga el led i

		  delayTurn( &dOn, false);		// apaga el timer on

		  delayTurn( &dOff, true);		// inicia el timmer Off

		  i++;							// actualiza el contador de leds

		  if (i>2) i=0;

	  }

  }

}



