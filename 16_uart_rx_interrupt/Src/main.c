#include <stdio.h>
#include "stm32c0xx.h"
#include "stdint.h"
#include "uart.h"

#define GPIOAEN (1U << 0)
#define PIN5 (1U << 5)
#define LED_PIN PIN5




char key;
int main(void){


	uart2_rxtx_init();
	RCC->IOPENR |= GPIOAEN;
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &= ~(1U << 11);


	uart2_rx_interrupt_init();

	while(1){

	}
}


void uart_callback(void){

	key = USART2->RDR;

	if(key == 'p'){
				GPIOA->ODR |= LED_PIN;

			}
			else{
				GPIOA->ODR &= ~LED_PIN;
			}
}

void USART2_IRQHandler(void){

	//CHECK IF RXNE IS SET
	if(USART2->ISR & ISR_RXFNE){
		uart_callback();
	}

}






