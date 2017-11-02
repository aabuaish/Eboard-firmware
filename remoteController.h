#ifndef __REMOTE_CONTROLLER__
#define __REMOTE_CONTROLLER__

#include <stdint.h>
#include "main.h"


/*************************************************************************************
*
*						1. Macros used for GPIO pin Initialization
*
*************************************************************************************/
// enable interrupt that reads remote controller signal 
#define REMOTE_CONTROLLER_DISABLE	(0U)
#define REMOTE_CONTROLLER_ENABLE	(1U)


/*************************************************************************************
*
*						2. Defining structure for Driver API
*
*************************************************************************************/
// Application should use Macros defined above to specify pin driver and configuration

//typedef struct{
//	
//	uint32_t pin;								// Specify the GPIO pin to be configured
//	uint32_t direction; 				// Specify input or output
//	uint32_t pull_up_resis;			// Specify to add internal pull-up resistor
//	uint32_t pull_down_resis;		// Specify to add internal pull-down resistor
//	uint32_t open_drain;			// Specify to configure as open drain or not
//	
//} gpio_digital_pin_conf_t;



/*************************************************************************************
*
*						3. Creating the API
*
*************************************************************************************/

/*****************************************************************
	* @brief	configures the GPIO pins that read the remote controller singal
	* @param	*GPIOx: specify which GPIO the remote controller receiver is connected to
	* @param	pin1 and pin2: specify which pin the remote controller receiver is connected to
	* @return None
*****************************************************************/
void io_remote_control_GPIO_conf(GPIOA_Type *GPIOx, uint32_t pin1, uint32_t pin2);

/*****************************************************************
	* @brief	enable or disable the interrupt that reads the speed controller comman
	*					by (un)masking the interrupt.
	* @param	enb: enable or disable the interrupt that reads the speed controller comman
	* @param	*GPIOx: specify which GPIO the remote controller receiver is connected to
	* @param	pin1 and pin2: specify which pin the remote controller receiver is connected to
	* @return None
*****************************************************************/
void io_remoteControl_enable(uint32_t enb, GPIOA_Type *GPIOx, uint32_t pin1, uint32_t pin2);

#endif //__REMOTE_CONTROLLER__