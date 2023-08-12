/**
  ******************************************************************************
  * @file    	API_psensor.h
  * @author  	Luciano M. Smith
  * @brief   	Librería para controlar los sensores de posición de la válvula
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#include "API_psensor.h"

/**
  * @brief  Inicializa los puertos que leen los sensores de posición.
  * @param  None
  * @retval None
  */

void psensor_init(void) {

	__GPIOE_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_OPEN | GPIO_CLOSE;

	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

	GPIO_InitStruct.Pull = GPIO_PULLDOWN;

	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

}

/**
  * @brief  Lee la posición de la válvula por medio de los sensores magnéticos
  * @param  None
  * @retval res: devuelve la posición de la válvula (open, close, undefined)
  */

uint8_t psensor_status(void) {

	GPIO_PinState pinstatus;

	uint8_t res = undefined;

	pinstatus = HAL_GPIO_ReadPin(GPIOE, GPIO_OPEN);

	if (pinstatus == GPIO_PIN_SET) res = open;

	else {

		pinstatus = HAL_GPIO_ReadPin(GPIOE, GPIO_CLOSE);

		if (pinstatus == GPIO_PIN_SET) res = close;
	}

	return res;
}
