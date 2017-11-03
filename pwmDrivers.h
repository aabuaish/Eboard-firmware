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
  uint32_t freq;
  float duty;

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