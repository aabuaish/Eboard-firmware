
#include "main.h"


/*****************************************************************
****************************Variables*****************************/
volatile uint32_t speedCommand;

/******************************************************************
*****************************************************************/




/*****************************************************************
  * @brief	This is the main function. 
  * @param	None
  * @return None
	* date: October 25th
*****************************************************************/
int main(){

/*------System clock configuration ------*/
	SystemCoreClockUpdate();
	SystemInit();
	
/*------Configuring SysTic interrupt to execute every 10 msec------*/
	SysTick->LOAD = SYS_CLOCK_HZ/100 - 1;
  SysTick->VAL = 0U;
  SysTick->CTRL |= (1U<<2) | (1U<<1) | (1U<<0);

/*------Configuring LED GPIO pins------*/	
	led_init();
	turn_off_led(GPIOF_AHB, LED_BLUE);
	turn_off_led(GPIOF_AHB, LED_RED);
	turn_off_led(GPIOF_AHB, LED_GREEN);

/*------Configuring external GPIOF pins 0 and 4 interrupts------*/
  _GPIOF_CLK_ENABLE();	// enable clock to GPIO port F
  _GPIOF_AHB_ENABLE();	// enable clock to AHB
	
  gpio_extern_int_conf_t externalInt;
  externalInt.pin = 0;
  externalInt.edgeOrLevel = EDGE_INT;
  externalInt.edgeTriger = FALLING_EDGE;
  externalInt.priority = 2;
  dr_gpio_extern_int_init(GPIOF_AHB, &externalInt);
	externalInt.pin = 4;
  dr_gpio_extern_int_init(GPIOF_AHB, &externalInt);

/*------Configuring GP timers and remote controller------*/
	dr_timer0_init_32();
	io_remote_control_GPIO_conf(GPIOB_AHB, 0, 1);

/*------Enabling interrupts ------*/
	__enable_interrupt();
	
/*------Configuring PWM ------*/
  pwm_init(PWM0, GPIOB_AHB, 6);
	
  while(1){
		
	}
  return 0;
}
