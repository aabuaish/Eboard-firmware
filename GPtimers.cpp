
#include "GPTimers.h"


/*****************************************************************
	* @brief	Initilize timer0 as a 32 bit timer
	* @param	None
	* @return None
*****************************************************************/
void dr_timer0_init_32(){
  SYSCTL->RCGCTIMER |= (1U<<0); // turning on clock to GP timer module
	TIMER0->CTL &= ~(1U<<0); // disble timers A and B
	TIMER0->CTL &= ~(1U<<8);

	TIMER0->CFG = 0x00000000; // configure the timers to concatenate

	TIMER0->CTL |= (1U<<1); // pausing the timer when debugger is active

	TIMER0->TAMR = (TIMER0->TAMR&~0x00000003)|0x00000002; // periodic timers
	TIMER0->TAMR |= (1U<<7); // enabling taking a snapshot of the timer value
	TIMER0->TAMR &= ~(1U<<6); // timer starts as soon it's enabled
	TIMER0->TAMR &= ~(1U<<5); // disable the match interrupt feature
	TIMER0->TAMR |= (1U<<4); // counting up

	TIMER0->TAILR = 48000; // clock tics

	TIMER0->IMR &= ~(1U<<0); // disabing interrupts

	TIMER0->CTL |= (1U<<0); // start counting
}

/*****************************************************************
	* @brief	Enable or Disable the timer.
	* @param	enb: this take one of the defined directives above 
	* @return None
*****************************************************************/
void dr_timer0_enable(uint32_t enb){
  if(enb == TIMER0_DISABLE){
    TIMER0->CTL &= ~(1U<<0);
  }else if(enb == TIMER0_ENABLE){
    TIMER0->CTL |= (1U<<0);
  }
}

/*****************************************************************
	* @brief  Manually set the value of timers
	* @param	val: value the timer should be set to
	* @return None
*****************************************************************/
void dr_timer0_set_val(uint32_t val) {
  TIMER0->TAV = val;
}

/*****************************************************************
	* @brief  Read the value of timer
	* @param	none
	* @return the value of the timer
*****************************************************************/
uint32_t dr_timer0_read_val(){
  return TIMER0->TAV;
}