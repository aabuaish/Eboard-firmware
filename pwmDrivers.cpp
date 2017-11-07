
#include "pwmDrivers.h"
extern uint32_t probe1;
extern uint32_t probe2;

/*****************************************************************
  * @brief	This function initializes the PWM pin and module
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pin to configure as pwm
  * @return None
  * date: October 25
*****************************************************************/
void dr_pwm_init(PWM0_Type *pwmx, GPIOA_Type *GPIOx, pwm_pin_config_t *configStruct){
  float tmp = configStruct->duty;
  if(tmp>100){
    tmp = 100;
  }else if(tmp<0){
    tmp = 0;
  }
  uint32_t pin = configStruct->pin;
  uint32_t loadVal = SYS_CLOCK_HZ/2/(configStruct->freq) ;
  uint32_t cmpVal = (uint32_t)((100-tmp)/100*loadVal - 1);

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
  
  SYSCTL->RCC |= (1U<<20); // enabling PWM clock devider

  SYSCTL->RCC = ( SYSCTL->RCC&~(0x7U<<17) )|(0<<17); // specifiying the divsion value

  if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){ // enabling the clock to the associated GPIO port

    if(pin==6){
      pwmx->_1_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_1_GENA = 0x0000008C; // configring the PWM
      pwmx->_1_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_1_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_1_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<2); // enabling the PWM master controller
    }else if(pin==7){
      pwmx->_1_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_1_GENB = 0x0000080C; // configring the PWM
      pwmx->_1_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_1_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_1_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<3); // enabling the PWM master controller      
    }

  }else if(GPIOx == GPIOB || GPIOx == GPIOB_AHB){
    if(pin==6){
      pwmx->_0_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_0_GENA = 0x0000008C; // configring the PWM
      pwmx->_0_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_0_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_0_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<0); // enabling the PWM master controller
    }else if(pin==7){
      pwmx->_0_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_0_GENB = 0x0000080C; // configring the PWM
      pwmx->_0_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_0_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_0_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<1); // enabling the PWM master controller      
    }else if(pin==4){
      pwmx->_1_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_1_GENA = 0x0000008C; // configring the PWM
      pwmx->_1_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_1_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_1_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<2); // enabling the PWM master controller      
    }else if(pin==5){
      pwmx->_1_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_1_GENB = 0x0000080C; // configring the PWM
      pwmx->_1_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_1_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_1_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<3); // enabling the PWM master controller      
    }

  }else if(GPIOx == GPIOC || GPIOx == GPIOC_AHB){

    if(pin==4){
      pwmx->_3_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_3_GENA = 0x0000008C; // configring the PWM
      pwmx->_3_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_3_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_3_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<6); // enabling the PWM master controller
    }else if(pin==5){
      pwmx->_3_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_3_GENB = 0x0000080C; // configring the PWM
      pwmx->_3_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_3_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_3_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<7); // enabling the PWM master controller      
    }

  }else if(GPIOx == GPIOD || GPIOx == GPIOD_AHB){

    if(pin==0 && pwmx==PWM0){
      pwmx->_3_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_3_GENA = 0x0000008C; // configring the PWM
      pwmx->_3_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_3_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_3_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<6); // enabling the PWM master controller
    }else if(pin==1 && pwmx==PWM0){
      pwmx->_3_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_3_GENB = 0x0000080C; // configring the PWM
      pwmx->_3_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_3_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_3_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<7); // enabling the PWM master controller      
    }else if(pin==0 && pwmx==PWM1){
      pwmx->_0_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_0_GENA = 0x0000008C; // configring the PWM
      pwmx->_0_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_0_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_0_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<0); // enabling the PWM master controller
    }else if(pin==1 && pwmx==PWM1){
      pwmx->_0_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_0_GENB = 0x0000080C; // configring the PWM
      pwmx->_0_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_0_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_0_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<1); // enabling the PWM master controller      
    }

  }else if(GPIOx == GPIOE || GPIOx == GPIOE_AHB){

    if(pin==4 && pwmx==PWM0){
      pwmx->_2_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_2_GENA = 0x0000008C; // configring the PWM
      pwmx->_2_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_2_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_2_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<4); // enabling the PWM master controller
    }else if(pin==5 && pwmx==PWM0){
      pwmx->_2_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_2_GENB = 0x0000080C; // configring the PWM
      pwmx->_2_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_2_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_2_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<5); // enabling the PWM master controller      
    }else if(pin==4 && pwmx==PWM1){
      pwmx->_1_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_1_GENA = 0x0000008C; // configring the PWM
      pwmx->_1_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_1_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_1_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<2); // enabling the PWM master controller
    }else if(pin==5 && pwmx==PWM1){
      pwmx->_1_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_1_GENB = 0x0000080C; // configring the PWM
      pwmx->_1_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_1_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_1_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<3); // enabling the PWM master controller      
    }

  }else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB){

    if(pin==0){
      pwmx->_2_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_2_GENA = 0x0000008C; // configring the PWM
      pwmx->_2_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_2_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_2_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<4); // enabling the PWM master controller
    }else if(pin==1){
      pwmx->_2_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_2_GENB = 0x0000080C; // configring the PWM
      pwmx->_2_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_2_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_2_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<5); // enabling the PWM master controller      
    }else if(pin==2){
      pwmx->_3_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_3_GENA = 0x0000008C; // configring the PWM
      pwmx->_3_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_3_CMPA = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_3_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<6); // enabling the PWM master controller      
    }else if(pin==3){
      pwmx->_3_CTL &= ~(1U<<0); // disabling PWM generator block
      pwmx->_3_GENB = 0x0000080C; // configring the PWM
      pwmx->_3_LOAD = loadVal; // seting the timer load value to specify the desired freq.
      pwmx->_3_CMPB = cmpVal; // specify comp value to specify the duty cycle
      pwmx->_3_CTL |= (1U<<0); // enabling the PWM generator block
      pwmx->ENABLE |= (1U<<7); // enabling the PWM master controller      
    }

  } // end of else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB)

} // end of dr_pwm_init()

