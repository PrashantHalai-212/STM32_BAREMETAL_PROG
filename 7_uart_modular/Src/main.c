#include <stdio.h>
#include "stm32c0xx.h"
#include "stdint.h"
#include "uart.h"







int main(void){


	uart2_tx_init();

	while(1){
		printf("Hello World from STM32 \n\r");

	}
}







