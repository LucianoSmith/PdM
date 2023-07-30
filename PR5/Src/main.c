/*
  ******************************************************************************
  * @title   	Practica 5 - Ejercicios 1 y 2
  * @author  	Luciano M. Smith
  * @brief		utilización el módulo de uart para informar al usuario
  * 			cuando se producen los flancos ascendente y descendente.
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
*/

#include "main.h"
#include "API_delay.h"		// modulo con las funciones de delay
#include "API_debounce.h"	// modulo con las funciones antirebote

#define freq1 100
#define freq2 500

bool_t freq = true;

// inicio de estructuras de delay

delay_t dled2;


// estructura principal

int main(void)
{
  // inicialización de la capa de abstracción de hardware

  HAL_Init();

   // inicialización de los leds on-board

  BSP_LED_Init(LED2);
  BSP_LED_Init(LED1);

  // inicialización del boton del usuario

  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

  // inicialización del proceso de debounce

  debounceFSM_init();

  // incio de delays

  delayInit(&dled2, freq1);

  // enciende el led2

  BSP_LED_Toggle(LED2);


  // bucle infinito

  while (1) {

	  debounceFSM_update();

	  //uartReceiveStringSize((uint8_t *)&cc, 1);

	  //uartSendStringSize((uint8_t *)&cc, 1);

	  if (readKey()) {

		  if (freq) {
			  delayWrite(&dled2, freq2);
			  freq = false;
		  } else {
			  delayWrite(&dled2, freq1 );
			  freq = true;
		  }

	  }

	  if (delayRead(&dled2)) {
		  BSP_LED_Toggle(LED2);
	  }

  }

}

