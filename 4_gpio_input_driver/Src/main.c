// PUSH BUTTON -> PA0

#include "stm32f4xx.h"

#define GPIOCEN		(1U<<2)
#define PIN13		(1U<<13)
#define LED_PIN		PIN13

#define GPIOAEN 	(1U<<0)
#define PIN0		(1U<<0)
#define BTN_PIN		PIN0

int main(void)
{
	/*enable clock access to GPIOA and GPIOC */
	RCC->AHB1ENR |=GPIOCEN;
	RCC->AHB1ENR |=GPIOAEN;

	// set PC13 as OUTPUT PIN
	GPIOC->MODER |=(1U<<26);
	GPIOC->MODER &=~(1U<<27);

	// set PA0 as INPUT PIN
	GPIOA->MODER &=~(1U<<0);
	GPIOA->MODER &=~(1U<<1);

	GPIOA->PUPDR &=~(3U << 0);
	GPIOA->PUPDR |= (1U << 0);
	while (1)
	{
	    if(GPIOA->IDR & BTN_PIN) {
	    	GPIOC->BSRR=(1U<<29); // LED ACESO
	    } else {
	    	GPIOC->BSRR=(1U<<13); //LED APAGADO
	    }
	}
}
