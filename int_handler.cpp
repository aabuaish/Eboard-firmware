#include "int_handler.h"

extern uint32_t speedCommand;
extern uint32_t window;
extern uint32_t GPIO_global;
extern uint32_t GPIO_global2;
extern uint32_t count;
extern uint32_t countInterrupt;

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
		dr_pin_digital_write(GPIOA_AHB, 2, 0);
		dr_pin_digital_write(GPIOA_AHB, 3, 0);
		dr_pin_digital_write(GPIOA_AHB, 4, 0);
		dr_pin_digital_write(GPIOA_AHB, 6, 0);
		dr_pin_digital_write(GPIOA_AHB, 7, 0);
		window = 0;
		countInterrupt = 0;
	}else if(counter == 1){
		io_remoteControl_enable(REMOTE_CONTROLLER_ENABLE, GPIOB_AHB, 0, 1);
		dr_gpio_extern_int_clear(GPIOB_AHB, 0);
		dr_gpio_extern_int_clear(GPIOB_AHB, 1);
		window = 1;
	}else if(counter == 2){
		io_remoteControl_enable(REMOTE_CONTROLLER_DISABLE, GPIOB_AHB, 0, 1);
		dr_pin_digital_write(GPIOA_AHB, 2, 0);
		dr_pin_digital_write(GPIOA_AHB, 3, 0);
		dr_pin_digital_write(GPIOA_AHB, 4, 0);
		dr_pin_digital_write(GPIOA_AHB, 6, 1);
		window = 2;
	}else if(counter == 3){
		io_remoteControl_enable(REMOTE_CONTROLLER_DISABLE, GPIOB_AHB, 0, 1);
		dr_pin_digital_write(GPIOA_AHB, 2, 0);
		dr_pin_digital_write(GPIOA_AHB, 3, 0);
		dr_pin_digital_write(GPIOA_AHB, 4, 0);
		dr_pin_digital_write(GPIOA_AHB, 7, 1);
		window = 3;
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
	static uint32_t xx = 0;
  if(GPIOB_AHB->MIS&(1U<<0)){
    dr_timer0_set_val(0);
    dr_timer0_enable(TIMER0_ENABLE);
    dr_gpio_extern_int_clear(GPIOB_AHB, 0);
		dr_pin_digital_write(GPIOA_AHB, 2, 1);
  } else if(GPIOB_AHB->MIS&(1U<<1)){
    speedCommand = dr_timer0_read_val();
    dr_timer0_enable(TIMER0_DISABLE);
    dr_gpio_extern_int_clear(GPIOB_AHB, 1);
		dr_pin_digital_write(GPIOA_AHB, 3, 1);
	}else{
		countInterrupt++;
		dr_gpio_extern_int_clear(GPIOB_AHB, 0);
		dr_gpio_extern_int_clear(GPIOB_AHB, 1);
//		dr_pin_digital_write(GPIOA_AHB, 4, 0);
		if(xx == 0){
			dr_pin_digital_write(GPIOA_AHB, 4, 1);
			//xx++;
		}else{
			dr_pin_digital_write(GPIOA_AHB, 4, 0);
			xx = 0;
		}
//		toggle_led(GPIOA_AHB, 4);
		if(count==0){
			GPIO_global = GPIOB_AHB->MIS;
			GPIO_global2 = GPIOB_AHB->RIS;
			count++;
		}
	}
}

void GPIOPortD_IRQHandler::Handler() {
//  if(GPIOD_AHB->MIS&(1U<<2)){
//    dr_timer0_set_val(0);
//    dr_timer0_enable(TIMER0_ENABLE);
//    dr_gpio_extern_int_clear(GPIOD_AHB, 2);
//  } else if(GPIOD_AHB->MIS&(1U<<3)){
//    speedCommand = dr_timer0_read_val();
//    dr_timer0_enable(TIMER0_DISABLE);
//    dr_gpio_extern_int_clear(GPIOD_AHB, 3);
//	}else{
//		dr_gpio_extern_int_clear(GPIOD_AHB, 2);
//		dr_gpio_extern_int_clear(GPIOD_AHB, 3);
//	}
}

void GPIOPortE_IRQHandler::Handler() {

}

void GPIOPortF_IRQHandler::Handler() {
	dr_gpio_extern_int_clear(GPIOF_AHB,0);
	dr_gpio_extern_int_clear(GPIOF_AHB,4);
	toggle_led(GPIOF_AHB, LED_GREEN);
}



