/**
  ******************************************************************************
  * @file    	API_osensor.h
  * @author  	Luciano M. Smith
  * @brief   	Librería para controlar los sensores ópticos
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#include "API_osensor.h"

/**
  * @brief  Inicializa los puertos que leen los sensores ópticos.
  * @param  None
  * @retval None
  */

void osensor_init(void) {

	__GPIOE_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_ENTERING | GPIO_EXITING;

	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

	GPIO_InitStruct.Pull = GPIO_PULLDOWN;

	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

}

/**
  * @brief  Lee el estado de un determinado sensor óptico.
  * @param  pos: la posición del sensor que se desea leer.
  * @retval res: true si el sensor esta detectando y false en caso contrario.
  */

bool osensor_status(uint8_t pos) {

	GPIO_PinState pinstatus;

	bool res = false;

	if (pos==entering){

		pinstatus = HAL_GPIO_ReadPin(GPIOE, GPIO_ENTERING);

	}

	if (pos==exiting) {

		pinstatus = HAL_GPIO_ReadPin(GPIOE, GPIO_EXITING);

	}

	if (pinstatus == GPIO_PIN_SET) res = true;

	return res;
}
