

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
void pal_adc_init(void);
void start_conversion(void);
void PAl_adc_Interrupt_init(void);
uint32_t adc_read(void);
#define EOC (1U << 2)

#endif /* ADC_H_ */
