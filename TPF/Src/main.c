/**
  ******************************************************************************
  * @title   	Trabajo final: Control autónomo de válvula guillotina
  * @file    	main.c
  * @author  	Luciano M. Smith
  * @hardware 	Nucleo-F429ZI
  ******************************************************************************
**/

#include "main.h"
#include "API_mef.h"

int main(void)						// estructura principal
{

  HAL_Init();				  		// inicialización de la capa de abstracción de hardware

  MEF_init();						// inicialización de la MEF

  while (1) {						// bucle infinito

	  MEF_update();					// llamada a la actualización de la MEF

  }

}