/*****************************************************************
  * @brief	Enables pwm pin
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pwm pin to be enabled
  * @return None
  * date: October 25
*****************************************************************/
void dr_pwm_enable(PWM0_Type *pwmx, GPIOA_Type *GPIOx, uint32_t pin){
  if(pwmx == PWM0){

    if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){

    }else if(GPIOx == GPIOB || GPIOx == GPIOB_AHB){

      if(pin==6){
        pwmx->ENABLE |= (1U<<0);
      }else if(pin==7){
        pwmx->ENABLE |= (1U<<1);
      }else if(pin==4){
        pwmx->ENABLE |= (1U<<2);
      }else if(pin==5){
        pwmx->ENABLE |= (1U<<3);
      }

    }else if(GPIOx == GPIOC || GPIOx == GPIOC_AHB){

      if(pin==4){
        pwmx->ENABLE |= (1U<<6);
      }else if(pin==5){
        pwmx->ENABLE |= (1U<<7);
      }

    }else if(GPIOx == GPIOD || GPIOx == GPIOD_AHB){

      if(pin==0){
        pwmx->ENABLE |= (1U<<6);
      }else if(pin==1){
        pwmx->ENABLE |= (1U<<7);
      }

    }else if(GPIOx == GPIOE || GPIOx == GPIOE_AHB){

      if(pin==4){
        pwmx->ENABLE |= (1U<<4);
      }else if(pin==5){
        pwmx->ENABLE |= (1U<<5);
      }

    }else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB){
      
    }

  }else if(pwmx == PWM1){

    if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){

      if(pin==6){
        pwmx->ENABLE |= (1U<<2);
      }else if(pin==7){
        pwmx->ENABLE |= (1U<<3);
      }

    }else if(GPIOx == GPIOB || GPIOx == GPIOB_AHB){
      
    }else if(GPIOx == GPIOC || GPIOx == GPIOC_AHB){
      
    }else if(GPIOx == GPIOD || GPIOx == GPIOD_AHB){

      if(pin==0){
        pwmx->ENABLE |= (1U<<0);
      }else if(pin==1){
        pwmx->ENABLE |= (1U<<1);
      }

    }else if(GPIOx == GPIOE || GPIOx == GPIOE_AHB){

      if(pin==4){
        pwmx->ENABLE |= (1U<<2);
      }else if(pin==5){
        pwmx->ENABLE |= (1U<<3);
      }

    }else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB){

      if(pin==0){
        pwmx->ENABLE |= (1U<<4);
      }else if(pin==1){
        pwmx->ENABLE |= (1U<<5);
      }else if(pin==2){
        pwmx->ENABLE |= (1U<<6);
      }else if(pin==3){
        pwmx->ENABLE |= (1U<<7);
      }

    }

  } // end of else if(pwmx == PWM1)
}// end of function

