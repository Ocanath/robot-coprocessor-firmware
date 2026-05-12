/*
 * uart_buffers.c
 *
 *  Created on: Jan 7, 2026
 *      Author: Ocanath Robotman
 */
#include "uart_buffers.h"
#include "init.h"

uint8_t gl_uart1_rx_buf[UART_BUF_SIZE] = {};
uint8_t gl_uart1_rx_decoded_buf[UART_BUF_SIZE] = {};
uint8_t gl_uart1_tx_buf[UART_BUF_SIZE] = {};

uint8_t gl_uart2_rx_buf[UART_BUF_SIZE] = {};
uint8_t gl_uart2_rx_decoded_buf[UART_BUF_SIZE] = {};
uint8_t gl_uart2_tx_buf[UART_BUF_SIZE] = {};

uint8_t gl_uart3_rx_buf[UART_BUF_SIZE] = {};
uint8_t gl_uart3_rx_decoded_buf[UART_BUF_SIZE] = {};
uint8_t gl_uart3_tx_buf[UART_BUF_SIZE] = {};

dma_uart_t m_huart1;
dma_uart_t m_huart2;
dma_uart_t m_huart3;


void init_uart_buffers(void)
{
	init_dma_uart(
				&m_huart1,
				huart1.Instance,
				hdma_usart1_rx.Instance,
				hdma_usart1_tx.Instance,
				gl_uart1_rx_buf,
				sizeof(gl_uart1_rx_buf),
				gl_uart1_rx_decoded_buf,
				sizeof(gl_uart1_rx_decoded_buf),
				gl_uart1_tx_buf,
				sizeof(gl_uart1_tx_buf)
			);


	init_dma_uart(
				&m_huart2,
				huart2.Instance,
				hdma_usart2_rx.Instance,
				hdma_usart2_tx.Instance,
				gl_uart2_rx_buf,
				sizeof(gl_uart2_rx_buf),
				gl_uart2_rx_decoded_buf,
				sizeof(gl_uart2_rx_decoded_buf),
				gl_uart2_tx_buf,
				sizeof(gl_uart2_tx_buf)
			);

	init_dma_uart(
				&m_huart3,
				huart3.Instance,
				hdma_usart3_rx.Instance,
				hdma_usart3_tx.Instance,
				gl_uart3_rx_buf,
				sizeof(gl_uart3_rx_buf),
				gl_uart3_rx_decoded_buf,
				sizeof(gl_uart3_rx_decoded_buf),
				gl_uart3_tx_buf,
				sizeof(gl_uart3_tx_buf)
			);

}
