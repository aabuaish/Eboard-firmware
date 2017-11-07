
#include "onBoard_leds.h"

/*****************************************************************
  * @brief	This function initializes and configures the GPIO pins. 
  * @param	None
  * @return None
  * date: October 25
*****************************************************************/
void led_init(void){
  _GPIOF_CLK_ENABLE();	// enable clock to GPIO port F
  _GPIOF_AHB_ENABLE();	// enable clock to AHB
  
  // fill in the strcture to configure the GPIO port
  gpio_digital_pin_conf_t gpio_pin_conf;
  gpio_pin_conf.direction = GPIO_DIR_OUTPUT;
  gpio_pin_conf.pull_down_resis = GPIO_PULLDOWN_RESISTOR_FALSE;
  gpio_pin_conf.pull_up_resis = GPIO_PULLUP_RESISTOR_FALSE;
  gpio_pin_conf.pin = LED_RED;
  
  // initializing red led pin in GPIO port F
  dr_gpio_digital_init(GPIOF_AHB, &gpio_pin_conf);
  
  // initializing blue led pin in GPIO port F
  gpio_pin_conf.pin = LED_BLUE;
  dr_gpio_digital_init(GPIOF_AHB, &gpio_pin_conf);
  
  // initializing green led pin in GPIO port F
  gpio_pin_conf.pin = LED_GREEN;
  dr_gpio_digital_init(GPIOF_AHB, &gpio_pin_conf);
}

/*****************************************************************
  * @brief	This function is used to turn on the LED specified by pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be set
  * @return None
*****************************************************************/
void turn_on_led(GPIOA_Type *GPIOx, uint32_t pin){
  dr_pin_digital_write(GPIOx,  pin, 1);
}

/*****************************************************************
  * @brief	This function is used to turn off the LED specified by pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be set to zero
  * @return None
*****************************************************************/
void turn_off_led(GPIOA_Type *GPIOx, uint32_t pin){
  dr_pin_digital_write(GPIOx,  pin, 0);
}

/*****************************************************************
  * @brief	This function toggles the value of a pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be toggled
  * @return None
*****************************************************************/
void toggle_led(GPIOA_Type *GPIOx, uint32_t pin){
  uint32_t dummy = dr_pin_digital_read(GPIOx,pin);
  dr_pin_digital_write(GPIOx,  pin, (~dummy)&(1U) );
}