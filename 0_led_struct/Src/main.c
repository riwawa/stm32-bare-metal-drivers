// onde o LED está conectado
// PORT: C
// PIN: 13

#define PERIPH_BASE				(0x40000000UL)

#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOC_OFFSET			(0x0800UL)
#define GPIOC_BASE				(AHB1PERIPH_BASE + GPIOC_OFFSET)

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET			(0x30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET			(0x00UL)
#define GPIOC_MODE_R			(*(volatile unsigned int *)(GPIOC_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET				(0x14UL)
#define GPIOC_OD_R				(*(volatile unsigned int *)(GPIOC_BASE + OD_R_OFFSET))

#define GPIOCEN 				(1U<<2)

#define PIN13					(1U<<13)
#define LED_PIN					PIN13

#define __IO 	volatile

typedef struct
{
	__IO uint32 MODER;
	__IO uint32 OTYPER;
	__IO uint32 OSPEEDR;
	__IO uint32 PUPDR;
	__IO uint32	IDR;
	__IO uint32 ODR;
	__IO uint32 BSRR;
	__IO uint32 LCKR;
	__IO uint32 AFR[2];
}GPIO_TypeDef;

int main(void){
	RCC_AHB1EN_R |= GPIOCEN;
	GPIOC_MODE_R |= (1U << 26);
	GPIOC_MODE_R &= ~(1U << 27);

	while (1) {
	    GPIOC_OD_R &= ~LED_PIN;

	    // toggle pc13
	    //GPIOC_OD_R ^= LED_PIN;
	    //for (int i=0; i < 100000; i++){}
	}
}
