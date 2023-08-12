/**
  ******************************************************************************
  * @file    	API_motor.h
  * @author  	Luciano M. Smith
  * @brief   	Modulo con funciones de "delay"
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#include "API_delay.h"

/**
  * @brief  función de inicializacion del "delay"
  * @param  delay: estructura delay / duration: duración del delay
  * @retval None
  */

void delayInit( delay_t * delay, tick_t duration ) {

	delay->running = false;
	delay->duration = duration;

}

/**
  * @brief  función de comprobación/lectura del "delay"
  * @param  delay: estructura delay que se quiere leer
  * @retval ret: true si ha vencido el tiempo del delay
  */

bool_t delayRead( delay_t * delay ) {

	bool_t ret = false;	// variable de retorno

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

/**
  * @brief  función para el cambio de duración del "delay"
  * @param  delay: estructura delay / duration: duración del delay
  * @retval none
  */

void delayWrite( delay_t * delay, tick_t duration ) {
	delay->duration = duration;
}

/**
 * @brief  función para comenzar el conteo del "delay"
 * @param  delay: estructura delay
 * @retval none
 */

void delayStart(delay_t * delay) {
	delay->startTime = HAL_GetTick();
	delay->running = true;
}
