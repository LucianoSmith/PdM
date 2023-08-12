/**
  ******************************************************************************
  * @file    	API_osensor.h
  * @author  	Luciano M. Smith
  * @brief   	Librería para controlar los sensores ópticos
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#ifndef __API_OSENSOR_H
#define __API_OSENSOR_H

#include <stdio.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"

#define entering 	0
#define exiting 	1

#define GPIO_ENTERING 		GPIO_PIN_13
#define GPIO_EXITING 		GPIO_PIN_14

/**
  * @brief  Inicializa los puertos que leen los sensores ópticos.
  * @param  None
  * @retval None
  */

void osensor_init(void);

/**
  * @brief  Lee el estado de un determinado sensor óptico.
  * @param  pos: la posición del sensor que se desea leer.
  * @retval res: true si el sensor esta detectando y false en caso contrario.
  */

bool osensor_status(uint8_t pos);

#endif /* __API_OSENSOR_H */
