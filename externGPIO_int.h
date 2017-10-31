
#ifndef __EXTERN_GPOI_INT__
#define __EXTERN_GPOI_INT__

#include <stdint.h>
#include "main.h"

/*************************************************************************************
*
*						1. Macros used for GPIO pin Initialization
*
*************************************************************************************/
// edge or voltage level detection
#define EDGE_INT	(0U)
#define LEVEL_INT	(1U)

// detect on which edge
#define FALLING_EDGE	(0U)
#define RISING_EEDGE	(1U)
#define RISING_AND_FALLING_EDGE	(2U)

// Masking interupprts
#define MASK_INT_TRUE	  (0U)
#define MASK_INT_FALSE	(1U)



/*************************************************************************************
*
*						2. Defining structure for Driver API
*
*************************************************************************************/
// Application should use Macros defined above to specify pin driver and configuration

typedef struct{
	
	uint32_t pin;           // Specify the GPIO pin to be configured
	uint32_t edgeOrLevel;   // Specify whether to detect on edge or voltage level
	uint32_t edgeTriger;		// Specify on which edge to triger the interrupt on
  uint32_t priority;      // Specify the priotery of the interrupt 0-7

} gpio_extern_int_conf_t;



/*************************************************************************************
*
*						3. Creating the API
*
*************************************************************************************/
/*****************************************************************
	* @brief	Initializes the GPIO pin to be configured as an interrupt
	* @param	*GPIOx: base address of GPIO Port
	* @param	*gpio_pin_conf: pointer to the pin conf structure sent by application
	* @return None
*****************************************************************/
void dr_gpio_extern_int_init(GPIOA_Type *GPIOx, gpio_extern_int_conf_t *gpio_pin_conf);

/*****************************************************************
	* @brief	This API allows the user to mask/unmask GPIO interrupts
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be read
	* @param	mask: used to specify whether on not mask an interrupt
	* @return None
*****************************************************************/
void dr_gpio_extern_int_mask(GPIOA_Type *GPIOx, uint32_t pin, uint32_t mask);

/*****************************************************************
	* @brief	Clear the interrupt status register to allow interrupts to be triggered again
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be written to
	* @return None
*****************************************************************/
void dr_gpio_extern_int_clear(GPIOA_Type *GPIOx, uint32_t pin);

/*****************************************************************
	* @brief	Enable interrupt to GPIO port
	* @param	*GPIOx: pointer the GPIO port
	* @return None
*****************************************************************/
void dr_gpio_extern_int_enable(GPIOA_Type *GPIOx);

/*****************************************************************
	* @brief	Disable interrupt to GPIO port
	* @param	*GPIOx: pointer the GPIO port
	* @return None
*****************************************************************/
void dr_gpio_extern_int_disable(GPIOA_Type *GPIOx);

/*****************************************************************
	* @brief	Set priotery level from GPIO port
	* @param	port: a charecter specifies which port to enable;
				it's a char=> 'A', 'B', 'C', 'D', 'F'
	* @param	priotery: set priotery level; takes value from 0-7
	* @return None
*****************************************************************/
void dr_gpio_extern_int_priotery(GPIOA_Type *GPIOx, uint32_t priotery);


#endif //__EXTERN_GPOI_INT__