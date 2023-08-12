/**
  ******************************************************************************
  * @file    	API_uart.h
  * @author  	Luciano M. Smith
  * @brief   	Librería para comunicaciones UART
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#ifndef __API_USART_H
#define __API_USART_H

#include <stdio.h>
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#include <stdbool.h>
#include <string.h>


typedef bool bool_t;


#define USARTx                           USART3
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART3_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART3_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART3_RELEASE_RESET()

/* Definition for USARTx Pins */

#define USARTx_TX_PIN                    GPIO_PIN_8
#define USARTx_TX_GPIO_PORT              GPIOD
#define USARTx_TX_AF                     GPIO_AF7_USART3
#define USARTx_RX_PIN                    GPIO_PIN_9
#define USARTx_RX_GPIO_PORT              GPIOD
#define USARTx_RX_AF                     GPIO_AF7_USART3

/**
  * @brief  Realiza  la inicialización de la UART e inmprime los parámetros de configuración.
  * @param  None
  * @retval true : si la inicialización es exitosa. false: si la inicialización no es exitosa.
  */

bool_t uartInit();

/**
  * @brief  Recibe un puntero a un string que se desea enviar por la UART completo (hasta el caracter ‘\0’)
  * @param  pstring : puntero al string que se desea imprimir.
  * @retval None
  */

void uartSendString(uint8_t * pstring);

#endif /* __API_USART_H */
