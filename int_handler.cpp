#include "int_handler.h"

extern uint32_t speedCommand;

__stackless void assert_failed (char const *file, int line) {
	NVIC_SystemReset();
}

void SystemTick::Handler(){
	static int counter = 0;
	int doIt = 0;
	
	if (doIt==1){
		if(counter == 0){
			toggle_led(GPIOF_AHB, LED_GREEN);
			counter++;
		}else {
			toggle_led(GPIOF_AHB, LED_BLUE);
			counter = 0;
		}
	}
	
	if(counter == 0){
		io_remoteControl_enable(REMOTE_CONTROLLER_DISABLE, GPIOB_AHB, 0, 1);
	}else if(counter == 1){
		io_remoteControl_enable(REMOTE_CONTROLLER_ENABLE, GPIOB_AHB, 0, 1);
		dr_gpio_extern_int_clear(GPIOB_AHB, 0);
		dr_gpio_extern_int_clear(GPIOB_AHB, 1);
	}else if(counter == 2){
		io_remoteControl_enable(REMOTE_CONTROLLER_DISABLE, GPIOB_AHB, 0, 1);
	}else if(counter == 3){
		io_remoteControl_enable(REMOTE_CONTROLLER_DISABLE, GPIOB_AHB, 0, 1);
	}

  if(counter>=3){
    counter = 0;
  }else{
    counter++;
  }

}

void GPIOPortA_IRQHandler::Handler() {

}

void GPIOPortB_IRQHandler::Handler() {

  if(GPIOB_AHB->MIS&(1U<<0)){
    dr_timer0_set_val(0);
    dr_timer0_enable(TIMER0_ENABLE);
    dr_gpio_extern_int_clear(GPIOB_AHB, 0);
  } else if(GPIOB_AHB->MIS&(1U<<1)){
    speedCommand = dr_timer0_read_val();
    dr_timer0_enable(TIMER0_DISABLE);
    dr_gpio_extern_int_clear(GPIOB_AHB, 1);
	}else{
		dr_gpio_extern_int_clear(GPIOB_AHB, 0);
		dr_gpio_extern_int_clear(GPIOB_AHB, 1);
	}
}

void GPIOPortD_IRQHandler::Handler() {

}

void GPIOPortE_IRQHandler::Handler() {

}

void GPIOPortF_IRQHandler::Handler() {
	dr_gpio_extern_int_clear(GPIOF_AHB,0);
	dr_gpio_extern_int_clear(GPIOF_AHB,4);
	toggle_led(GPIOF_AHB, LED_GREEN);
}



