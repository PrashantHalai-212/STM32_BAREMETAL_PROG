#include "stm32c0xx.h"
#define GPIOBEN (1U << 1)

void tim3_1hz_init(void){

	//ENABLE CLOCK ACCESS TO TIM2
	RCC->APBENR1 |= (1U << 1);

	//SET THE PRESCALER VALUE
	TIM3->PSC = (1600 - 1); //(16000000/1600) = 10000

	//AUTORELOAD VALUE
	TIM3->ARR = 10000 - 1; //(10000/10000) = 1

	//CLEAR THE COUNTER
	TIM3->CNT = 0;

	//ENABLE TIMER
	TIM3->CR1 |= (1U << 0);
}


void tim3_PB1_output_compare(void){

	//ENABLE CLOCK ACCESS TO GPIOB
	RCC->IOPENR |= GPIOBEN;

	//PB1 INTO ALTERNATE FUNCTION MODE
	GPIOB->MODER |= (1U << 3);
	GPIOB->MODER &= ~(1U << 2);

	//PB1 ALTERNATE FUNC TO TIM3_CH4
	GPIOB->AFR[0] |= (1U << 4);
	GPIOB->AFR[0] &= ~(1U << 5);
	GPIOB->AFR[0] &= ~(1U << 6);
	GPIOB->AFR[0] &= ~(1U << 7);

	//ENABLE CLOCK ACCESS TO TIM3
	RCC->APBENR1 |= (1U << 1);

	//SET THE PRESCALER VALUE
	TIM3->PSC = (1600 - 1); //(16000000/1600) = 10000

	//AUTORELOAD VALUE
	TIM3->ARR = 1000 - 1; //(10000/10000) = 1

	//SET OUTPUT COMPARE TOGGLE MODE
	TIM3->CCMR2 &= ~(1U << 8); //have to set this 2 bits to 0
	TIM3->CCMR2 &= ~(1U << 9); //in oder to use alternate register

	TIM3->CCMR2 = (1U << 12) | (1U << 13);
	TIM3->CCMR2 &= ~(1U << 14);
	TIM3->CCMR2 &= ~(1U << 24);

	//ENABLE CH4 IN COMPARE MODE
	TIM3->CCER |= (1U << 12);

	//CLEAR THE COUNTER
	TIM3->CNT = 0;

	//ENABLE TIMER
	TIM3->CR1 |= (1U << 0);
}
