/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Hussein Demrdash
 * @brief          : Main program body
 ******************************************************************************
 */


typedef unsigned int  uint32_t;
typedef unsigned char uint8_t;


typedef volatile unsigned int vuint32_t;

//RCC register
#define RCC_BASE 		0x40021000
#define RCC_APB2ENR 	*(volatile uint32_t *)(RCC_BASE + 0x18)	


//GPIO register
#define GPIOA_BASE 		0x40010800
#define GPIOA_CRL 		*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH 		*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR 		*(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR 		*(volatile uint32_t *)(GPIOA_BASE + 0x08)


#define GPIOB_BASE 		0x40010C00
#define GPIOB_CRL 		*(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH 		*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR 		*(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR 		*(volatile uint32_t *)(GPIOB_BASE + 0x08)

void Clock_Init()
{
	//	enable clock GPIOA
	RCC_APB2ENR |= (1 << 2);
	//	enable clock GPIOB
	RCC_APB2ENR |= (1 << 3);

}
void GPIO_Init()
{
	//	00: Analog mode
	//	01: Floating input (reset state)
	//	10: Input with pull-up / pull-down
	//	11: Reserved
	//	Pin 1 port A input
	//	00: Input mode (reset state)
	//	01: Floating input (reset state)
	GPIOA_CRL &= ~(0b1111 << 4);
    GPIOA_CRL |=  (0b0100 << 4);

	//	Pin 13 port A input
	//	00: Input mode (reset state)
	//	01: Floating input (reset state)
	GPIOA_CRH &= ~(0b1111 << 20);
    GPIOA_CRH |=  (0b0100 << 20);

	//	Pin 1 Port B Push-Pull output
	//	01: Output mode, max speed 10 MHz.
	//	00: General purpose output push-pull
	GPIOB_CRL &= ~(0b1111 << 4);
    GPIOB_CRL |=  (0b0001 << 4);

	//	Pin 13 port B Push-Pull 01: Output mode, max speed 10 MHz. output
	//	01: Output mode, max speed 10 MHz.
	//	00: General purpose output push-pull
	GPIOB_CRH &= ~(0b1111 << 20);
    GPIOB_CRH |=  (0b0001 << 20);


}
void wait(vuint32_t time)
{

	vuint32_t i,j;
	for (i =0; i<time;i++)
	{
		for (j=0 ; j<255;j++)
		{

		}
	}

}

int main(void)
{
	Clock_Init();
	GPIO_Init();
    uint8_t still_pressed_flag = 0; 
	while(1)
	{
		if((((GPIOA_IDR & (1<<1)) >> 1) == 0 ) && (still_pressed_flag == 0))//Get pressed and realse
		{
            //			single press
			GPIOB_ODR ^= (1<<1);
			still_pressed_flag = 1;
		}

        if((still_pressed_flag == 1) && (((GPIOA_IDR & (1<<1)) >> 1) ==1 ))//Get unpressed
		{
			still_pressed_flag = 0;
		}

		if(((GPIOA_IDR & (1<<13))>> 13) == 1) //Get pressed
		{
			//			multi press
			GPIOB_ODR ^= (1<<13);
			wait(500);
		}
		

	}
}