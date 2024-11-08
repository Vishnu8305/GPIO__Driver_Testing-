#include 	"stm32l4xx.h"
#include 	"stm32l4xx_gpio_driver.h"
#define 	BTN_PRESSED LOW
#define		LOW 0
void delay(void) {
    for (uint32_t i = 0; i < 500000/2; i++);
}

int main(void) {
    // Enable the clock for GPIOB
    GPIO_PeriCLockControl(GPIOA, ENABLE);
    GPIO_PeriCLockControl(GPIOC, ENABLE);


    // Configure GPIOB Pin 5 as output
    GPIO_Handel_t gpio_handle, GPIOBtn;
    gpio_handle.pGPIOx = GPIOA;
    gpio_handle.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5; // Pin 5
    gpio_handle.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT; // Set as output mode
    gpio_handle.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST; // Fast speed
    gpio_handle.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP; // Push-pull output
    gpio_handle.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    		// No pull-up/pull-down
    GPIO_Init(&gpio_handle); // Initialize GPIO with the above configuration

    GPIOBtn.pGPIOx = GPIOC;
    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13; // Pin 5
    GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN; // Set as output mode
    GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST; // Fast speed
    GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    		// No pull-up/pull-down
    GPIO_Init(&GPIOBtn); // Initialize GPIO with the above configuration

    while (1) {
    	if(GPIO_ReadFromInputPin(GPIOC,GPIO_PIN_NO_13)== BTN_PRESSED)
    	{
        // Toggle GPIOB Pin 5
    	delay();
        GPIO_ToggleOutPin(GPIOA, GPIO_PIN_NO_5);
    }}

    return 0;
}
