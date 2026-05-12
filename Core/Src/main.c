#include "main.h"
#include "init.h"
#include "uart_buffers.h"

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_TIM1_Init();
	MX_TIM2_Init();
	MX_SPI1_Init();
	MX_USART2_UART_Init();
	MX_FDCAN1_Init();
	MX_I2S2_Init();
	MX_USART1_UART_Init();
	MX_USART3_UART_Init();
	while (1)
	{
		//do stuff
	}
}

