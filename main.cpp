
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


volatile uint32_t  raw;
volatile uint32_t  masked;
volatile uint32_t  val;
volatile uint32_t  reset = 0;
volatile uint32_t speedCommand = 0;
volatile uint32_t probe;
volatile uint32_t window = 0;

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
	
  _GPIOE_CLK_ENABLE();	// enable clock to GPIO port E
  _GPIOE_AHB_ENABLE();	// enable clock to AHB
	
  gpio_extern_int_conf_t externalInt;
  externalInt.pin = 0;
  externalInt.edgeOrLevel = EDGE_INT;
  externalInt.edgeTriger = FALLING_EDGE;
  externalInt.priority = 2;
  dr_gpio_extern_int_init(GPIOF_AHB, &externalInt);
	externalInt.pin = 4;
  dr_gpio_extern_int_init(GPIOF_AHB, &externalInt);

/*------Configuring GP timers ------*/
	dr_timer0_init_32();
	io_remote_control_GPIO_conf(GPIOB_AHB, 0, 1);
	// // fill in the strcture to configure the GPIO port
  // gpio_digital_pin_conf_t gpio_pin_conf;
  // gpio_pin_conf.direction = GPIO_DIR_INPUT;
  // gpio_pin_conf.pull_down_resis = GPIO_PULLDOWN_RESISTOR_FALSE;
  // gpio_pin_conf.pull_up_resis = GPIO_PULLUP_RESISTOR_FALSE;
  // gpio_pin_conf.open_drain = GPIO_OPEN_DRAIN_FALSE;
  // gpio_pin_conf.pin = 0;
	
	// // initializing red led pin in GPIO port F
  // dr_gpio_digital_init(GPIOB_AHB, &gpio_pin_conf);
	
	// // initializing blue led pin in GPIO port F
  // gpio_pin_conf.pin = 1;
  // dr_gpio_digital_init(GPIOB_AHB, &gpio_pin_conf);

/*------debugging pins ------*/
  _GPIOA_CLK_ENABLE();	// enable clock to GPIO port A
  _GPIOA_AHB_ENABLE();	// enable clock to AHB
  gpio_digital_pin_conf_t debug;
  debug.direction = GPIO_DIR_OUTPUT;
  debug.pull_down_resis = GPIO_PULLDOWN_RESISTOR_FALSE;
  debug.pull_up_resis = GPIO_PULLUP_RESISTOR_FALSE;
  debug.open_drain = GPIO_OPEN_DRAIN_FALSE;
  debug.pin = 2;
	
	// initializing red led pin in GPIO port F
  dr_gpio_digital_init(GPIOA_AHB, &debug);
	
	// initializing blue led pin in GPIO port F
  debug.pin = 3;
  dr_gpio_digital_init(GPIOA_AHB, &debug);
	
  debug.pin = 4;
  dr_gpio_digital_init(GPIOA_AHB, &debug);


/*------Enabling interrupts ------*/
	__enable_interrupt();
	
  uint32_t counter = 0;
	
  while(1){

		counter++;
    if(counter == 50000){
      val = TIMER0->TAV;
			counter = 0;
    }
		
		if(reset == 1){
			dr_timer0_enable(TIMER0_DISABLE);
			val = dr_timer0_read_val();
			dr_timer0_set_val(0);
			//TIMER0->CTL |= (1U<<0);
			val = dr_timer0_read_val();
		}
		//printf("dummy=%d\n",dummy);
		probe = GPIOB_AHB->MIS;
		
	}
  return 0;
}
