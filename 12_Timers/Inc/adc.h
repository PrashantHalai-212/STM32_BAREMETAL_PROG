/*
 * adc.h
 *
 *  Created on: 16-Sept-2026
 *      Author: Prashant
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
void pal_adc_init(void);
void start_conversion(void);
uint32_t adc_read(void);


#endif /* ADC_H_ */
