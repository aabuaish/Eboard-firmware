
#include "externGPIO_int.h"


/*****************************************************************
	* @brief	Initializes the GPIO pin to be configured as an interrupt
	* @param	*GPIOx: base address of GPIO Port
	* @param	*gpio_pin_conf: pointer to the pin conf structure sent by application
	* @return None
*****************************************************************/
void dr_gpio_extern_int_init(GPIO_Type *GPIOx, gpio_extern_int_conf_t *gpio_pin_conf){
  uint32_t pin = gpio_pin_conf->pin;

/*-------- configuring digital properties --------*/
  gpio_digital_pin_conf_t digital_GPIO;
  digital_GPIO.pin = pin;
  digital_GPIO.direction = GPIO_DIR_INPUT;
  if(gpio_pin_conf->edgeTriger == FALLING_EDGE){
    digital_GPIO.pull_up_resis = GPIO_PULLUP_RESISTOR_TRUE;
    digital_GPIO.pull_down_resis = GPIO_PULLDOWN_RESISTOR_FALSE;
  }else if(gpio_pin_conf->edgeTriger == RISING_EEDGE){
    digital_GPIO.pull_up_resis = GPIO_PULLUP_RESISTOR_FALSE;
    digital_GPIO.pull_down_resis = GPIO_PULLDOWN_RESISTOR_TRUE;
  }else{  // both edges
    digital_GPIO.pull_up_resis = GPIO_PULLUP_RESISTOR_FALSE;
    digital_GPIO.pull_down_resis = GPIO_PULLDOWN_RESISTOR_FALSE;
  }
  digital_GPIO.open_drain = GPIO_OPEN_DRAIN_FALSE;
  dr_gpio_digital_init(GPIOx, &digital_GPIO);


/*-------- disabling all analog functions --------*/
  GPIOx->AFSEL &= ~(1U<<pin);
  GPIOx->PCTL &= ~(0xFU<<pin*4);
  GPIOx->AMSEL &= ~(0x1U<<pin);

/*-------- mask the interrupt before making changes and configuration --------*/
  dr_gpio_extern_int_mask(GPIOx, pin, MASK_INT_TRUE);

/*-------- configuring interrupt whether on edges of voltage levels --------*/
  if(gpio_pin_conf->edgeOrLevel == EDGE_INT){
    GPIOx->IS &= ~(1U<<pin);  // clearing the bit to configure bit as edge detection
  }else{
    GPIOx->IS |= (1U<<pin);   // setting the bit to configure bit as voltage levels detection
  }

/*-------- configuring interrupt edge detection --------*/
  if(gpio_pin_conf->edgeTriger == FALLING_EDGE){
    GPIOx->IBE &= ~(1U<<pin);   // clearing the bit disables both edge detection
    GPIOx->IEV &= ~(1U<<pin);   // clearing the bit enable both falling edge detection
  }else if(gpio_pin_conf->edgeTriger == RISING_EEDGE){
    GPIOx->IBE &= ~(1U<<pin);   // clearing the bit disables both edge detection
    GPIOx->IEV |= (1U<<pin);    // setting the bit enable both rising edge detection
  }else{  // both edges
    GPIOx->IBE |= (1U<<pin);    // setting the bit enables both edge detection
  }

/*-------- clear interrupt bit --------*/
  dr_gpio_extern_int_clear(GPIOx, pin);

/*-------- unmask the interrupt --------*/
  dr_gpio_extern_int_mask(GPIOx, pin, MASK_INT_FALSE);

/*-------- enabling GPIO interrupt --------*/
  dr_gpio_extern_int_enable(GPIOx);

/*-------- setting priorty of the interrupt --------*/
  dr_gpio_extern_int_priotery(GPIOx, gpio_pin_conf->priority);

/*-------- enabling processor interrupt --------*/
__enable_interrupt();
}



