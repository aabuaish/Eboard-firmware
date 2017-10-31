
#include "digitalGPIO_driver.h"

/*****************************************************************
	* @brief	Initializes the GPIO pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	*gpio_digital_pin_conf_t: pointer to the pin conf structure sent by application
	* @return None
*****************************************************************/
void dr_gpio_digital_init(GPIO_Type *GPIOx, gpio_digital_pin_conf_t *gpio_pin_conf){
	
	uint32_t pin = gpio_pin_conf->pin;

	/*--------- unlocking the GPIO port ---------*/
	GPIOx->LOCK = 0x4C4F434B;

	/*--------- enable commiting to GPIO oprt ---------*/
	GPIOx->CR |= (1U<<pin);

	/*--------- enabling digital function of pin ---------*/
	GPIOx->DEN |= (1U<<pin);    // setting bit to enable digital operation for pin

	/*--------- configuring direction of GPIO pin ---------*/
	if(gpio_pin_conf->direction == GPIO_DIR_INPUT){
		GPIOx->DIR &= ~(1U<<pin);	// clearing direction bit for input
	}else{
		GPIOx->DIR |= (1U<<pin);	// seting direction bit for output
	}

  /*--------- configuring pull up resistor ---------*/
	if(gpio_pin_conf->pull_up_resis == GPIO_PULLUP_RESISTOR_FALSE){
		GPIOx->PUR &= ~(1U<<pin); // clearing the bit to disable pullup resistor
	}else{
		GPIOx->PUR |= (1U<<pin);  // setting the bit to enable pullup resistor
	}
	
  /*--------- configuring pull down resistor ---------*/
	if(gpio_pin_conf->pull_down_resis == GPIO_PULLDOWN_RESISTOR_FALSE){
		GPIOx->PDR &= ~(1U<<pin); // clearing the bit to disable pulldown resistor
	}else{
		GPIOx->PDR |= (1U<<pin);  // setting the bit to enable pulldown resistor
	}

  /*--------- configuring open drain operation ---------*/
	if(gpio_pin_conf->open_drain == GPIO_OPEN_DRAIN_FALSE){
		GPIOx->ODR &= ~(1U<<pin); // clearing the bit to disable open drain
	}else{
		GPIOx->ODR |= (1U<<pin);  // setting the bit to enables open drain
	}	
		
}

/*****************************************************************
	* @brief	Read the value of the pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be read
	* @return uint32_t with a value of 0 or 1
*****************************************************************/
uint32_t dr_pin_digital_read(GPIO_Type *GPIOx, uint32_t pin){
	uint32_t tmp = GPIOx->DATA;
	tmp = tmp&(1U<<pin);
  
	return (tmp>>pin);
}

/*****************************************************************
	* @brief	Write a value to the pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be written to
  * @param  val: value to be written to pin; 0 or 1
	* @return None
*****************************************************************/
void dr_pin_digital_write(GPIO_Type *GPIOx, uint32_t pin, uint32_t val){
	if(val>0){
		GPIOx->DATA_Bits[(1U<<pin)]	|= (1U<<pin);
	}else{
		GPIOx->DATA_Bits[(1U<<pin)]	&= ~(1U<<pin);
	}
}

