/*
 * stm32l4xx.h
 *
 *  Created on: Sep 26, 2024
 *      Author: kunfu
 */

#ifndef INC_STM32L4XX_H_
#define INC_STM32L4XX_H_

#include<stdint.h>
#define __vo volatile

#define  NVIC_ISER0				((__vo uint32_t*)0XE000E100)
#define  NVIC_ISER1				((__vo uint32_t*)0XE000E104)
#define  NVIC_ISER2				((__vo uint32_t*)0XE000E108)
#define  NVIC_ISER3				((__vo uint32_t*)0XE000E10c)




#define  NVIC_ICER0				((__vo uint32_t*)0XE000E180)
#define  NVIC_ICER1				((__vo uint32_t*)0XE000E184)
#define  NVIC_ICER2				((__vo uint32_t*)0XE000E188)
#define  NVIC_ICER3				((__vo uint32_t*)0XE000E18c)


#define NVIC_PR_BASE_ADDR		((__vo uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED			4

#define FLASH_BASEADDR			0x08000000U	/*	if for the flash base address*/
#define SRAM1_BASEADDR			0x20000000U //112kb
#define SRAM2_BASEADDR			0x10000000U
#define ROM_BASEADDR			0x1FFF0000U
#define SRAM 					SRAM1_BASEADDR

#define PERIPH_BASEADDR			0x40000000U
#define	APB1PERIPH_BASEADDR		PERIPH_BASEADDR
#define	APB2PERIPH_BASEADDR		0x40010000U
#define	AHB1PERIPH_BASEADDR		0x40020000U
#define AHB2PERIPH_BASEADDR		0x48000000U

#define GPIOA_BASEADDR			(AHB2PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR			(AHB2PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR			(AHB2PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR			(AHB2PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR			(AHB2PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR			(AHB2PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR			(AHB2PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR			(AHB2PERIPH_BASEADDR + 0x1C00)

#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR + 0x4800)

#define UART4_BASEADDR			(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR + 0x5000)

#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000)

#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800)

#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x0400)

#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x0000)
#define RCC_BASEADDR 			(APB1PERIPH_BASEADDR + 0x1000)

/************************************************************************peripheral register definition *************************************************************************/

typedef struct {
	__vo uint32_t MODER; /*          GPIO port mode register						*/
	__vo uint32_t OTYPER; /*  		GPIO port output type register 				*/
	__vo uint32_t OSPEEDR; /* 			GPIO port output speed register				*/
	__vo uint32_t PUPDR; /*   		GPIO port pull-up/pull-down register 		*/
	__vo uint32_t IDR; /*  		GPIO port input data register 				*/
	__vo uint32_t ODR; /* 			GPIO port output data register				*/
	__vo uint32_t BSRR; /* 			GPIO port bit set/reset register 			*/
	__vo uint32_t LCKR; /*  		GPIO port configuration lock register 		*/
	__vo uint32_t AFR[2]; /*  		GPIO alternate function low register 		*/
	__vo uint32_t BRR; /*  		GPIO port bit reset register				*/
	__vo uint32_t ASCR; /* 			GPIO port analog switch control register 	*/
} GPIO_RegDef_t;

typedef struct {
	__vo uint32_t CR; /*   Clock control register  										 	*/
	__vo uint32_t ICSCR; /*   Internal clock sources calibration register    				 	*/
	__vo uint32_t CFGR; /*   Clock configuration register    								 	*/
	__vo uint32_t PLLCFGR; /*   PLL configuration register    									 	*/
	__vo uint32_t PLLSAI1CFGR; /*   PLLSAI1 configuration register     								*/
	__vo uint32_t PLLSAI2CFGR; /*   PLLSAI2 configuration register    									*/
	__vo uint32_t CIER; /*   Clock interrupt enable register    								*/
	__vo uint32_t CIFR; /*   Clock interrupt flag register   									*/
	__vo uint32_t CICR; /*   Clock interrupt clear register    									*/
	__vo uint32_t RESERVED0;  		// Offset: 0x24 (padding for alignment)
	__vo uint32_t AHB1RSTR; /*   AHB1 peripheral reset register    									*/
	__vo uint32_t AHB2RSTR; /*   AHB2 peripheral reset register   									*/
	__vo uint32_t AHB3RSTR; /*   AHB3 peripheral reset register    									*/
	__vo uint32_t RESERVED1;		// Offset: 0x34 (padding for alignment)
	__vo uint32_t APB1RSTR1; /*   APB1 peripheral reset register 1    								*/
	__vo uint32_t APB1RSTR2; /*   APB1 peripheral reset register 2   								*/
	__vo uint32_t APB2RSTR; /*   APB2 peripheral reset register    									*/
	__vo uint32_t RESERVED2;  		// Offset: 0x44 (padding for alignment)
	__vo uint32_t AHB1ENR; /*   AHB1 peripheral clock enable register    							*/
	__vo uint32_t AHB2ENR; /*   AHB2 peripheral clock enable register    							*/
	__vo uint32_t AHB3ENR; /*   AHB3 peripheral clock enable register    							*/
	__vo uint32_t RESERVED3;  		// Offset: 0x44 (padding for alignment)
	__vo uint32_t APB1ENR1; /*   APB1 peripheral clock enable register 1     						*/
	__vo uint32_t APB1ENR2; /*   APB1 peripheral clock enable register 2    						*/
	__vo uint32_t APB2ENR; /*   APB2 peripheral clock enable register   							*/
	__vo uint32_t RESERVED4;  		// Offset: 0x44 (padding for alignment)
	__vo uint32_t AHB1SMENR; /*   AHB1 peripheral clocks enable in Sleep and Stop modes register     */
	__vo uint32_t AHB2SMENR; /*   AHB2 peripheral clocks enable in Sleep and Stop modes register     */
	__vo uint32_t AHB3SMENR; /*   AHB3 peripheral clocks enable in Sleep and Stop modes register     */
	__vo uint32_t RESERVED5;  		// Offset: 0x44 (padding for alignment)
	__vo uint32_t APB1SMENR1; /*   APB1 peripheral clocks enable in Sleep and Stop modes register 1   */
	__vo uint32_t APB1SMENR2; /*   APB1 peripheral clocks enable in Sleep and Stop modes register 2   */
	__vo uint32_t APB2SMENR; /*   APB2 peripheral clocks enable in Sleep and Stop modes register     */
	__vo uint32_t RESERVED6;  		// Offset: 0x44 (padding for alignment)
	__vo uint32_t CCIPR; /*   Peripherals independent clock configuration register    			*/
	__vo uint32_t BDCR; /*   Backup domain control register    									*/
	__vo uint32_t CSR; /*   Control/status register    										*/
	__vo uint32_t RESERVED7;  		// Offset: 0x44 (padding for alignment)
	__vo uint32_t CRRCR; /*   Clock recovery RC register     									*/
	__vo uint32_t CCIPR2; /*   Peripherals independent clock configuration register     			*/
} RCC_RegDef_t;