/*****************************************************************
  * @brief	Disbales pwm pin
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	pin: pwm pin to be disabled
  * @return None
  * date: October 25
*****************************************************************/
void dr_pwm_disable(PWM0_Type *pwmx, GPIOA_Type *GPIOx, uint32_t pin){
  if(pwmx == PWM0){

    if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){

    }else if(GPIOx == GPIOB || GPIOx == GPIOB_AHB){

      if(pin==6){
        pwmx->ENABLE &= ~(1U<<0);
      }else if(pin==7){
        pwmx->ENABLE &= ~(1U<<1);
      }else if(pin==4){
        pwmx->ENABLE &= ~(1U<<2);
      }else if(pin==5){
        pwmx->ENABLE &= ~(1U<<3);
      }

    }else if(GPIOx == GPIOC || GPIOx == GPIOC_AHB){

      if(pin==4){
        pwmx->ENABLE &= ~(1U<<6);
      }else if(pin==5){
        pwmx->ENABLE &= ~(1U<<7);
      }

    }else if(GPIOx == GPIOD || GPIOx == GPIOD_AHB){

      if(pin==0){
        pwmx->ENABLE &= ~(1U<<6);
      }else if(pin==1){
        pwmx->ENABLE &= ~(1U<<7);
      }

    }else if(GPIOx == GPIOE || GPIOx == GPIOE_AHB){

      if(pin==4){
        pwmx->ENABLE &= ~(1U<<4);
      }else if(pin==5){
        pwmx->ENABLE &= ~(1U<<5);
      }

    }else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB){
      
    }

  }else if(pwmx == PWM1){

    if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){

      if(pin==6){
        pwmx->ENABLE &= ~(1U<<2);
      }else if(pin==7){
        pwmx->ENABLE &= ~(1U<<3);
      }

    }else if(GPIOx == GPIOB || GPIOx == GPIOB_AHB){
      
    }else if(GPIOx == GPIOC || GPIOx == GPIOC_AHB){
      
    }else if(GPIOx == GPIOD || GPIOx == GPIOD_AHB){

      if(pin==0){
        pwmx->ENABLE &= ~(1U<<0);
      }else if(pin==1){
        pwmx->ENABLE &= ~(1U<<1);
      }

    }else if(GPIOx == GPIOE || GPIOx == GPIOE_AHB){

      if(pin==4){
        pwmx->ENABLE &= ~(1U<<2);
      }else if(pin==5){
        pwmx->ENABLE &= ~(1U<<3);
      }

    }else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB){

      if(pin==0){
        pwmx->ENABLE &= ~(1U<<4);
      }else if(pin==1){
        pwmx->ENABLE &= ~(1U<<5);
      }else if(pin==2){
        pwmx->ENABLE &= ~(1U<<6);
      }else if(pin==3){
        pwmx->ENABLE &= ~(1U<<7);
      }

    }

  } // end of else if(pwmx == PWM1)
}// end of function


