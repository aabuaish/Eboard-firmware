
#include "main.h"

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
  gpio_pin_conf_t gpio_pin_conf;
  gpio_pin_conf.digital = GPIO_DIGITAL_TRUE;
  gpio_pin_conf.direction = GPIO_DIR_OUTPUT;
  gpio_pin_conf.pull_down_resis = GPIO_PULLDOWN_RESISTOR_FALSE;
  gpio_pin_conf.pull_up_resis = GPIO_PULLUP_RESISTOR_FALSE;
  gpio_pin_conf.pin = LED_RED;
	
	// initializing red led pin in GPIO port F
  dr_gpio_init(GPIOF_HS, &gpio_pin_conf);
	
	// initializing blue led pin in GPIO port F
  gpio_pin_conf.pin = LED_BLUE;
  dr_gpio_init(GPIOF_HS, &gpio_pin_conf);
	
	// initializing green led pin in GPIO port F
  gpio_pin_conf.pin = LED_GREEN;
  dr_gpio_init(GPIOF_HS, &gpio_pin_conf);
}

/*****************************************************************
  * @brief	This function is used to turn on the LED specified by pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be set
  * @return None
*****************************************************************/
void turn_on_led(GPIO_Type *GPIOx, uint32_t pin){
  dr_pin_write(GPIOx,  pin, 1);
}

/*****************************************************************
  * @brief	This function is used to turn off the LED specified by pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be set to zero
  * @return None
*****************************************************************/
void turn_off_led(GPIO_Type *GPIOx, uint32_t pin){
  dr_pin_write(GPIOx,  pin, 0);
}

/*****************************************************************
  * @brief	This function toggles the value of a pin. 
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to be toggled
  * @return None
*****************************************************************/
void toggle_led(GPIO_Type *GPIOx, uint32_t pin){
	uint32_t dummy = dr_pin_read(GPIOx,pin);
  dr_pin_write(GPIOx,  pin, (~dummy)&(1U) );
}


/*****************************************************************
  * @brief	This is the main function. 
  * @param	None
  * @return None
	* date: October 25th
*****************************************************************/
int main(){

/*------Configuring SysTic interrupt to execute every 0.5 sec------START*/
	SysTick->LOAD = SYS_CLOCK_HZ/2 - 1;
  SysTick->VAL = 0U;
  SysTick->CTRL |= (1U<<2) | (1U<<1) | (1U<<0);
	__enable_interrupt();
/*------Configuring SysTic interrupt to execute every 0.5 sec------END*/
	
	led_init();
	turn_off_led(GPIOF_HS, LED_BLUE);
	turn_off_led(GPIOF_HS, LED_RED);
	turn_off_led(GPIOF_HS, LED_GREEN);
	
	while(1){
		
	}
  return 0;
}
