
#ifndef TIM_H_
#define TIM_H_

void tim2_1hz_init(void);

#define SR_UIF (1U<<0)
#define SR_CC1IF (1U << 1)

void tim3_PB1_output_compare(void);
void tim14_PA7_input_capture(void);


#endif /* TIM_H_ */









