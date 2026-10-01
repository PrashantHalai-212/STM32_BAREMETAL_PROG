#include <stdio.h>
#include "stm32c0xx.h"
#include "stdint.h"
#include "uart.h"
#include "adc.h"

uint32_t value;
int main(void){
	uart2_tx_init();
	pal_adc_init();


	while(1){
		start_conversion();
		value = adc_read();
		printf("VALUE IS =  %d \n\r",(int)value);

	}
}







