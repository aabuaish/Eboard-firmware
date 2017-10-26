#include "int_handler.h"

__stackless void assert_failed (char const *file, int line) {
	NVIC_SystemReset();
}

void SystemTick::Handler(){
	static int counter = 0;
	if(counter == 0){
		toggle_led(GPIOF_HS, LED_GREEN);
		counter++;
	}else {
		toggle_led(GPIOF_HS, LED_RED);
		counter = 0;
	}
	
	
//	static uint16_t window = 1;
//	
//	if(window == 1){
//		task1();
//	}elseif(window == 2){
//		task2();
//	}elseif(window ==3){
//		task3();
//	}else{
//		task4();
//	}
//	
//	if(window>4) {
//		window=1;
//	}else{
//		window++;
//	}
}

