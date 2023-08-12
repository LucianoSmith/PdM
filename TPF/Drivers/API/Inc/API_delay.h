/**
  ******************************************************************************
  * @file    	API_motor.h
  * @author  	Luciano M. Smith
  * @brief   	Modulo con funciones de "delay"
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#ifndef __API_DELAY_H
#define __API_DELAY_H

#include <stdio.h>
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#include <stdbool.h>

typedef uint32_t tick_t;

typedef bool bool_t;

typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

/**
  * @brief  función de inicializacion del "delay"
  * @param  delay: estructura delay / duration: duración del delay
  * @retval None
  */

void delayInit( delay_t * delay, tick_t duration );

/**
  * @brief  función de comprobación/lectura del "delay"
  * @param  delay: estructura delay que se quiere leer
  * @retval ret: true si ha vencido el tiempo del delay
  */

bool_t delayRead( delay_t * delay );

/**
  * @brief  función para el cambio de duración del "delay"
  * @param  delay: estructura delay / duration: duración del delay
  * @retval none
  */

void delayWrite( delay_t * delay, tick_t duration );

/**
 * @brief  función para comenzar el conteo del "delay"
 * @param  delay: estructura delay
 * @retval none
 */

void delayStart(delay_t * delay);


#endif /* __API_DELAY_H */
