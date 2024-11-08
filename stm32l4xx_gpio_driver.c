/*
 * stm32l4xx_gpio_driver.c
 *
 *  Created on: Oct 18, 2024
 *      Author: kunfu
 */

#include  "stm32l4xx_gpio_driver.h"

/*
 * peripheral clock setup
 */
/************************************
 * @fn				- GPIO_PeriCLockCOntrol
 // * @brief			- These function is used to enable and disable the peripheral clock of gpio port
 * @
 * @param[in]		- base address of the gpio peripheral
 * @param[in]		-ENABLE or DESABLE macros
 * @param[in]		-
 *
 * @return			- none
 *
 * @Note			-none
 */
void GPIO_PeriCLockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi) {
	if (EnorDi == ENABLE) {
		if (pGPIOx == GPIOA) {
			GPIOA_PCLK_EN();
		} else if (pGPIOx == GPIOB) {
			GPIOB_PCLK_EN();
		}
		else if (pGPIOx == GPIOC) {
			GPIOC_PCLK_EN();
		} else if (pGPIOx == GPIOD) {
			GPIOD_PCLK_EN();
		}
		else if (pGPIOx == GPIOE) {
			GPIOE_PCLK_EN();
		} else if (pGPIOx == GPIOF) {
			GPIOF_PCLK_EN();
		} else if (pGPIOx == GPIOG) {
			GPIOG_PCLK_EN();
		} else if (pGPIOx == GPIOH) {
			GPIOH_PCLK_EN();
		}
	} else {
		if (pGPIOx == GPIOA) {
			GPIOA_PCLK_DI();
		} else if (pGPIOx == GPIOB) {
			GPIOB_PCLK_DI();
		}
		else if (pGPIOx == GPIOC) {
			GPIOC_PCLK_DI();
		} else if (pGPIOx == GPIOD) {
			GPIOD_PCLK_DI();
		} else if (pGPIOx == GPIOE) {
			GPIOE_PCLK_DI();
		} else if (pGPIOx == GPIOF) {
			GPIOF_PCLK_DI();
		} else if (pGPIOx == GPIOG) {
			GPIOG_PCLK_DI();
		} else if (pGPIOx == GPIOH) {
			GPIOH_PCLK_DI();
		}
	}
}

/*
 * init and deinit
 */

/************************************
 * @fn				- GPIO_Init
 // * @brief			- These function is used to handile the pin set mode
 * @
 * @param[in]		-  these holds the base address of the gpio port to which the pin belongs
 * @param[in]		-	these tell the that the port is enabled or disabled
 * @param[in]		-
 *
 * @return			- none
 *
 * @Note			-none
 */
void GPIO_Init(GPIO_Handel_t *pGPIOHandle) {
    uint32_t temp = 0;

    // 1. Configure the mode of GPIO (input, output, alt, analog)
    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG) {
        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
        pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));  // Clear mode bits
        pGPIOHandle->pGPIOx->MODER |= temp;  // Set mode bits
    } else {
        // Handle interrupt mode if needed
        if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_FT) {
        	EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        	EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        }
        else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_RT) {
        	EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        	EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        }
        else     if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_RFT) {
        	EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
         	EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        }

        uint8_t temp1= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber /4;
        uint8_t temp2= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber %4;
        uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle-> pGPIOx);
        SYSCFG_PCLK_EN();

        SYSCFG->EXTICR[temp1] = portcode << (temp2 *4);


        EXTI->IMR |= 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
    }

    // 2. Configure output type
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);  // Clear the bit
    pGPIOHandle->pGPIOx->OTYPER |= temp;  // Set the bit

    // 3. Configure speed
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));  // Clear speed bits
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;  // Set speed bits

    // 4. Configure pull-up/pull-down settings
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));  // Clear pull-up/pull-down bits
    pGPIOHandle->pGPIOx->PUPDR |= temp;  // Set pull-up/pull-down bits
}

/************************************
 * @fn				- GPIO_DeInit
 // * @brief			- These function is used to handile the pin reset mode
 * @
 * @param[in]		-  these holds the base address of the gpio port to which the pin belongs
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- none
 *
 * @Note			-none
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

			if (pGPIOx == GPIOA) {
				GPIOA_REG_RESET();
			} else if (pGPIOx == GPIOB) {
				GPIOB_REG_RESET();
			}
			else if (pGPIOx == GPIOC) {
				GPIOC_REG_RESET();
			} else if (pGPIOx == GPIOD) {
				GPIOD_REG_RESET();
			}
			else if (pGPIOx == GPIOE) {
				GPIOE_REG_RESET();
			} else if (pGPIOx == GPIOF) {
				GPIOF_REG_RESET();
			} else if (pGPIOx == GPIOG) {
				GPIOG_REG_RESET();
			} else if (pGPIOx == GPIOH) {
				GPIOH_REG_RESET();
			}

}

/*
 * data read and write
 */

