#include "bsp_led.h"

void LED_GPIO_init(void){
	
	GPIO_InitTypeDef LED_GPIO_Init; 
	
	__HAL_RCC_GPIOG_CLK_ENABLE();
	
	
	
	LED_GPIO_Init.Mode  =  GPIO_MODE_OUTPUT_PP; //push pull output
	LED_GPIO_Init.Pin   =  GPIO_PIN_11;
	LED_GPIO_Init.Pull  = GPIO_NOPULL;
	LED_GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW; 
	
	HAL_GPIO_Init(GPIOE, &LED_GPIO_Init);
	
	LED_GPIO_Init.Mode  =  GPIO_MODE_OUTPUT_PP;
	LED_GPIO_Init.Pin   =  GPIO_PIN_14;
	LED_GPIO_Init.Pull  = GPIO_NOPULL;
	LED_GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW; 
	
	HAL_GPIO_Init(GPIOF, &LED_GPIO_Init);
}
