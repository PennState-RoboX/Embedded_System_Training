#include "my_can_init.h"
#include "main.h"


extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

void mycan_init(void)
	
{
	
	    HAL_CAN_Start(&hcan1);
	
	
}