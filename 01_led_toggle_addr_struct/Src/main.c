//Where is the LED connected
//PORT:  A
//PIN:   5

#include <stdint.h>
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

#define __IO volatile

typedef struct{

	volatile uint32_t MODER;        /* GPIO port mode register,               Address offset: 0x00*/
	//__IO uint32_t OTYPER;         /* GPIO port output type register,        Address offset: 0x04*/
	//__IO uint32_t OSPEEDR;  	    /* GPIO port output speed register,       Address offset: 0x08*/
	//__IO uint32_t PUPDR;  		/* GPIO port pull-up/pull-down register,  Address offset: 0x0C*/
	//__IO uint32_t IDR;  		    /* GPIO port input data register, 		  Address offset: 0x10*/
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;          /* GPIO port output data register,        Address offset: 0x14*/
	//__IO uint32_t BSRR;           /* GPIO port bit set/reset register,      Address offset: 0x18*/
	//__IO uint32_t LCKR;  	        /* GPIO port configuration lock register, Address offset: 0x1C*/
	//__IO uint32_t AFR;  		    /* GPIO alternate function low register,  Address offset: 0x20*/
	//__IO uint32_t AFRH;  	        /* GPIO alternate function high register, Address offset: 0x24*/
	//__IO uint32_t BRR;  	        /* GPIO port bit reset register, 		  Address offset: 0x28*/

}GPIO_TypeDef;

typedef struct{
	volatile uint32_t DUMY[13];
	volatile uint32_t IOPENR;       /*RCC I/O port clock enable register      Address offset: 0x34*/
}RCC_TypeDef;

#define RCC   ((RCC_TypeDef*)RCC_BASE)
#define GPIO  ((GPIO_TypeDef*)GPIOA_BASE)


int main(void){
	/*1. Enable clock access to GPIOA*/
	//RCC_IOPEN_R |= GPIOAEN;
	RCC->IOPENR |= GPIOAEN;
	/*2. Set PA5 as OUTPUT*/
	//GPIOA_MODE_R |=  (1U << 10);
	//GPIOA_MODE_R &= ~(1U << 11);
	GPIO->MODER |= (1U << 10);
	GPIO->MODER &= ~(1U << 11);


	while(1)

	{
		/*Set PA5 High*/
		//GPIO_A_OD_R |= LED_PIN;

		//Toggle The LED
		//GPIO_A_OD_R ^= LED_PIN;
		GPIO->ODR ^= LED_PIN;
		for(int i = 0 ; i<100000 ; i++){}


	}


}
