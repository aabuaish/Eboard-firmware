
#include "remoteController.h"

/*****************************************************************
	* @brief	enable or disable the interrupt that reads the speed controller comman
	*					by (un)masking the interrupt.
	* @param	enb: enable or disable the interrupt that reads the speed controller command
	* @param	*GPIOx: specify which GPIO the remote controller receiver is connected to
	* @param	pin1 and pin2: specify which pin the remote controller receiver is connected to
	* @return None
*****************************************************************/
void io_remoteControl_enable(uint32_t enb, GPIOA_Type *GPIOx, uint32_t pin1, uint32_t pin2){
	if(enb == REMOTE_CONTROLLER_DISABLE){
		dr_gpio_extern_int_mask(GPIOx, pin1, MASK_INT_TRUE);
    dr_gpio_extern_int_mask(GPIOx, pin2, MASK_INT_TRUE);
	}else if(enb == REMOTE_CONTROLLER_ENABLE){
		dr_gpio_extern_int_mask(GPIOx, pin1, MASK_INT_FALSE);
    dr_gpio_extern_int_mask(GPIOx, pin2, MASK_INT_FALSE);
	}
}

/*****************************************************************
	* @brief	configures the GPIO pins that read the remote controller singal
	* @param	*GPIOx: specify which GPIO the remote controller receiver is connected to
	* @param	pin1 and pin2: specify which pin the remote controller receiver is connected to
	* @return None
*****************************************************************/
void io_remote_control_GPIO_conf(GPIOA_Type *GPIOx, uint32_t pin1, uint32_t pin2){

  if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){
		_GPIOA_CLK_ENABLE();
		_GPIOA_AHB_ENABLE();
  }else if(GPIOx == GPIOB || GPIOx == GPIOB_AHB){
		_GPIOB_CLK_ENABLE();
		_GPIOB_AHB_ENABLE();
  }else if(GPIOx == GPIOC || GPIOx == GPIOC_AHB){
		_GPIOC_CLK_ENABLE();
		_GPIOC_AHB_ENABLE();
  }else if(GPIOx == GPIOD || GPIOx == GPIOD_AHB){
		_GPIOD_CLK_ENABLE();
		_GPIOD_AHB_ENABLE();
  }else if(GPIOx == GPIOE || GPIOx == GPIOE_AHB){
		_GPIOE_CLK_ENABLE();
		_GPIOE_AHB_ENABLE();
  }else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB){
		_GPIOF_CLK_ENABLE();
		_GPIOF_AHB_ENABLE();
  }	
	 
  gpio_extern_int_conf_t externalInt;
  externalInt.pin = pin1;
  externalInt.edgeOrLevel = EDGE_INT;
  externalInt.edgeTriger = RISING_EDGE;
  externalInt.priority = 2;
  dr_gpio_extern_int_init(GPIOx, &externalInt);
	
	externalInt.edgeTriger = FALLING_EDGE;
	externalInt.pin = pin2;
  dr_gpio_extern_int_init(GPIOx, &externalInt);	
}