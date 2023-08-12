/**
  ******************************************************************************
  * @file    	API_motor.h
  * @author  	Luciano M. Smith
  * @brief   	Librería para controlar el motor.
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/
#ifndef __API_MOTOR_H
#define __API_MOTOR_H

#include "stm32f4xx_hal.h"

#define GPIO_ENA GPIO_PIN_8
#define GPIO_IN1 GPIO_PIN_9
#define GPIO_IN2 GPIO_PIN_10

/**
  * @brief  Inicializa los puertos que utilizará el módulo que controla el motor.
  * @param  None
  * @retval None
  */

void motor_init(void);

/**
  * @brief  Envia las señales a los puertos que controlan el motor para realizar la apertura de la válvula.
  * @param  None
  * @retval None
  */

void motor_open(void);

/**
  * @brief  Envia las señales a los puertos que controlan el motor para realizar el cierre de la válvula.
  * @param  None
  * @retval None
  */

void motor_close(void);

/**
  * @brief  Envia las señales a los puertos que controlan el motor para frenar el motor.
  * @param  None
  * @retval None
  */

void motor_brake(void);

#endif /* __API_MOTOR_H */
