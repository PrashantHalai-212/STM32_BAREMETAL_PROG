#include <stdio.h>
#include "stm32c0xx.h"
#include "stdint.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

int timestamp = 0;

//CONNECT PB1 to PA7 ON YOUR NUCLEO BOARD

int main(void){

	tim3_PB1_output_compare();
	tim14_PA7_input_capture();

	while(1){
		//WAIT FOR CC1IF
		while(!(TIM3->SR & SR_CC1IF)){}

		//READ CAPTURED VALUE
		timestamp = TIM14->CCR1;
	}
}







