#ifndef __MAIN__
#define __MAIN__

#include <stdint.h>
#include <stdio.h>

#include "tm4c_cmsis.h"
#include "digitalGPIO_driver.h"
#include "int_handler.h"
#include "externGPIO_int.h"
#include "lm4f120h5qr.h"


/*****************************************************************
  * @brief	This function initializes and configures the GPIO pins. 
  * @param	None
  * @return None
*****************************************************************/
void led_init(void);

/*****************************************************************
  * @brief	This function is used to turn on the LED specified by pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be set
  * @return None
*****************************************************************/
void turn_on_led(GPIO_Type *GPIOx, uint32_t pin);

/*****************************************************************
  * @brief	This function is used to turn off the LED specified by pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be set to zero
  * @return None
*****************************************************************/
void turn_off_led(GPIO_Type *GPIOx, uint32_t pin);

/*****************************************************************
  * @brief	This function toggles the value of a pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be toggled
  * @return None
*****************************************************************/
void toggle_led(GPIO_Type *GPIOx, uint32_t pin);

#endif //__MAIN__