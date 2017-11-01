
#ifndef __GPTIMERS__
#define __GPTIMERS__

#include <stdint.h>
#include "main.h"
/*************************************************************************************
*
*						1. Macros used for GPIO pin Initialization
*
*************************************************************************************/
// enalble to disable timer0
#define TIMER0_DISABLE	(0U)
#define TIMER0_ENABLE 	(1U)




/*************************************************************************************
*
*						2. Defining structure for Driver API
*
*************************************************************************************/
// none for now



/*************************************************************************************
*
*						3. Creating the API
*
*************************************************************************************/

/*****************************************************************
	* @brief	Initilize timer0 as a 32 bit timer
	* @param	None
	* @return None
*****************************************************************/
void dr_timer0_init_32();

/*****************************************************************
	* @brief	Enable or Disable the timer.
	* @param	enb: this take one of the defined directives above 
	* @return None
*****************************************************************/
void dr_timer0_enable(uint32_t enb);

/*****************************************************************
	* @brief  Manually set the value of timers
	* @param	val: value the timer should be set to
	* @return None
*****************************************************************/
void dr_timer0_set_val(uint32_t val);

/*****************************************************************
	* @brief  Read the value of timer
	* @param	none
	* @return the value of the timer
*****************************************************************/
uint32_t dr_timer0_read_val();

#endif //__GPTIMERS__