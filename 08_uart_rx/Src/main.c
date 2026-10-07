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



	while(1){

		key = uart2_read();
		if(key == 'p'){
			GPIOA->ODR |= LED_PIN;

		}
		else{
			GPIOA->ODR &= ~LED_PIN;
		}

	}
}







