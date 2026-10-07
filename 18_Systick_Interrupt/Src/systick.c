#include "stm32c0xx.h"

#define SYSTICK_LOAD_VAL		11999
#define CTRL_ENABLE				(1U<<0)
#define CTRL_CLKSRC				(1U<<2)
#define CTRL_COUNTFLAG			(1U<<16)
#define CTRL_TICKINT 			(1U << 1)
#define ONE_SEC_LOAD			16000000

void systickDelayMs(int delay){
	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD  = SYSTICK_LOAD_VAL;

	/*Clear systick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i=0; i<delay ; i++){

		/*Wait until the COUNTFLAG is set*/
		while((SysTick->CTRL &  CTRL_COUNTFLAG) == 0){}

	}

	SysTick->CTRL = 0;
}

void Systick_1Hz_Interrupt(void){

	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD = ONE_SEC_LOAD - 1;

	/*Clear SysTick current value register */
	SysTick->VAL = 0;

	/*Enable SysTick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	//ENABLE THE INTERRUPT
	SysTick->CTRL |= CTRL_TICKINT;

}
