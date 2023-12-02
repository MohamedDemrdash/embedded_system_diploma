//Mohamed Hussein Demrdash
//Mastering Embedded System Online Diploma

typedef volatile unsigned int vuint32_t ;
typedef unsigned int uint32_t;

// register address
#define GPIOB_BASE 		0x40010C00
#define GPIOB_CRH 		*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR 		*(volatile uint32_t *)(GPIOB_BASE + 0x0C)

#define RCC_BASE 		0x40021000
#define RCC_APB2ENR 	*(volatile uint32_t *)(RCC_BASE + 0x18)

int main(void)
{

	//Enable IO port B clock
	RCC_APB2ENR |= 1<<3;
	//Init GPIOB
	GPIOB_CRH &= 0xFF0FFFFF;
	GPIOB_CRH |= 0x00200000;
	while(1)
	{
		int i;
		GPIOB_ODR |= 1<<13 ;
		for (i = 0; i < 5000; i++);
		GPIOB_ODR &= ~(1<<13) ;
		for (i = 0; i < 5000; i++);
	}
}
