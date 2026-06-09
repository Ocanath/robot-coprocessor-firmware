#include "main.h"
#include "init.h"
#include "uart_buffers.h"
#include "dartt.h"

/**
 * TODO:
 *
 * Turn this firmware into a full wifi middleman
 *
 * 1. Keep this as a template branch and tag, check out new wifi middleman branch.
 * 2. Create a dartt_map to control each external interface. Has dedicated memory for tx/rx which lives in the map. Has length argument for each buffer.
 	 	 I.e. - transfer ownership of ONLY decoded RX and tx buf to the dartt_map. Encoded RX is left separate as the async/DMA buffer
 * 3. Writes are dispatched based on len!=0. Writes are collected and dispatched in the event loop as-is
 * 4. Reads are routed to the ESP32 via UART2. Any collected read will get dispatched to the ESP32 UART as a DARTT read reply of the dartt map memory as-is.
 * 		So the ESP32 will be likely getting DARTT read replies where the payload is another DARTT read reply.
 * 		UART read reply to ESP32 is triggered by COBS framing only (no additional validation).
 * 		The DARTT payload section of the read reply will be COBS decoded, but the parent write frame will be COBS encoded.
 *
 * So the flow is:
 *
 *	//PSEUDOCODE
	while (1)
	{
		if(dartt_map.write_len != 0)
		{
			uart_write(dartt_map.write_buffer, dartt_map.write_len)
		}

		if(dartt_map.uart_decoded.len != 0)
		{
			read_reply = make_dartt_read_reply(type, dartt_map, dartt_map.uart_decoded)	//
			uart_write(read_reply)
		}
	}
 *
 * But for each interface.
 *
 * FDCAN is handled the same way - if there's a message in the mailbox passing the address filter, it gets wrapped up as a dartt read reply and dispatched.
 *
 *This means that the only valid things which can be written to the ESP32 to propagate to the controller are dartt frames. TCP or UDP will equivalently route out to USART2 dispatches.
 *The ESP32 will route replies out depending on a mode bit - we'll have to add 'async_reply_network_mode_is_tcp' to the nvs
 *
 *
 */



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

