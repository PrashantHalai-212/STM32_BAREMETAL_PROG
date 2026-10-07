#include <stdio.h>
#include "stm32c0xx.h"
#include "stdint.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

int main(void){


	/*RCC->IOPENR |= GPIOAEN;
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &= ~(1U << 11);

	uart2_tx_init();

	tim2_1hz_init();*/
	tim3_PB1_output_compare();


	while(1){

		/*WAIT FOR UIF
		while(!(TIM3->SR & SR_UIF)){}

		//CLEAR UIF
		TIM3->SR &= ~SR_UIF;
		printf("A second passed \n\r");
		GPIOA->ODR ^= LED_PIN;*/




	}
}







