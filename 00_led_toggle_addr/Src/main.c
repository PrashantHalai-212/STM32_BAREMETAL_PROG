//Where is the LED connected
//PORT:  A
//PIN:   5


#define PERIPH_BASE    					(0x40000000UL)

#define IOPORT_OFFSET  					(0x10000000UL)
#define IOPORT_BASE	   					(PERIPH_BASE + IOPORT_OFFSET)
#define GPIOA_OFFSET   					(0x0000UL)
#define GPIOA_BASE 	  					(IOPORT_BASE + GPIOA_OFFSET)

#define AHBPERIPH_OFFSET 				(0x00020000UL)
#define AHBPERIPH_BASE   				(PERIPH_BASE + AHBPERIPH_OFFSET)

#define RCC_OFFSET     					(0x00001000UL)
#define RCC_BASE       					(AHBPERIPH_BASE + RCC_OFFSET)

#define RCC_IOPEN_R_OFFSET  			(0x34UL)
#define RCC_IOPEN_R 					(*(volatile unsigned int *)(RCC_BASE + RCC_IOPEN_R_OFFSET))

#define MODE_R_OFFSET 					(0x00UL)
#define GPIOA_MODE_R  					(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define ODR_OFFSET 						(0x14UL)
#define GPIO_A_OD_R 					(*(volatile unsigned int *)(GPIOA_BASE + ODR_OFFSET))

#define GPIOAEN  						(1U << 0)  // 0b 0000 0000 0000 0000 0000 0000 0000 0001

#define PIN5 							(1U << 5)
#define LED_PIN 						(PIN5)


int main(void){
	/*1. Enable clock access to GPIOA*/
	RCC_IOPEN_R |= GPIOAEN;
	/*2. Set PA5 as OUTPUT*/
	GPIOA_MODE_R |=  (1U << 10);
	GPIOA_MODE_R &= ~(1U << 11);


	while(1)

	{
		/*Set PA5 High*/
		//GPIO_A_OD_R |= LED_PIN;

		//Toggle The LED
		GPIO_A_OD_R ^= LED_PIN;
		for(int i = 0 ; i<100000 ; i++){}


	}


}
