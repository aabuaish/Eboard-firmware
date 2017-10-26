
#include "digitalGPIO_driver.h"

/*****************************************************************
	* @brief	Initializes the GPIO pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	*gpio_pin_conf: pointer to the pin conf structure sent by application
	* @return None
*****************************************************************/
void dr_gpio_init(GPIO_Type *GPIOx, gpio_pin_conf_t *gpio_pin_conf){
	
	if(gpio_pin_conf->direction>0){
		GPIOx->DIR |= (1U<<gpio_pin_conf->pin);
	}
	
	if(gpio_pin_conf->digital>0){
		GPIOx->DEN |= (1U<<gpio_pin_conf->pin);
	}	

	if(gpio_pin_conf->pull_up_resis>0){
		GPIOx->PUR |= (1U<<gpio_pin_conf->pin);
	}
	
	if(gpio_pin_conf->pull_down_resis>0){
		GPIOx->PDR |= (1U<<gpio_pin_conf->pin);
	}
		
}

/*****************************************************************
	* @brief	Read the value of the pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be read
	* @return uint16_t with a value of 0 or 1
*****************************************************************/
uint32_t dr_pin_read(GPIO_Type *GPIOx, uint16_t pin){
	uint32_t tmp = GPIOx->DATA;
	tmp = tmp&(1U<<pin);
	uint32_t res = (tmp>>pin);
	return res;
}

/*****************************************************************
	* @brief	Read the value of the pin
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be written to
  * @param  val: value to be written to pin
	* @return None
*****************************************************************/
void dr_pin_write(GPIO_Type *GPIOx, uint16_t pin, uint16_t val){
	if(val>0){
		GPIOx->DATA_Bits[(1U<<pin)]	|= (1U<<pin);
	}else{
		GPIOx->DATA_Bits[(1U<<pin)]	&= ~(1U<<pin);
	}
}