/************************************
 * @fn				- GPIO_ReadFromInputPin
 // * @brief			- These function is used to handile the read pin functunalitys
 * @
 * @param[in]		-  these holds the base address pf the gpio port
 * @param[in]		-these function holds the pin number of that pin
 * @param[in]		-
 *
 * @return			- 0 or 1
 *
 * @Note			-none
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value =	(uint8_t)((pGPIOx -> IDR >> PinNumber) & 0x00000001);
	return value;
}

/************************************
 * @fn				- GPIO_ReadFromInputPort
 // * @brief			- These function is used to handile the read port functunalities
 * @
 * @param[in]		-  these holds the base address of the gpio port
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- 0 or 1
 *
 * @Note			-none
 */

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
		value =	(uint16_t)(pGPIOx -> IDR );
		return value;
}

/************************************
 * @fn				- GPIO_WriteToOutputPin
 // * @brief			- These function is used to handile the write  pin functunalities
 * @
 * @param[in]		-  these holds the base address of the gpio port
 * @param[in]		- these function holds the pin number of that port
 * @param[in]		- these will be sending the value as and output
 *
 * @return			- none
 *
 * @Note			-none
 */

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,uint8_t Value)
{
	if ( Value == GPIO_PIN_SET){
		pGPIOx ->ODR |= (1<<PinNumber);
	}
	else{
		pGPIOx ->ODR &= ~(1<<PinNumber);

	}
}

/************************************
 * @fn				- GPIO_WriteToOutputPort
 // * @brief			- These function is used to handile the write  port functunalities
 * @
 * @param[in]		-  these holds the base address of the gpio port
 * @param[in]		- these will be sending the value as and output
 * @param[in]		-
 *
 * @return			- none
 *
 * @Note			-none
 */

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx ->ODR =Value;
}

/************************************
 * @fn				- PIO_ToggleOutPin
 // * @brief			- These function is used to handile the toggling of an output
 * @
 * @param[in]		-  these holds the base address of the gpio port
 * @param[in]		- these function is used for the storing the pin number of that port
 * @param[in]		-
 *
 * @return			- none
 *
 * @Note			-none
 */

void GPIO_ToggleOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {
    pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * IRQ config
 */

/************************************
 * @fn				- GPIO_IRQConfig
 // * @brief			- These function is used to handile the configuration of the interapt
 * @
 * @param[in]		-
 * @param[in]		-
 * @param[in]		- these tell the that the port is enabled or disabled
 *
 * @return			- none
 *
 * @Note			-none
 */

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	if (EnorDi == ENABLE ){
		if (IRQNumber <= 31){
			*NVIC_ISER0 |= (1<< IRQNumber );
		}
		else if (IRQNumber >31 && IRQNumber < 64)
		{
			*NVIC_ISER1 |= (1<< (IRQNumber%32) );
		}
		else if(IRQNumber >=64 && IRQNumber <96)
		{
			*NVIC_ISER2 |= (1<< (IRQNumber%64) );
		}
	}
	else{
		if (IRQNumber <= 31){
			*NVIC_ICER0 |= (1<< IRQNumber );

				}
				else if (IRQNumber >31 && IRQNumber < 64)
				{
					*NVIC_ICER1 |= (1<< (IRQNumber%32) );

				}
				else if(IRQNumber >=64 && IRQNumber <96)
				{
					*NVIC_ICER2 |= (1<< (IRQNumber%64) );

				}

	}
}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber ,uint8_t IRQPriority)
{
	uint8_t iprx =IRQNumber /4;
	uint8_t iprx_section = IRQNumber %4;

	uint8_t shift_amount = (8* iprx_section) + (8- NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR + iprx*4) |= (IRQPriority << shift_amount);
}


/************************************
 * @fn				- GPIO_IRQHandling
 // * @brief			- These function is used to handile the handling  of the interapts
 * @
 * @param[in]		- it stores the pin number
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- none
 *
 * @Note			-none
 */

void GPIO_IRQHandling(uint8_t PinNumber)
{

}
