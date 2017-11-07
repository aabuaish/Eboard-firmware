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

/*****************************************************************
  * @brief	this function linearly maps a value from one range to another 
  * @param	x1, x2: values of limits on the first range
  * @param	y1, y2: values of limits on the second range
  * @param	val: input value to be mapped
  * @return   the mapped value from the first range to the second range
*****************************************************************/
uint32_t io_data_maping(float x1, float x2, float y1, float y2, float val);

#endif //__REMOTE_CONTROLLER__