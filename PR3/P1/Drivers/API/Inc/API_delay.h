/*
  ******************************************************************************
  * @title   	Practica 3 - Ejercicio 1 - API_delay.h
  * @author  	Luciano M. Smith
  * @brief		Modulo con funciones de "delay"
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
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

void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );

