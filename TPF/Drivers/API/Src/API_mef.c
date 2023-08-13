/**
  ******************************************************************************
  * @file    	API_mef.c
  * @author  	Luciano M. Smith
  * @brief   	Librería para manejar la maquina de estados finitos.
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#include "API_mef.h"

static delay_t dledR;									// delay para el parpadeo del led rojo
static delay_t dtimeOut1;								// delay para el timeout 1.
static delay_t dtimeOut2;								// delay para el timeout 2
static delay_t dtimeOut3;								// delay para el timeout 3

static MEFState_t MEFState;								// variable estado actual

/**
  * @brief  Inicializa la máquina de estados y todos sus perifericos.
  * @param  None
  * @retval None
  */

void MEF_init() {										// Carga el estado inicial. No retorna valores.

	MEFState = starting;

	delayInit(&dledR, led_blink);						// inicialización del delay para parpadeo de led

	delayInit(&dtimeOut1, t1);							// inicialización del delay para el vencimiento del timeout 1

	delayInit(&dtimeOut2, t2);							// inicialización del delay para el vencimiento del timeout 2

	delayInit(&dtimeOut3, t3);							// inicialización del delay para el vencimiento del timeout 3

	BSP_LED_Init(ledV);									// inicializa led rojo

	BSP_LED_Init(ledR); 								// inicializa led verde

	uartInit();											// inicialización de la comunicación UART

	motor_init();										// inicialización el control del motor

	psensor_init();										// inicialización de los sensores de posición

	osensor_init();										// inicialización de los sensores ópticos

	BSP_LED_On(ledV);									// enciende led verde

	uartSendString((uint8_t*)&"Starting ... \r\n");

}

/**
  * @brief  Lee las entradas, resuelve la lógica de transición de estados y actualiza las salidas.
  * @param  None
  * @retval None
  */

void MEF_update() {

	switch (MEFState) {

		case starting:

			if (psensor_status() == close) {			// verifica posición de la valvula

				MEFState = closed_gate;					// valvula cerrada

				uartSendString((uint8_t*)&"Valve closed.\r\n");

			} else {

				delayStart(&dtimeOut3);					// activa tiempo de timeout 3

				motor_close(); 							// motor cerrando

				MEFState = closing_gate;				// cambia el estado a cerrando

				uartSendString((uint8_t*)&"Open or undefined valve position. Trying to close ... \r\n");

			}

			break;

		case closing_gate:

			if (delayRead(&dledR)) {

			  BSP_LED_Toggle(ledR);						// blink led rojo

			}

			if (psensor_status() == close) {			// verifica posición del sensor

				motor_brake(); 							// si alcanzo la posición frena motor

				BSP_LED_Off(ledR);						// apaga led rojo

				MEFState = closed_gate;					// siguiente estado

				uartSendString((uint8_t*)&"Valve closed.\r\n");
			}

			// se vence time out 3

			if (delayRead(&dtimeOut3) && (MEFState != closed_gate)) {

				motor_brake(); 							// frena motor

				MEFState = error_state;					// pasa a error

				uartSendString((uint8_t*)&"Timeout (3). Can't find the position.\r\n");

			}

			break;

		case closed_gate:

			if (psensor_status() != close) {

				delayStart(&dtimeOut3);					// activa tiempo de timeout 3

				motor_close(); 							// motor cerrando

				MEFState = closing_gate;				// cambia el estado a cerrando

				uartSendString((uint8_t*)&"Undefined valve position. Trying to close ... \r\n");

			} else {

				if (osensor_status(entering)) { 		// sensa el sensor óptico de entrada

					delayStart(&dtimeOut1);				// activa tiempo de timeout 1

					MEFState = carrier_entering;		// cambia de estado a contenedor entrando

					uartSendString((uint8_t*)&"Carrier entering!\r\n");

				}
			}

			break;

		case carrier_entering:

			if (delayRead(&dtimeOut1)) {				// Al vencer el contador t1, vuelve a chequear si el contenedor contenedor aún
														// se encuentra en la entrada a fin de evitar falsas detecciones

				if (osensor_status(entering)) { 		// si esta el contenedor entonces

					delayStart(&dtimeOut3);				// activa delay de posicion de valvula

					motor_open(); 						// activa motor direccion apertura

					MEFState = opennig_gate;			// cambia de estado a abriendo valvula

					uartSendString((uint8_t*)&"Carrier detected. Openning valve ... \r\n");

				} else {

					BSP_LED_Off(ledR);					// apaga led rojo

					MEFState = closed_gate;				// pasa al estado valvula cerrada

					uartSendString((uint8_t*)&"Timeout (1). Carrier not detected. Valve closed.\r\n");

				}

			}

			break;

		case opennig_gate:

			if (delayRead(&dledR)) {

			  BSP_LED_Toggle(ledR);						// blink led rojo

			}

			if (psensor_status() == open) {				// verifica posición del sensor

				motor_brake(); 							// si alcanzo la posición frena motor

				BSP_LED_Off(ledR);						// apaga led rojo

				MEFState = open_gate;					// siguiente estado

				uartSendString((uint8_t*)&"Valve open.\r\n");
			}

			// se vence time out 3

			if (delayRead(&dtimeOut3) && (MEFState != open_gate)) {

				motor_brake(); 							// frena motor

				MEFState = error_state;					// pasa a error

				uartSendString((uint8_t*)&"Timeout (3). Can't find the position.\r\n");

			}

			break;

		case open_gate:

			if (psensor_status() != open) {

				delayStart(&dtimeOut3);					// activa tiempo de timeout 3

				motor_open(); 							// motor abriendo

				MEFState = opennig_gate;				// cambia el estado a abriendo

				uartSendString((uint8_t*)&"Openning ... \r\n");

			} else {

				if (osensor_status(exiting)) { 			// sensa el sensor óptico de salida

					delayStart(&dtimeOut2);				// activa tiempo de timeout 2

					MEFState = carrier_exiting;

					uartSendString((uint8_t*)&"Carrier exiting ... \r\n");

				}
			}

			break;

		case carrier_exiting:

			if (delayRead(&dtimeOut2)) {				// Al vencer el contador t2, vuelve a chequear si el contenedor no
														// se encuentra en la salida a fin de cerrar la valvula y dañar el contenedor

				if (!osensor_status(exiting)) { 		// sensa el sensor óptico de salida

					delayStart(&dtimeOut3);				// activa tiempo de timeout 3

					motor_close(); 						// motor cerrando

					MEFState = closing_gate;			// cambia el estado a cerrando

					uartSendString((uint8_t*)&"Confirmed carrier passed. Closing valve ... \r\n");

				} else {

					MEFState = error_state;				// cambia el estado a error

					uartSendString((uint8_t*)&"Timeout (2). Carrier still detected/blocked.\r\n");

				}
			}

			break;

		case error_state:

			BSP_LED_Off(ledV);							// apaga led verde

			BSP_LED_On(ledR); 							// enciende led rojo

			uartSendString((uint8_t*)&"Error. Please, check the valve and reset.\r\n");

			while (1) {

			}

			break;

		default:

			uartSendString((uint8_t*)&"Undefined internal state ... \r\n");

			MEFState = error_state;

			break;

	}

}
