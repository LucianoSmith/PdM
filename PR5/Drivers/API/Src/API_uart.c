/**
  ******************************************************************************
  * @file    API_uart.c
  * @author  Luciano M. Smith
  * @brief   Librería para comunicaciones UART
  ******************************************************************************
**/

#include "API_uart.h"

UART_HandleTypeDef UartHandle;

#define timeOut 0xFFFF

// manejo de errores.

static void Error_Handler(void)
{
  // enciende el led 1 en caso de error
  BSP_LED_On(LED1);
  while (1)
  {
  }

}

/**
 * Realiza  la inicialización de la UART e inmprime los parámetros de configuración.
 * La función no recibe parámetros.
 * La función devuelve:
 * 		true : si la inicialización es exitosa.
 * 		false: si la inicialización no es exitosa.
**/

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
 * uartSendString: Recibe un puntero a un string que se desea enviar por la UART completo (hasta el caracter ‘\0’)
 * La función recibe:
 * 		pstring : puntero al string que se desea imprimir.
 * La función no retorna parámetros.
**/

void uartSendString(uint8_t* pstring) {

	// control de errores en los parámetros

	if (pstring == NULL)
		Error_Handler();

	uint8_t i = 0;

	while ( (*(pstring+i))!='\0' ) {

		HAL_StatusTypeDef status = HAL_UART_Transmit(&UartHandle, (uint8_t*)(pstring+i), 1, timeOut);

		if (status != HAL_OK) {
			Error_Handler();
		}

		i++;

	}

}

/**
 * uartSendStringSize: Recibe un puntero a un string y un entero con la cantidad de caracteres que se debe enviar por la UART.
 * La función recibe:
 * 		pstring : puntero al string que se desea enviar.
 * 		size : cantidad de caracteres que se desea enviar.
 * La función no retorna parámetros.
**/


void uartSendStringSize(uint8_t * pstring, uint16_t size) {


	// control de errores en los parámetros

	if (pstring == NULL || size == 0 )
		Error_Handler();

	HAL_StatusTypeDef status = HAL_UART_Transmit(&UartHandle, (uint8_t*)pstring, size, timeOut);

	if (status != HAL_OK) {
		Error_Handler();
	}
}

/**
 * uartReceiveStringSize: Recibe el puntero de un string y un entero con la cantidad de caracteres que se debe recibir.
 * La función recibe:
 * 		pstring : puntero al string que va a recibir.
 * 		size : cantidad de caracteres que se desea recibir.
 * La función no retorna parámetros.
**/

void uartReceiveStringSize(uint8_t * pstring, uint16_t size) {

	if (pstring == NULL || size == 0 )
		Error_Handler();

	HAL_StatusTypeDef status = HAL_UART_Receive(&UartHandle, (uint8_t*)pstring, size, timeOut);

	if (status != HAL_OK) {
		Error_Handler();
	}

}