/*****************************************************************
	* @brief	This API allows the user to mask/unmask GPIO interrupts
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be read
	* @param	mask: used to specify whether on not mask an interrupt
	* @return None
*****************************************************************/
void dr_gpio_extern_int_mask(GPIO_Type *GPIOx, uint32_t pin, uint32_t mask){
  if(mask == MASK_INT_TRUE){
    GPIOx->IM &= ~(1U<<pin);      
  }else{
    GPIOx->IM |= (1U<<pin);
  }
}


/*****************************************************************
	* @brief	Clear the interrupt status register to allow interrupts to be triggered again
	* @param	*GPIOx: base address of GPIO Port
	* @param	pin: pin number to be written to
	* @return None
*****************************************************************/
void dr_gpio_extern_int_clear(GPIO_Type *GPIOx, uint32_t pin){
  GPIOx->ICR |= (1U<<pin);
}


/*****************************************************************
	* @brief	Enable interrupt to GPIO port
	* @param	GPIOx: base address of GPIO Port
	* @return None
*****************************************************************/
void dr_gpio_extern_int_enable(GPIO_Type *GPIOx){

  if(GPIOx == GPIOA || GPIOx == GPIOA_HS){
    NVIC_EN0_R |= (1U<<0);
  }else if(GPIOx == GPIOB || GPIOx == GPIOB_HS){
    NVIC_EN0_R |= (1U<<1);
  }else if(GPIOx == GPIOC || GPIOx == GPIOC_HS){
    NVIC_EN0_R |= (1U<<2);
  }else if(GPIOx == GPIOD || GPIOx == GPIOD_HS){
    NVIC_EN0_R |= (1U<<3);
  }else if(GPIOx == GPIOE || GPIOx == GPIOE_HS){
    NVIC_EN0_R |= (1U<<4);
  }else if(GPIOx == GPIOF || GPIOx == GPIOF_HS){
    NVIC_EN0_R |= (1U<<30);
  }

}

/*****************************************************************
	* @brief	Disable interrupt to GPIO port
	* @param	*GPIOx: pointer the GPIO port
	* @return None
*****************************************************************/
void dr_gpio_extern_int_disable(GPIO_Type *GPIOx){

  if(GPIOx == GPIOA || GPIOx == GPIOA_HS){
    NVIC_EN0_R &= ~(1U<<0);
  }else if(GPIOx == GPIOB || GPIOx == GPIOB_HS){
    NVIC_EN0_R &= ~(1U<<1);
  }else if(GPIOx == GPIOC || GPIOx == GPIOC_HS){
    NVIC_EN0_R &= ~(1U<<2);
  }else if(GPIOx == GPIOD || GPIOx == GPIOD_HS){
    NVIC_EN0_R &= ~(1U<<3);
  }else if(GPIOx == GPIOE || GPIOx == GPIOE_HS){
    NVIC_EN0_R &= ~(1U<<4);
  }else if(GPIOx == GPIOF || GPIOx == GPIOF_HS){
    NVIC_EN0_R &= ~(1U<<30);
  }

}

/*****************************************************************
	* @brief	Set priotery level from GPIO port
	* @param	port: GPIOx: base address of GPIO Port
	* @param	priotery: set priotery level; takes value from 0-7
	* @return None
*****************************************************************/
void dr_gpio_extern_int_priotery(GPIO_Type *GPIOx, uint32_t priority){
  
  if(GPIOx == GPIOA || GPIOx == GPIOA_HS){
    NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFFFF00)|(priority<<5);
  }else if(GPIOx == GPIOB || GPIOx == GPIOB_HS){
    NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF00FF)|(priority<<13);
  }else if(GPIOx == GPIOC || GPIOx == GPIOC_HS){
    NVIC_PRI0_R = (NVIC_PRI0_R&0xFF00FFFF)|(priority<<21);
  }else if(GPIOx == GPIOD || GPIOx == GPIOD_HS){
    NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|(priority<<29);
  }else if(GPIOx == GPIOE || GPIOx == GPIOE_HS){
    NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF00)|(priority<<5);
  }else if(GPIOx == GPIOF || GPIOx == GPIOF_HS){
    NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|(priority<<21);
  }

}