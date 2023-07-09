/*
  ******************************************************************************
  * @title   	Practica 2 - Ejercicio 1
  * @author  	Luciano M. Smith
  * @brief		Programa que parpadea leds a distintas velocidades sin bloquear
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
  */

#include "main.h"

// tiempos de parpadeo

#define time1 100
#define time2 500
#define time3 1000

// inicio de estructuras de delay

delay_t dled1;
delay_t dled2;
delay_t dled3;

// control de errores

static void Error_Handler(void) {

	// enciende el led rojo

	BSP_LED_Toggle(LED2);
	while(1) {
	}

}

// función de inicializacion del "delay"

void delayInit( delay_t * delay, tick_t duration ) {

	// control de errores en los parámetros

	if (delay == NULL || duration <= 0 )
		Error_Handler();

	delay->running = false;
	delay->duration = duration;

}

// función de comprobación/lectura del "delay"

bool_t delayRead( delay_t * delay ) {

	bool_t ret = false;	// variable de retorno

	// control de errores en los parámetros

	if (delay == NULL)
		Error_Handler();

	if (delay->running==false) {
		delay->startTime = HAL_GetTick();
		delay->running = true;

	} else {

		if ((HAL_GetTick() - delay->startTime) >= delay->duration) {
			delay->running = false;
			ret = true;
		}
	}

	return ret;
}

// función para el cambio de duración del "delay"

void delayWrite( delay_t * delay, tick_t duration ) {
	delay->duration = duration;
}

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



