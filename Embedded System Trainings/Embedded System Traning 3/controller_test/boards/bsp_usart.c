#include "bsp_usart.h"
#include "main.h"

extern UART_HandleTypeDef huart6;
extern DMA_HandleTypeDef hdma_usart6_tx;
void usart6_tx_dma_init(void)
{
    //enable the DMA transfer for the receiver request
    //使能DMA串口接收
    SET_BIT(huart6.Instance->CR3, USART_CR3_DMAT);
}
void usart6_tx_dma_enable(uint8_t *data, uint16_t len)
{

    //disable DMA
    //失效DMA
    __HAL_DMA_DISABLE(&hdma_usart6_tx);
    while(hdma_usart6_tx.Instance->CR & DMA_SxCR_EN)
    {
        __HAL_DMA_DISABLE(&hdma_usart6_tx);
    }

    //clear flag
    //清除标志位
    __HAL_DMA_CLEAR_FLAG(&hdma_usart6_tx, DMA_HISR_TCIF6);
    __HAL_DMA_CLEAR_FLAG(&hdma_usart6_tx, DMA_HISR_HTIF6);

    //set data address
    //设置数据地址
    hdma_usart6_tx.Instance->M0AR = (uint32_t)(data);
    //set data length
    //设置数据长度
    hdma_usart6_tx.Instance->NDTR = len;

    //enable DMA
    //使能DMA
    __HAL_DMA_ENABLE(&hdma_usart6_tx);
	HAL_UART_Transmit (&huart6, data , sizeof (data), 1000); 
}


