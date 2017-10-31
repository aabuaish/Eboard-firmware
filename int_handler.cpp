#include "int_handler.h"

__stackless void assert_failed (char const *file, int line) {
	NVIC_SystemReset();
}

void SystemTick::Handler(){
	static int counter = 0;
	int doIt = 0;
	
	if (doIt==1){
		if(counter == 0){
			toggle_led(GPIOF_HS, LED_GREEN);
			counter++;
		}else {
			toggle_led(GPIOF_HS, LED_RED);
			counter = 0;
		}
	}
	
}

void GPIOPortA_IRQHandler::Handler() {
	dr_gpio_extern_int_clear(GPIOA_HS,4);
	toggle_led(GPIOF_HS, LED_RED);
}

void GPIOPortB_IRQHandler::Handler() {
	dr_gpio_extern_int_clear(GPIOB_HS,4);
	toggle_led(GPIOF_HS, LED_RED);
}

void GPIOPortD_IRQHandler::Handler() {
	dr_gpio_extern_int_clear(GPIOD_HS,4);
	toggle_led(GPIOF_HS, LED_RED);
}

void GPIOPortE_IRQHandler::Handler() {
	dr_gpio_extern_int_clear(GPIOE_HS,1);
	toggle_led(GPIOF_HS, LED_RED);
}

void GPIOPortF_IRQHandler::Handler() {
	dr_gpio_extern_int_clear(GPIOF_HS,0);
	dr_gpio_extern_int_clear(GPIOF_HS,4);
	toggle_led(GPIOF_HS, LED_GREEN);
}



