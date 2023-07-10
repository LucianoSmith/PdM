/*
  ******************************************************************************
  * @title   	Practica 3 - Ejercicio 1 - API_delay.c
  * @author  	Luciano M. Smith
  * @brief		Modulo con funciones de "delay"
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
  */

#include "API_delay.h"

// control de errores
static void Error_Handler(void) {

	// enciende el led rojo indicando error
	BSP_LED_Toggle(LED2);
	while(1) {
	}

}

// función de inicializacion del "delay"
void delayInit( delay_t * delay, tick_t duration ) {

	// control de errores en los parámetros

	if (delay == NULL || duration == 0 )
		Error_Handler();

	delay->running = false;
	delay->duration = duration;
	delay->on = true;

}

// función de comprobación/lectura del "delay"
bool_t delayRead( delay_t * delay ) {

	bool_t ret = false;	// variable de retorno

	// control de errores en los parámetros

	if (delay == NULL)
		Error_Handler();


	if (delay->on) {
		if (delay->running==false) {
			delay->startTime = HAL_GetTick();
			delay->running = true;

		} else {

			if ((HAL_GetTick() - delay->startTime) >= delay->duration) {
				delay->running = false;
				ret = true;
			}
		}
	}

	return ret;
}

// función para el cambio de duración del "delay"
void delayWrite( delay_t * delay, tick_t duration ) {
	delay->duration = duration;
}

void delayTurn( delay_t * delay, bool_t status ) {

	// control de errores en los parámetros

	if (delay == NULL)
		Error_Handler();

	delay->on = status;
	delay->running = false;


}

