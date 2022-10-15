#include "decode.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "string.h"


extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart7;

void decodeData(volatile const uint8_t *pData){
	if(pData==NULL){
		return;
	}
	
	rc_t.ch[0] = (((int16_t)pData[0] | ((int16_t)pData[1] << 8)) & 0x07FF) ; 
	rc_t.ch[1] = ((((int16_t)pData[1] >> 3) | ((int16_t)pData[2] << 5)) & 0x07FF)  ;
	rc_t.ch[2] = ((((int16_t)pData[2] >> 6) | ((int16_t)pData[3] << 2) |((int16_t)pData[4] << 10)) & 0x07FF) ;
	rc_t.ch[3] = ((((int16_t)pData[4] >> 1) | ((int16_t)pData[5]<<7)) & 0x07FF) ;
	rc_t.s[0] = ((pData[5] >> 4) & 0x000C) >> 2;
	rc_t.s[1]= ((pData[5] >> 4) & 0x0003);
	
}

uint8_t data_collection[18];
uint8_t aa[]="------------------";
int start = 0;
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	if(__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) != RESET)  //接收到数据
	{
			
		HAL_UART_Receive(&huart1,data_collection, 18,100);
		decodeData(data_collection);
		HAL_UART_Transmit(&huart7,(uint8_t *)rc_t.s[0], 1,1000);
		//HAL_UART_Transmit(&huart7,aa, 18,1000);
		
		

	
		__HAL_UART_CLEAR_FLAG(&huart1,UART_FLAG_RXNE);        //清除接收标志位，每次接收完成都需要清除一下
		//while(__HAL_UART_GET_FLAG(USART3,USART_FLAG_TC) ==RESET);	  //用于检查串口UART1是否发送完成,完成时,TC中断标志置位,退出轮询等待!	
	}

	

	

  /* USER CODE END USART1_IRQn 0 */
	HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}