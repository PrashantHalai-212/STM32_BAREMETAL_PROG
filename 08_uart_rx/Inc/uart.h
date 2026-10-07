

#ifndef UART_H_
#define UART_H_
#include "stm32c0xx.h"
#include "stdint.h"


void uart2_tx_init(void);
void uart2_rxtx_init(void);
uint8_t uart2_read(void);


#endif /* UART_H_ */
