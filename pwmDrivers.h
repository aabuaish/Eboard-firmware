#ifndef __PWM_DRIVERS__
#define __PWM_DRIVERS__

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
typedef struct {
  uint32_t pin;   // GPIO pin that generate the PWM signal
  uint32_t freq;  // frequency of the PWM signal
  float duty;     // duty cycle of the PWM signal; range from 0 to 100

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
  * @param	configStruct: structure that has pin configuration info
  * @return None
  * date: October 25
*****************************************************************/
void dr_pwm_init(PWM0_Type *pwmx, GPIOA_Type *GPIOx, pwm_pin_config_t *configStruct);

/*****************************************************************
  * @brief	Enables pwm pin
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pwm pin to be enabled
  * @return None
  * date: October 25
*****************************************************************/
void dr_pwm_enable(PWM0_Type *pwmx, GPIOA_Type *GPIOx, uint32_t pin);

/*****************************************************************
  * @brief	Disbales pwm pin
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pwm pin to be disabled
  * @return None
  * date: October 25
*****************************************************************/
void dr_pwm_disable(PWM0_Type *pwmx, GPIOA_Type *GPIOx, uint32_t pin);

/*****************************************************************
  * @brief	Set the value of PWM
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	configStruct: structure that has pin configuration info
  * @return None
  * date: October 25
*****************************************************************/
void dr_pwm_freq_duty_set(PWM0_Type *pwmx, GPIOA_Type *GPIOx, pwm_pin_config_t *configStruct);

#endif //__PWM_DRIVERS__