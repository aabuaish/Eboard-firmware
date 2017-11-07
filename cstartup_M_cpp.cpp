/**************************************************
 *
 * This file contains an interrupt vector for Cortex-M written in C++.
 * Compare it to the <EWARM>\arm\src\lib\thumb\cstartup_M.c written in C.
 * The actual interrupt functions must be provided by the application developer.
 *
 * Copyright 2007 IAR Systems. All rights reserved.
 *
 * $Revision: 41481 $
 *
 **************************************************/
#include "cstartup_M_cpp.h"

#pragma language=extended
#pragma segment="CSTACK"

extern "C" void __iar_program_start( void );

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

// The vector table is normally located at address 0.
// When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
// If you need to define interrupt service routines,
// make a copy of this file and include it in your project.
// The name "__vector_table" has special meaning for C-SPY:
// it is where the SP start value is found, and the NVIC vector
// table register (VTOR) is initialized to this address if != 0.

#pragma location = ".intvec"
extern "C" const intvec_elem __vector_table[] =
{
  { .__ptr = __sfe( "CSTACK" ) },
  __iar_program_start,

  NMI::Handler,
  HardFault::Handler,
  MemManage::Handler,
  BusFault::Handler,
  UsageFault::Handler,
  0,
  0,
  0,
  0,
  SVC::Handler,
  DebugMon::Handler,
  0,
  PendSV::Handler,
  SystemTick::Handler,
  
  
  GPIOPortA_IRQHandler::Handler,
  GPIOPortB_IRQHandler::Handler,
  GPIOPortC_IRQHandler::Handler,
  GPIOPortD_IRQHandler::Handler,
  GPIOPortE_IRQHandler::Handler,
  UART0_IRQHandler::Handler,
  UART1_IRQHandler::Handler,
  SSI0_IRQHandler::Handler,
  I2C0_IRQHandler::Handler,
  PWMFault_IRQHandler::Handler,
  PWMGen0_IRQHandler::Handler,
  PWMGen1_IRQHandler::Handler,
  PWMGen2_IRQHandler::Handler,
  QEI0_IRQHandler::Handler,
  ADCSeq0_IRQHandler::Handler,
  ADCSeq1_IRQHandler::Handler,
  ADCSeq2_IRQHandler::Handler,
  ADCSeq3_IRQHandler::Handler,
  Watchdog_IRQHandler::Handler,
  Timer0A_IRQHandler::Handler,
  Timer0B_IRQHandler::Handler,
  Timer1A_IRQHandler::Handler,
  Timer1B_IRQHandler::Handler,
  Timer2A_IRQHandler::Handler,
  Timer2B_IRQHandler::Handler,
  Comp0_IRQHandler::Handler,
  Comp1_IRQHandler::Handler,
  Comp2_IRQHandler::Handler,
  SysCtrl_IRQHandler::Handler,
  FlashCtrl_IRQHandler::Handler,
  GPIOPortF_IRQHandler::Handler,
  GPIOPortG_IRQHandler::Handler,
  GPIOPortH_IRQHandler::Handler,
  UART2_IRQHandler::Handler,
  SSI1_IRQHandler::Handler,
  Timer3A_IRQHandler::Handler,
  Timer3B_IRQHandler::Handler,
  I2C1_IRQHandler::Handler,
  QEI1_IRQHandler::Handler,
  CAN0_IRQHandler::Handler,
  CAN1_IRQHandler::Handler,
  CAN2_IRQHandler::Handler,
  Hibernate_IRQHandler::Handler,
  USB0_IRQHandler::Handler,
  PWMGen3_IRQHandler::Handler,
  uDMAST_IRQHandler::Handler,
  uDMAError_IRQHandler::Handler,
  ADC1Seq0_IRQHandler::Handler,
  ADC1Seq1_IRQHandler::Handler,
  ADC1Seq2_IRQHandler::Handler,
  ADC1Seq3_IRQHandler::Handler,
  GPIOPortJ_IRQHandler::Handler,
  GPIOPortK_IRQHandler::Handler,
  GPIOPortL_IRQHandler::Handler,
  SSI2_IRQHandler::Handler,
  SSI3_IRQHandler::Handler,
  UART3_IRQHandler::Handler,
  UART4_IRQHandler::Handler,
  UART5_IRQHandler::Handler,
  UART6_IRQHandler::Handler,
  UART7_IRQHandler::Handler,
  I2C2_IRQHandler::Handler,
  I2C3_IRQHandler::Handler,
  Timer4A_IRQHandler::Handler,
  Timer4B_IRQHandler::Handler,
  Timer5A_IRQHandler::Handler,
  Timer5B_IRQHandler::Handler,
  WideTimer0A_IRQHandler::Handler,
  WideTimer0B_IRQHandler::Handler,
  WideTimer1A_IRQHandler::Handler,
  WideTimer1B_IRQHandler::Handler,
  WideTimer2A_IRQHandler::Handler,
  WideTimer2B_IRQHandler::Handler,
  WideTimer3A_IRQHandler::Handler,
  WideTimer3B_IRQHandler::Handler,
  WideTimer4A_IRQHandler::Handler,
  WideTimer4B_IRQHandler::Handler,
  WideTimer5A_IRQHandler::Handler,
  WideTimer5B_IRQHandler::Handler,
  FPU_IRQHandler::Handler,
  I2C4_IRQHandler::Handler,
  I2C5_IRQHandler::Handler,
  GPIOPortM_IRQHandler::Handler,
  GPIOPortN_IRQHandler::Handler,
  QEI2_IRQHandler::Handler,
  GPIOPortP0_IRQHandler::Handler,
  GPIOPortP1_IRQHandler::Handler,
  GPIOPortP2_IRQHandler::Handler,
  GPIOPortP3_IRQHandler::Handler,
  GPIOPortP4_IRQHandler::Handler,
  GPIOPortP5_IRQHandler::Handler,
  GPIOPortP6_IRQHandler::Handler,
  GPIOPortP7_IRQHandler::Handler,
  GPIOPortQ0_IRQHandler::Handler,
  GPIOPortQ1_IRQHandler::Handler,
  GPIOPortQ2_IRQHandler::Handler,
  GPIOPortQ3_IRQHandler::Handler,
  GPIOPortQ4_IRQHandler::Handler,
  GPIOPortQ5_IRQHandler::Handler,
  GPIOPortQ6_IRQHandler::Handler,
  GPIOPortQ7_IRQHandler::Handler,
  GPIOPortR_IRQHandler::Handler,
  GPIOPortS_IRQHandler::Handler,
  PWM1Gen0_IRQHandler::Handler,
  PWM1Gen1_IRQHandler::Handler,
  PWM1Gen2_IRQHandler::Handler,
  PWM1Gen3_IRQHandler::Handler,
  PWM1Fault_IRQHandler::Handler
};

