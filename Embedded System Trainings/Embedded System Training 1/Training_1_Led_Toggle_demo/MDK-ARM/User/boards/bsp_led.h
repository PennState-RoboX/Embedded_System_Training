#ifndef __bsp_led__
#define __bsp_led__

#include "stm32f4xx.h"  //allow to use HAL_function


#define LED_R_ON  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_RESET);
#define LED_G_ON  HAL_GPIO_WritePin(GPIOF,GPIO_PIN_14,GPIO_PIN_RESET);

#define LED_R_OFF  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET);
#define LED_G_OFF  HAL_GPIO_WritePin(GPIOF,GPIO_PIN_14,GPIO_PIN_SET);

#define LED_R_Toggle  HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_11);
#define LED_G_Toggle  HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_14);

void LED_GPIO_init(void);

#endif