/*****************************************************************
  * @brief	Set the value of PWM
  * @param	*pwm: this is a pointer to the PWM module
  * @param	*GPIOx: pointer the GPIO port
  * @param	duty: value of duty cycle from 0 to 100 %
  * @return None
  * date: October 25
*****************************************************************/
void dr_pwm_freq_duty_set(PWM0_Type *pwmx, GPIOA_Type *GPIOx, pwm_pin_config_t *configStruct){
  float tmp = configStruct->duty;
  if(tmp>100){
    tmp = 100;
  }else if(tmp<0){
    tmp = 0;
  }
  uint32_t pin = configStruct->pin;
  uint32_t loadVal = SYS_CLOCK_HZ/2/(configStruct->freq) ;
  uint32_t cmpVal = (uint32_t)((100-tmp)/100*loadVal - 1);

if(pwmx == PWM0){

    if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){

    }else if(GPIOx == GPIOB || GPIOx == GPIOB_AHB){

      if(pin==6){
        pwmx->_0_LOAD = loadVal;
        pwmx->_0_CMPA = cmpVal;
      }else if(pin==7){
        pwmx->_0_LOAD = loadVal;
        pwmx->_0_CMPB = cmpVal;
      }else if(pin==4){
        pwmx->_1_LOAD = loadVal;
        pwmx->_1_CMPA = cmpVal;
      }else if(pin==5){
        pwmx->_1_LOAD = loadVal;
        pwmx->_1_CMPB = cmpVal;
      }

    }else if(GPIOx == GPIOC || GPIOx == GPIOC_AHB){

      if(pin==4){
        pwmx->_3_LOAD = loadVal;
        pwmx->_3_CMPA = cmpVal;
      }else if(pin==5){
        pwmx->_3_LOAD = loadVal;
        pwmx->_3_CMPB = cmpVal;
      }

    }else if(GPIOx == GPIOD || GPIOx == GPIOD_AHB){

      if(pin==0){
        pwmx->_3_LOAD = loadVal;
        pwmx->_3_CMPA = cmpVal;
      }else if(pin==1){
        pwmx->_3_LOAD = loadVal;
        pwmx->_3_CMPB = cmpVal;
      }

    }else if(GPIOx == GPIOE || GPIOx == GPIOE_AHB){

      if(pin==4){
        pwmx->_2_LOAD = loadVal;
        pwmx->_2_CMPA = cmpVal;
      }else if(pin==5){
        pwmx->_2_LOAD = loadVal;
        pwmx->_2_CMPB = cmpVal;
      }

    }else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB){
      
    }

  }else if(pwmx == PWM1){

    if(GPIOx == GPIOA || GPIOx == GPIOA_AHB){

      if(pin==6){
        pwmx->_1_LOAD = loadVal;
        pwmx->_1_CMPA = cmpVal;
      }else if(pin==7){
        pwmx->_1_LOAD = loadVal;
        pwmx->_1_CMPB = cmpVal;
      }

    }else if(GPIOx == GPIOB || GPIOx == GPIOB_AHB){
      
    }else if(GPIOx == GPIOC || GPIOx == GPIOC_AHB){
      
    }else if(GPIOx == GPIOD || GPIOx == GPIOD_AHB){

      if(pin==0){
        pwmx->_0_LOAD = loadVal;
        pwmx->_0_CMPA = cmpVal;
      }else if(pin==1){
        pwmx->_0_LOAD = loadVal;
        pwmx->_0_CMPB = cmpVal;
      }

    }else if(GPIOx == GPIOE || GPIOx == GPIOE_AHB){

      if(pin==4){
        pwmx->_1_LOAD = loadVal;
        pwmx->_1_CMPA = cmpVal;
      }else if(pin==5){
        pwmx->_1_LOAD = loadVal;
        pwmx->_1_CMPB = cmpVal;
      }

    }else if(GPIOx == GPIOF || GPIOx == GPIOF_AHB){

      if(pin==0){
        pwmx->_2_LOAD = loadVal;
        pwmx->_2_CMPA = cmpVal;
      }else if(pin==1){
        pwmx->_2_LOAD = loadVal;
        pwmx->_2_CMPB = cmpVal;
      }else if(pin==2){
        pwmx->_3_LOAD = loadVal;
        pwmx->_3_CMPA = cmpVal;
      }else if(pin==3){
        pwmx->_3_LOAD = loadVal;
        pwmx->_3_CMPB = cmpVal;
      }

    }

  } // end of else if(pwmx == PWM1)

} // end of function dr_pwm_freq_duty_set()