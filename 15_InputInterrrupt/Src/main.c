#include <stdio.h>
#include "stm32c0xx.h"
#include "stdint.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

#define GPIOAEN (1U << 0)
#define PIN5 (1U << 5)
#define LED_PIN PIN5

int main(void){

	RCC->IOPENR |= GPIOAEN;
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &= ~(1U << 11);

	PC13_exti_init();
	while(1){
	}
}


static void exti_callback(void){
	GPIOA->ODR ^= LED_PIN;

}


void EXTI4_15_IRQHandler(void){
	if((EXTI->FPR1 & (1U << 13)) != 0){
		//CLEAR THE FLAG
		EXTI->FPR1 = (1U << 13);
		//DO SOMETHING
		exti_callback();
	}
}




