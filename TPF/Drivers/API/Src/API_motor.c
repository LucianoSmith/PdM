/**
  ******************************************************************************
  * @file    	API_motor.c
  * @author  	Luciano M. Smith
  * @brief   	Librería para controlar el motor.
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#include "API_motor.h"

/**
  * @brief  Inicializa los puertos que utilizará el módulo que controla el motor.
  * @param  None
  * @retval None
  */

void motor_init(void) {

	__GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_ENA | GPIO_IN1 | GPIO_IN2;

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;

	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	HAL_GPIO_WritePin(GPIOC, GPIO_ENA, GPIO_PIN_RESET);		// inicia con motor apagado

}

/**
  * @brief  Envia las señales a los puertos que controlan el motor para realizar la apertura de la válvula.
  * @param  None
  * @retval None
  */

void motor_open(void){

	// ENA = true
	// IN1 = true
	// IN2 = false

	HAL_GPIO_WritePin(GPIOC, GPIO_ENA, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_IN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_IN2, GPIO_PIN_RESET);

}

/**
  * @brief  Envia las señales a los puertos que controlan el motor para realizar el cierre de la válvula.
  * @param  None
  * @retval None
  */

void motor_close(void){

	// ENA = true
	// IN1 = false
	// IN2 = true

	HAL_GPIO_WritePin(GPIOC, GPIO_ENA, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_IN1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_IN2, GPIO_PIN_SET);

}

/**
  * @brief  Envia las señales a los puertos que controlan el motor para frenar el motor.
  * @param  None
  * @retval None
  */


void motor_brake(void){

	// IN1 = true
	// IN2 = true
	// ENA = false

	HAL_GPIO_WritePin(GPIOC, GPIO_IN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_IN2, GPIO_PIN_SET);
	HAL_Delay(500);		// delay bloqueante necesario para frenar el motor antes de apagarlo.
	HAL_GPIO_WritePin(GPIOC, GPIO_ENA, GPIO_PIN_RESET);

}
