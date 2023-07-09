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

#define time1 100
#define time2 500
#define time3 1000

// inicio de estructuras de delay

delay_t dled1;
delay_t dled2;
delay_t dled3;

// estructura principal

int main(void)
{
  // inicialización de la capa de abstracción de hardware

  HAL_Init();

  // inicialización de los delays

  delayInit(&dled1, time1);
  delayInit(&dled2, time2);
  delayInit(&dled3, time3);

  // inicialización de los leds on-board

  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);

  // bucle infinito

  while (1) {
	  if (delayRead(&dled1)) {
		  BSP_LED_Toggle(LED1);
	  }
	  if (delayRead(&dled2)==true) {
		  BSP_LED_Toggle(LED2);
	  }
	  if (delayRead(&dled2)==true) {
		  BSP_LED_Toggle(LED3);
	  }
  }

}



