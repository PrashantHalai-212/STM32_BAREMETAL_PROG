#include "stm32c0xx.h"
#include "stdint.h"


#define GPIOAEN (1U << 0)
#define UART2EN (1U << 17)
#define CR1_TE (1U << 3)
#define SYS_FREQ 12000000
#define APB1_CLK SYS_FREQ
#define UART_BAUDRATE 115200
#define ISR_TXFNF (1U << 7)

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate){
	return (PeriphClk + (BaudRate/2U))/BaudRate;
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate){
	USARTx->BRR = compute_uart_bd(PeriphClk,BaudRate);
}

void uart2_write(int ch){

	/*Make Sure transmit data register is empty*/
	while(!(USART2->ISR & ISR_TXFNF)){}
	/*Write to transmit register*/
	USART2->TDR = (ch & 0xFF);
}

void uart2_tx_init(void){
	/*********************Configure UART GPIO pin*******************/
	//Enable the clock access to GPIOA
	RCC->IOPENR |= (1U << 0);

	//SET PA2 to Alternate Function Mode
	GPIOA->MODER |= (1U << 5);
	GPIOA->MODER &= ~(1U << 4);

	//SET PA2 Alternate Function Type to UART_TX (AF1)
	GPIOA->AFR[0] |=  (1U << 8);
	GPIOA->AFR[0] &= ~(1U << 9);
	GPIOA->AFR[0] &= ~(1U << 10);
	GPIOA->AFR[0] &= ~(1U << 11);

	/***************Configure UART Module******************/

	//Enable the clock access to UART2
	RCC->APBENR1 |= UART2EN;

	//Configure BaudRate
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

	//Configure the Transfer Direction
	USART2->CR1 = CR1_TE;

	//Enable the UART module
	USART2->CR1 |= (1U << 0);

}



int main(void){


	uart2_tx_init();

	while(1){
		uart2_write('Y');

	}
}







