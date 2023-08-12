/**
  ******************************************************************************
  * @file    	API_uart.c
  * @author  	Luciano M. Smith
  * @brief   	Librería para comunicaciones UART
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#include "API_uart.h"

UART_HandleTypeDef UartHandle;

#define timeOut 0xFFFF

/**
  * @brief  Realiza  la inicialización de la UART e inmprime los parámetros de configuración.
  * @param  None
  * @retval true : si la inicialización es exitosa. false: si la inicialización no es exitosa.
  */

bool_t uartInit() {

	bool_t ret = true;

	UartHandle.Instance        = USARTx;
	UartHandle.Init.BaudRate   = 9600;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits   = UART_STOPBITS_1;
	UartHandle.Init.Parity     = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode       = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;

	if (HAL_UART_Init(&UartHandle) != HAL_OK) {
		ret = false;
	} else {

		// Envia los parametros por puerto serie;

		uartSendString((uint8_t*)&"BaudRate         : 9600\r\n");
		uartSendString((uint8_t*)&"WordLength       : 8\r\n");
		uartSendString((uint8_t*)&"StopBits         : 1\r\n");
		uartSendString((uint8_t*)&"Hardware Control : None\r\n");
		uartSendString((uint8_t*)&"Mode             : TX/RX\r\n");
		uartSendString((uint8_t*)&"OverSampling     : 16\r\n\r\n");

	}

	return ret;
}

/**
  * @brief  Recibe un puntero a un string que se desea enviar por la UART completo (hasta el caracter ‘\0’)
  * @param  pstring : puntero al string que se desea imprimir.
  * @retval None
  */

void uartSendString(uint8_t* pstring) {

	uint8_t i = 0;

	while ( (*(pstring+i))!='\0' ) {

		HAL_UART_Transmit(&UartHandle, (uint8_t*)(pstring+i), 1, timeOut);

		i++;

	}

}


