
#include "pwmDrivers.h"

/*****************************************************************
  * @brief	This function initializes the PWM pin and module
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to configure as pwm
  * @return None
	* date: October 25
*****************************************************************/
void pwm_init(PWM0_Type *pwmx, GPIOA_Type *GPIOx, uint32_t pin){

  SYSCTL->RCGC0 |= (1U<<20); // enabling gating to the PWM module

  if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){ // enabling the clock to the associated GPIO port
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

  GPIOx->DIR |= (1U<<pin); // configureing pin to be an output

  GPIOx->DEN |= (1U<<pin); // configureing pin to be digital
  
  GPIOx->AFSEL |= (1U<<pin);  // configure the pin to have alternate functions
  
  if(pwmx == PWM0){
    GPIOx->PCTL = ( GPIOx->PCTL&~(0xFU<<pin*4) )|(0x4U<<pin*4);  // configuring pin to PWM
  }else{
    GPIOx->PCTL = ( GPIOx->PCTL&~(0xFU<<pin*5) )|(0x4U<<pin*5);  // configuring pin to PWM
  }
  
  SYSCTL->RCC |= (1U<<20); // enabling PWM clock devider (in API)

  SYSCTL->RCC = ( SYSCTL->RCC&~(0x7U<<17) )|(0<<17); // specifiying the divsion value (in API)
  
  pwmx->_0_CTL &= ~(1U<<0); // disabling PWM generator block

  pwmx->_0_GENA = 0x0000008C; // configring the PWM

  pwmx->_0_LOAD = 0x0000013F; // seting the timer load value to specify the desired freq.

  pwmx->_0_CMPA = 0x000000EF; // specify comp value to specify the duty cycle

  pwmx->_0_CTL |= (1U<<0); // enabling the PWM generator block

  pwmx->ENABLE |= (1U<<0)|(1U<<1); // enabling the PWM master controller


}
