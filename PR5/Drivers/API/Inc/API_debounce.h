/**
  ******************************************************************************
  * @file    API_debounce.h
  * @author  Luciano M. Smith
  * @brief   Librería para manejar los rebotes de los pulsadores.
  ******************************************************************************
**/

#ifndef __DEBOUNCE_H
#define __DEBOUNCE_H

#include <stdio.h>
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#include <stdbool.h>
#include "API_delay.h"

typedef bool bool_t;

void debounceFSM_init();		// debe cargar el estado inicial
void debounceFSM_update();		// debe leer las entradas, resolver la lógica de
								// transición de estados y actualizar las salidas
bool readKey();					// Devuelve true si el pulsador se presiono

#endif /* __DEBOUNCE_H */