/*
 *peripheral definition ( peripheral base addresses typecasted toEXTI)
 *peripheral
 * */
typedef struct
{
	__vo uint32_t IMR; /*          GPIO port mode register						*/
	__vo uint32_t EMR; /*  		GPIO port output type register 				*/
	__vo uint32_t RTSR; /* 			GPIO port output speed register				*/
	__vo uint32_t FTSR; /*   		GPIO port pull-up/pull-down register 		*/
	__vo uint32_t SWIER; /*  		GPIO port input data register 				*/
	__vo uint32_t PR; /* 			GPIO port output data register				*/
}EXTI_RegDef_t;


typedef struct
{
	__vo uint32_t MEMRMP; /*          GPIO port mode register						*/
	__vo uint32_t CFGR1; /*  		GPIO port output type register 				*/
	__vo uint32_t EXTICR[4]; /* 			GPIO port output speed register				*/
	__vo uint32_t SCSR; /*   		GPIO port pull-up/pull-down register 		*/
	__vo uint32_t CFGR2; /*  		GPIO port input data register 				*/
	__vo uint32_t SWPR; /* 			GPIO port output data register				*/
	__vo uint32_t SKR;
}SYSCFG_RegDef_t;



#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  				((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC 				((RCC_RegDef_t*) RCC_BASEADDR)

#define EXTI				((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


#define GPIOA_PCLK_EN()    (RCC->AHB2ENR |= (1 << 0))
#define GPIOB_PCLK_EN()    (RCC->AHB2ENR |= (1 << 1))
#define GPIOC_PCLK_EN()    (RCC->AHB2ENR |= (1<<2))
#define GPIOD_PCLK_EN()    (RCC->AHB2ENR |= (1<<3))
#define GPIOE_PCLK_EN()    (RCC->AHB2ENR |= (1<<4))
#define GPIOF_PCLK_EN()    (RCC->AHB2ENR |= (1<<5))
#define GPIOG_PCLK_EN()    (RCC->AHB2ENR |= (1<<6))
#define GPIOH_PCLK_EN()    (RCC->AHB2ENR |= (1<<7))

#define I2C1_PCLK_EN()     (RCC->APB1ENR1 |= (1<<21))
#define I2C2_PCLK_EN()     (RCC->APB1ENR1 |= (1<<22))
#define I2C3_PCLK_EN()     (RCC->APB1ENR1 |= (1<<23))

#define SPI1_PCLK_EN()     (RCC->APB2ENR  |= (1<<12))
#define SPI2_PCLK_EN()     (RCC->APB1ENR1 |= (1<<14))
#define SPI3_PCLK_EN()     (RCC->APB1ENR1 |= (1<<15))

#define USART1_PCLK_EN()   (RCC->APB2ENR  |= (1<<14))
#define USART2_PCLK_EN()   (RCC->APB1ENR1 |= (1<<17))
#define USART3_PCLK_EN()   (RCC->APB1ENR1 |= (1<<18))
#define UART4_PCLK_EN()    (RCC->APB1ENR1 |= (1<<19))
#define UART5_PCLK_EN()    (RCC->APB1ENR1 |= (1<<20))

#define SYSCFG_PCLK_EN()   (RCC->APB2ENR  |= (1<<0))

// Disabling clock macros
#define GPIOA_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<7))

#define GPIOA_REG_RESET()		do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<0));}while(0)
#define GPIOB_REG_RESET()		do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<1));}while(0)
#define GPIOC_REG_RESET()		do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<2));}while(0)
#define GPIOD_REG_RESET()		do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<3));}while(0)
#define GPIOE_REG_RESET()		do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<4));}while(0)
#define GPIOF_REG_RESET()		do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<5));}while(0)
#define GPIOG_REG_RESET()		do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<6));}while(0)
#define GPIOH_REG_RESET()		do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<7));}while(0)

#define GPIO_BASEADDR_TO_CODE(x)     ((x== GPIOA)? 0:\
									  (x == GPIOB)? 1:\
									 (x == GPIOC)? 2:\
									(x == GPIOB)? 3:\
									 (x == GPIOA)? 4:\
									(x == GPIOB)? 5:\
											(x == GPIOA)? 6:\
													(x == GPIOB)? 7:0)
//
#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET 	SET
#define GPIO_PIN_RESET  RESET

#endif /* INC_STM32L4XX_H_ */
