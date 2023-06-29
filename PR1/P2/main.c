#include "main.h"

int main(void)
{
  HAL_Init();

  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

  int i = 0;
  int l[] = {0, 1, 2};

  while (1)
  {
	  BSP_LED_Toggle(l[i]);
	  HAL_Delay(200);
	  BSP_LED_Toggle(l[i]);
	  i++;
	  if (i>2) i=0;
	  if(BSP_PB_GetState(BUTTON_USER)){
		  if (l[1]==1) {
			  l[1] = 2;
			  l[2] = 1;
		  } else {
			  l[1] = 1;
			  l[2] = 2;
		  }
	  }

  }
}