__weak void NMI::Handler()          { while (1) {} }
__weak void HardFault::Handler()    { while (1) {} }
__weak void MemManage::Handler()    { while (1) {} }
__weak void BusFault::Handler()     { while (1) {} }
__weak void UsageFault::Handler()   { while (1) {} }
__weak void SVC::Handler()          { while (1) {} }
__weak void DebugMon::Handler()     { while (1) {} }
__weak void PendSV::Handler()       { while (1) {} }
__weak void SystemTick::Handler()      { while (1) {} }

__weak void GPIOPortA_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortB_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortC_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortD_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortE_IRQHandler::Handler()		{ while (1) {} }
__weak void UART0_IRQHandler::Handler()	    	{ while (1) {} }
__weak void UART1_IRQHandler::Handler()	    	{ while (1) {} }
__weak void SSI0_IRQHandler::Handler()	    	{ while (1) {} }
__weak void I2C0_IRQHandler::Handler()	    	{ while (1) {} }
__weak void PWMFault_IRQHandler::Handler()		{ while (1) {} }
__weak void PWMGen0_IRQHandler::Handler()	  	{ while (1) {} }
__weak void PWMGen1_IRQHandler::Handler()	  	{ while (1) {} }
__weak void PWMGen2_IRQHandler::Handler()	  	{ while (1) {} }
__weak void QEI0_IRQHandler::Handler()	    	{ while (1) {} }
__weak void ADCSeq0_IRQHandler::Handler()	  	{ while (1) {} }
__weak void ADCSeq1_IRQHandler::Handler()	  	{ while (1) {} }
__weak void ADCSeq2_IRQHandler::Handler()	  	{ while (1) {} }
__weak void ADCSeq3_IRQHandler::Handler()	  	{ while (1) {} }
__weak void Watchdog_IRQHandler::Handler()		{ while (1) {} }
__weak void Timer0A_IRQHandler::Handler()		  { while (1) {} }
__weak void Timer0B_IRQHandler::Handler()	  	{ while (1) {} }
__weak void Timer1A_IRQHandler::Handler()	  	{ while (1) {} }
__weak void Timer1B_IRQHandler::Handler()	  	{ while (1) {} }
__weak void Timer2A_IRQHandler::Handler()	  	{ while (1) {} }
__weak void Timer2B_IRQHandler::Handler()		  { while (1) {} }
__weak void Comp0_IRQHandler::Handler()	    	{ while (1) {} }
__weak void Comp1_IRQHandler::Handler()	    	{ while (1) {} }
__weak void Comp2_IRQHandler::Handler()	    	{ while (1) {} }
__weak void SysCtrl_IRQHandler::Handler()		  { while (1) {} }
__weak void FlashCtrl_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortF_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortG_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortH_IRQHandler::Handler()		{ while (1) {} }
__weak void UART2_IRQHandler::Handler()		    { while (1) {} }
__weak void SSI1_IRQHandler::Handler()	    	{ while (1) {} }
__weak void Timer3A_IRQHandler::Handler()	  	{ while (1) {} }
__weak void Timer3B_IRQHandler::Handler()	  	{ while (1) {} }
__weak void I2C1_IRQHandler::Handler()	    	{ while (1) {} }
__weak void QEI1_IRQHandler::Handler()	     	{ while (1) {} }
__weak void CAN0_IRQHandler::Handler()	    	{ while (1) {} }
__weak void CAN1_IRQHandler::Handler()	    	{ while (1) {} }
__weak void CAN2_IRQHandler::Handler()	    	{ while (1) {} }
__weak void Hibernate_IRQHandler::Handler()		{ while (1) {} }
__weak void USB0_IRQHandler::Handler()	    	{ while (1) {} }
__weak void PWMGen3_IRQHandler::Handler()	  	{ while (1) {} }
__weak void uDMAST_IRQHandler::Handler()		  { while (1) {} }
__weak void uDMAError_IRQHandler::Handler()		{ while (1) {} }
__weak void ADC1Seq0_IRQHandler::Handler()		{ while (1) {} }
__weak void ADC1Seq1_IRQHandler::Handler()		{ while (1) {} }
__weak void ADC1Seq2_IRQHandler::Handler()		{ while (1) {} }
__weak void ADC1Seq3_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortJ_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortK_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortL_IRQHandler::Handler()		{ while (1) {} }
__weak void SSI2_IRQHandler::Handler()	    	{ while (1) {} }
__weak void SSI3_IRQHandler::Handler()	    	{ while (1) {} }
__weak void UART3_IRQHandler::Handler()	    	{ while (1) {} }
__weak void UART4_IRQHandler::Handler()	    	{ while (1) {} }
__weak void UART5_IRQHandler::Handler()	    	{ while (1) {} }
__weak void UART6_IRQHandler::Handler()	    	{ while (1) {} }
__weak void UART7_IRQHandler::Handler()	    	{ while (1) {} }
__weak void I2C2_IRQHandler::Handler()	    	{ while (1) {} }
__weak void I2C3_IRQHandler::Handler()	    	{ while (1) {} }
__weak void Timer4A_IRQHandler::Handler()	  	{ while (1) {} }
__weak void Timer4B_IRQHandler::Handler()		  { while (1) {} }
__weak void Timer5A_IRQHandler::Handler()	  	{ while (1) {} }
__weak void Timer5B_IRQHandler::Handler()	  	{ while (1) {} }
__weak void WideTimer0A_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer0B_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer1A_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer1B_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer2A_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer2B_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer3A_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer3B_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer4A_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer4B_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer5A_IRQHandler::Handler()		{ while (1) {} }
__weak void WideTimer5B_IRQHandler::Handler()		{ while (1) {} }
__weak void FPU_IRQHandler::Handler()	       	{ while (1) {} }
__weak void I2C4_IRQHandler::Handler()		    { while (1) {} }
__weak void I2C5_IRQHandler::Handler()		    { while (1) {} }
__weak void GPIOPortM_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortN_IRQHandler::Handler()		{ while (1) {} }
__weak void QEI2_IRQHandler::Handler()		    { while (1) {} }
__weak void GPIOPortP0_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortP1_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortP2_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortP3_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortP4_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortP5_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortP6_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortP7_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortQ0_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortQ1_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortQ2_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortQ3_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortQ4_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortQ5_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortQ6_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortQ7_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortR_IRQHandler::Handler()		{ while (1) {} }
__weak void GPIOPortS_IRQHandler::Handler()		{ while (1) {} }
__weak void PWM1Gen0_IRQHandler::Handler()		{ while (1) {} }
__weak void PWM1Gen1_IRQHandler::Handler()		{ while (1) {} }
__weak void PWM1Gen2_IRQHandler::Handler()		{ while (1) {} }
__weak void PWM1Gen3_IRQHandler::Handler()		{ while (1) {} }
__weak void PWM1Fault_IRQHandler::Handler()		{ while (1) {} }


extern "C" void __cmain( void );
extern "C" __weak void __iar_init_core( void );
extern "C" __weak void __iar_init_vfp( void );

#pragma required=__vector_table
void __iar_program_start( void )
{
  __iar_init_core();
  __iar_init_vfp();
  __cmain();
}
