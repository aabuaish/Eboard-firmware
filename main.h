#ifndef __MAIN__
#define __MAIN__

#include <stdint.h>
#include <stdio.h>

#include "TM4C123.h"
#include "digitalGPIO_driver.h"
#include "int_handler.h"
#include "externGPIO_int.h"
#include "lm4f120h5qr.h"
#include "GPTimers.h"
#include "remoteController.h"
#include "onBoard_leds.h"
#include "pwmDrivers.h"


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

#endif //__MAIN__