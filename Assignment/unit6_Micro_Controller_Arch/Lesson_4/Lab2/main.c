//Mohamed Hussein Demrdash
//Mastering Embedded System Online Diploma

typedef volatile unsigned int vuint32_t ;
typedef unsigned int uint32_t;

// register address
#define RCC_BASE 		0x40021000
#define RCC_APB2ENR 	*(volatile uint32_t *)(RCC_BASE   + 0x18)

#define GPIOB_BASE 		0x40010C00
#define GPIOB_CRL 		*(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH 		*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR 		*(volatile uint32_t *)(GPIOB_BASE + 0x0C)

#define AFIO_BASE		0x40010000
#define AFIO_EXTICR1 	*(volatile uint32_t *)(AFIO_BASE  + 0x08)

#define EXTI_BASE		0x40010400
#define EXTI_IMR 		*(volatile uint32_t *)(EXTI_BASE  + 0x00)
#define EXTI_RTSR 		*(volatile uint32_t *)(EXTI_BASE  + 0x08)
#define EXTI_PR 		*(volatile uint32_t *)(EXTI_BASE  + 0x14)

#define NVIC_BASE		0xE000E000
#define NVIC_ISER		0x100
#define NVIC_ISER_0_31  *(volatile uint32_t *)(NVIC_BASE+ NVIC_ISER + 0x00)


void CLOCK_INIT(void)
{
	//Enable IO port B clock
	RCC_APB2ENR |= (1<<3);

	//Enable AFIO clock
	RCC_APB2ENR |= (1<<0);

	//EXTI clock are enabled by defualt
}


void GPIO_INIT(void)
{

	//Configure Pin 1 at port B as a floating input
	GPIOB_CRL &= 0xFFFFFF0F;
	GPIOB_CRL |= 0x00000040;

	//Configure Pin 13 at port B as an output
	GPIOB_CRH &= 0xFF0FFFFF;
	GPIOB_CRH |= 0x00200000;

	//Configure EXTI1 to take source from pin 1 at port b
	AFIO_EXTICR1 |= (0b0001<<4);

}

void EXTI_INIT(void)
{
	//Configure the EXTI 1 to be triggered by the rising edge
	EXTI_RTSR |= (1<<1);

	//Enable the mask interrupt for EXTI 1
	EXTI_IMR |= (1<<1);

	//Enable the mask interrupt for EXTI 1 at NVIC
	NVIC_ISER_0_31 |= (1<<7);
}

int main(void)
{

	CLOCK_INIT();
	GPIO_INIT();
	EXTI_INIT();

	while(1)
	{
	}
}


void EXTI1_IRQHandler(void)
{
	//clear the pending bit for the EXTI 1
	EXTI_PR |= (1<<1);

	//toggel the pin 13 at port B
	GPIOB_ODR ^= (1<<13) ;
}