#include <stdio.h>
#include "stm32c0xx.h"
#include "stdint.h"
#include "uart.h"
#include "adc.h"

uint32_t value;
int main(void){
	uart2_tx_init();
	PAl_adc_Interrupt_init();
	start_conversion();


	while(1){


	}
}

void  adc_callback(void){
	value = (ADC1->DR);
	printf("VALUE IS =  %d \n\r",(int)value);
}

void ADC_IRQHandler(void){
	//Check for EOC in SR
	if((ADC1->ISR & EOC)!=0){

		//CLEAR THE EOC
		ADC1->ISR &= ~EOC;

		//DO SOMETHING
		adc_callback();
	}
}







