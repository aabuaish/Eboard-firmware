#ifndef __ON_BOARD_LEDS__
#define __ON_BOARD_LEDS__

#include "main.h"

/*************************************************************************************
*
*						1. Macros used for GPIO pin Initialization
*
*************************************************************************************/


/*************************************************************************************
*
*						2. Defining structure for Driver API
*
*************************************************************************************/


/*************************************************************************************
*
*						3. Creating the API
*
*************************************************************************************/

/*****************************************************************
  * @brief	This function initializes and configures the GPIO pins. 
  * @param	None
  * @return None
  * date: October 25
*****************************************************************/
void led_init(void);

/*****************************************************************
  * @brief	This function is used to turn on the LED specified by pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be set
  * @return None
*****************************************************************/
void turn_on_led(GPIOA_Type *GPIOx, uint32_t pin);

/*****************************************************************
  * @brief	This function is used to turn off the LED specified by pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be set to zero
  * @return None
*****************************************************************/
void turn_off_led(GPIOA_Type *GPIOx, uint32_t pin);

/*****************************************************************
  * @brief	This function toggles the value of a pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be toggled
  * @return None
*****************************************************************/
void toggle_led(GPIOA_Type *GPIOx, uint32_t pin);



#endif //__ON_BOARD_LEDS__