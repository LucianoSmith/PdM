#include "main.h"

int main(void)
{
  HAL_Init();

  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);

  int i = 0;

  while (1)
  {
	  BSP_LED_Toggle(i);
	  HAL_Delay(200);
	  BSP_LED_Toggle(i);
	  i++;
	  if (i>2) i=0;
  }
}
