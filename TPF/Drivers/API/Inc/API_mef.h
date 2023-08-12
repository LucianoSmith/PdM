/**
  ******************************************************************************
  * @file    	API_mef.h
  * @author  	Luciano M. Smith
  * @brief   	Librería para manejar la maquina de estados finitos.
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#ifndef __API_MEF_H
#define __API_MEF_H

#include "API_psensor.h"								// manejo de los sensores de position
#include "API_osensor.h"								// manejo de los sensores opticos
#include "API_motor.h"									// control del motor
#include "API_uart.h"									// manejo de las comunicaciones UART
#include "API_delay.h"									// manejo de los delays no bloqueantes

// Creación de estados

typedef enum {

	starting,
	closed_gate,
	closing_gate,
	open_gate,
	opennig_gate,
	error_state,
	carrier_entering,
	carrier_exiting,

} MEFState_t;

#define open 		0
#define close 		1
#define undefined 	2

#define entering 	0
#define exiting 	1

#define led_blink 	300
#define t1 			5000								// tiempo para volver a verificar la entrada de un contenedor
#define t2 			5000								// tiempo para volver a verificar la salida de un contenedor
#define t3 			5000								// tiempo máximo para abrir o cerrar la valvula

#define ledR		LED3
#define ledV		LED1

/**
  * @brief  Inicializa la máquina de estados y todos sus perifericos.
  * @param  None
  * @retval None
  */

void MEF_init();

/**
  * @brief  Lee las entradas, resuelve la lógica de transición de estados y actualiza las salidas.
  * @param  None
  * @retval None
  */

void MEF_update();

#endif /* __API_MEF_H */
