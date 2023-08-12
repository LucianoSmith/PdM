/**
  ******************************************************************************
  * @file    	API_psensor.h
  * @author  	Luciano M. Smith
  * @brief   	Librería para controlar los sensores de posición de la válvula
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#ifndef __API_PSENSOR_H
#define __API_PSENSOR_H

#include <stdio.h>
#include "stm32f4xx_hal.h"

#define open 		0
#define close 		1
#define undefined 	2

#define GPIO_OPEN 		GPIO_PIN_9
#define GPIO_CLOSE 		GPIO_PIN_11

/**
  * @brief  Inicializa los puertos que leen los sensores de posición.
  * @param  None
  * @retval None
  */

void psensor_init(void);

/**
  * @brief  Lee la posición de la válvula por medio de los sensores magnéticos
  * @param  None
  * @retval res: devuelve la posición de la válvula (open, close, undefined)
  */

uint8_t psensor_status(void);

#endif /* __API_PSENSOR_H */
