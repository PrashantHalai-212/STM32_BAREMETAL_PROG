#include "stm32c0xx.h"
#include "adc.h"


#define GPIOAEN (1U << 0)
#define ADCEN (1U << 20)
#define ADC_CH1 (1U << 1) /*BE CAREFUL WHILE SELECTING THE CHANNEL*/
#define CCRDY (1U << 13)
#define ADEN (1U << 0)
#define ADSTART (1U << 2)
#define EOC (1U << 2)



void pal_adc_init(void){

	/*ENABLE CLOCK TO GPIOA PORT*/
	RCC->IOPENR |= GPIOAEN;

	/*SET THE PIN PA1 MODE TO ADC*/
	GPIOA->MODER |= (1U << 2);
	GPIOA->MODER |= (1U << 3);

	/*ENABLE CLOCK TO ADC*/
	RCC->APBENR2 |= ADCEN;

	/*CONVERSION SEQUENCE START*/
	ADC1->CHSELR = (ADC_CH1);


	/*SEQUENCE LENGTH (NO NEED IN NEWER NUCLEOBOARDS)*/

	/*ADC ENABLE*/
	ADC1->CR |= ADEN;
}

void start_conversion(void){
	/*STAR CONVERSION*/
	ADC1->CR |= ADSTART;
}

uint32_t adc_read(void){
	/*WAIT FOR THE CONVERSION TO BE COMPLETE*/
	while(!(ADC1->ISR & EOC)){}

	/*READ THE CONVERSION */
	return (ADC1->DR);


}
