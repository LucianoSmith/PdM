/**
  ******************************************************************************
  * @file    API_debounce.c
  * @author  Luciano M. Smith
  * @brief   Librería para manejar los rebotes de los pulsadores.
  ******************************************************************************
**/

#include "API_debounce.h"
#include "API_uart.h"

// Creación de estados

typedef enum {
	button_up,
	button_falling,
	button_down,
	button_raising,
} debounceState_t;


static debounceState_t s_button1;	// variable estado actual

bool_t falling = false;
bool_t pressed = false;	// varible que avisa si el pulsador fue presionado

// tiempo de verificación de debounce

#define timeDebounce 40

// inicio de estructuras de delay debounce

delay_t d_timer;

static char fd[] = "flanco descendente\r\n";
static char fa[] = "flanco ascendente\r\n";

// Funcion readKey. Devuelve true si el pulsador esta presionado.

bool readKey() {
	bool_t ret = false;

	if (pressed) {
		ret = true;
		pressed = false;
	}

	return ret;
}

// Carga el estado inicial. No retorna valores.

void debounceFSM_init() {

	s_button1 = button_up;

	// inicialización de los delays

	delayInit(&d_timer, timeDebounce);
	BSP_LED_Init(LED3);

	// inicialización de la comunicación UART

	uartInit();

}

// lee las entradas, resuelve la lógica de transición de estados y actualiza las salidas. No retorna valores.

void debounceFSM_update() {


	switch (s_button1) {

		case button_up:

			if(BSP_PB_GetState(BUTTON_USER)){

				// flanco desendente

				s_button1 = button_falling;
				falling = true;

				uartSendString((uint8_t*)&fd);

				delayRead(&d_timer);

			}

		break;

		case button_falling:

			if (BSP_PB_GetState(BUTTON_USER)) {

				if(BSP_PB_GetState(BUTTON_USER)){
					s_button1 = button_down;
					d_timer.running = false;
					pressed = true;
				} else {
					s_button1 = button_up;
				}

			}

		break;

		case button_down:

			if(!BSP_PB_GetState(BUTTON_USER)){

				// flanco ascendente

				s_button1 = button_raising;

				uartSendStringSize((uint8_t*)&fa, strlen(fa));

				delayRead(&d_timer);

			}

		break;

		case button_raising:

			if (delayRead(&d_timer)) {

				if(!BSP_PB_GetState(BUTTON_USER)){
					s_button1 = button_up;
					d_timer.running = false;
				} else {
					s_button1 = button_down;
				}

			}
		break;

		default:

			BSP_LED_On(LED3); 	// error no encuentra estado

			while (1) {

			}
		break;
	}

}
