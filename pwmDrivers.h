#ifndef __PWM_DRIVERS__
#define __PWM_DRIVERS__

#include "main.h"

/*************************************************************************************
*
*						1. Macros used for GPIO pin Initialization
*
*************************************************************************************/
// PWM generators
#define PWM_GEN0_DR  (0U)
#define PWM_GEN1_DR  (0U)
#define PWM_GEN2_DR  (0U)
#define PWM_GEN3_DR  (0U)

// PWM pin
#define PWM_PIN0_DR  (0U)
#define PWM_PIN1_DR  (1U)
#define PWM_PIN2_DR  (2U)
#define PWM_PIN3_DR  (3U)
#define PWM_PIN4_DR  (4U)
#define PWM_PIN5_DR  (5U)
#define PWM_PIN6_DR  (6U)
#define PWM_PIN7_DR  (7U)

/*************************************************************************************
*
*						2. Defining structure for Driver API
*
*************************************************************************************/
typedef struct {
  uint32_t pin;
  uint32_t loadVal;
  uint32_t cmpVal;

} pwm_pin_config_t;

/*************************************************************************************
*
*						3. Creating the API
*
*************************************************************************************/

/*****************************************************************
  * @brief	This function initializes the PWM pin and module
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to configure as pwm
  * @return None
	* date: October 25
*****************************************************************/
void pwm_init(PWM0_Type *pwmx, GPIOA_Type *GPIOx, uint32_t pin);



#endif //__PWM_DRIVERS__