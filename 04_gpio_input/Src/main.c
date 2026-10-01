#include "stm32c0xx.h"


#define GPIOAEN (1U << 0)
#define PIN5 (1U << 5)
#define LED_PIN PIN5

#define GPIOCEN (1U << 2)
#define PIN13 (1U << 13)
#define BTN_PIN PIN13


int main(void){

	RCC->IOPENR |= GPIOAEN;
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &= ~(1U << 11);

	RCC->IOPENR |= GPIOCEN;
	GPIOC->MODER &= ~(1U << 26);
	GPIOC->MODER &= ~(1U << 27);


	while(1){

		if(GPIOC->IDR & BTN_PIN){
		GPIOA->BSRR = LED_PIN;
		}
		else{
		GPIOA->BSRR = (1U<<21);
		}

	}
}
