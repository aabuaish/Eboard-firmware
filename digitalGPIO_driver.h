#ifndef __LED_DRIVER__
#define __LED_DRIVER__

#include <stdint.h>
#include "tm4c_cmsis.h"

/*************************************************************************************
*
*						1. Macros used for GPIO pin Initialization
*
*************************************************************************************/
// GPIO direction
#define GPIO_DIR_INPUT	(0U)
#define GPIO_DIR_OUTPUT	(1U)

// GPIO open drain
#define GPIO_OPEN_DRAIN_FALSE	(0U)
#define GPIO_OPEN_DRAIN_TRUE	(1U)

// GPIO pull-up resistor
#define GPIO_PULLUP_RESISTOR_FALSE	(0U)
#define GPIO_PULLUP_RESISTOR_TRUE		(1U)

// GPIO pull-down resistor
#define GPIO_PULLDOWN_RESISTOR_FALSE	(0U)
#define GPIO_PULLDOWN_RESISTOR_TRUE		(1U)

// GPIO digital enable
#define GPIO_DIGITAL_FALSE	(0U)
#define GPIO_DIGITAL_TRUE		(1U)


// function Macros to enable clocks to GPIO ports
#define _GPIOA_CLK_ENABLE()			(SYSCTL->RCGC2 |= (1U<<0) )
#define _GPIOB_CLK_ENABLE()			(SYSCTL->RCGC2 |= (1U<<1) )
#define _GPIOC_CLK_ENABLE()			(SYSCTL->RCGC2 |= (1U<<2) )
#define _GPIOD_CLK_ENABLE()			(SYSCTL->RCGC2 |= (1U<<3) )
#define _GPIOE_CLK_ENABLE()			(SYSCTL->RCGC2 |= (1U<<4) )
#define _GPIOF_CLK_ENABLE()			(SYSCTL->RCGC2 |= (1U<<5) )

// function Macros to enable AHB
#define _GPIOA_AHB_ENABLE()			(SYSCTL->GPIOHSCTL |= (1U<<0) )
#define _GPIOB_AHB_ENABLE()			(SYSCTL->GPIOHSCTL |= (1U<<1) )
#define _GPIOC_AHB_ENABLE()			(SYSCTL->GPIOHSCTL |= (1U<<2) )
#define _GPIOD_AHB_ENABLE()			(SYSCTL->GPIOHSCTL |= (1U<<3) )
#define _GPIOE_AHB_ENABLE()			(SYSCTL->GPIOHSCTL |= (1U<<4) )
#define _GPIOF_AHB_ENABLE()			(SYSCTL->GPIOHSCTL |= (1U<<5) )

/*************************************************************************************
*
*						2. Defining structure for Driver API
*
*************************************************************************************/
// Application should use Macros defined above to specify pin driver and configuration

typedef struct{
	
	uint32_t pin;								// Specify the GPIO pin to be configured
	uint32_t direction; 				// Specify input or output
	uint32_t digital;						// Specify if digital or not
	uint32_t pull_up_resis;			// Specify to add internal pull-up resistor
	uint32_t pull_down_resis;		// Specify to add internal pull-down resistor
	
} gpio_pin_conf_t;



/*************************************************************************************
*
*						3. Creating the API
*
*************************************************************************************/
/*****************************************************************
	* @brief	Initializes the GPIO pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	*gpio_pin_conf: pointer to the pin conf structure sent by application
	* @return None
*****************************************************************/
void dr_gpio_init(GPIO_Type *GPIOx, gpio_pin_conf_t *gpio_pin_conf);

/*****************************************************************
	* @brief	Read the value of the pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be read
	* @return None
*****************************************************************/
uint32_t dr_pin_read(GPIO_Type *GPIOx, uint16_t pin);

/*****************************************************************
	* @brief	Read the value of the pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be written to
  * @param  val: value to be written to pin
	* @return None
*****************************************************************/
void dr_pin_write(GPIO_Type *GPIOx, uint16_t pin, uint16_t val);

#endif //__LED_DRIVER__