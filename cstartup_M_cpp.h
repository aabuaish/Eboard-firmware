
#ifndef __CSTARTUP__
#define __CSTARTUP__

class NMI
{
public:
    static void Handler();
};

class HardFault
{
public:
    static void Handler();
};

class MemManage
{
public:
    static void Handler();
};

class BusFault
{
public:
    static void Handler();
};

class UsageFault
{
public:
    static void Handler();
};

class SVC
{
public:
    static void Handler();
};

class DebugMon
{
public:
    static void Handler();
};

class PendSV
{
public:
    static void Handler();
};

class SystemTick
{
public:
    static void Handler();
};

class GPIOPortA_IRQHandler    /* GPIO Port A                  */
{
public:
    static void Handler();
};

class GPIOPortB_IRQHandler    /* GPIO Port B                  */
{
public:
    static void Handler();
};

class GPIOPortC_IRQHandler    /* GPIO Port C                  */
{
public:
    static void Handler();
};

class GPIOPortD_IRQHandler    /* GPIO Port D                  */
{
public:
    static void Handler();
};

class GPIOPortE_IRQHandler    /* GPIO Port E                  */
{
public:
    static void Handler();
};

class UART0_IRQHandler        /* UART0 Rx and Tx              */
{
public:
    static void Handler();
};

class UART1_IRQHandler        /* UART1 Rx and Tx              */
{
public:
    static void Handler();
};

class SSI0_IRQHandler         /* SSI0 Rx and Tx               */
{
public:
    static void Handler();
};

class I2C0_IRQHandler         /* I2C0 Master and Slave        */
{
public:
    static void Handler();
};

class PWMFault_IRQHandler     /* PWM Fault                    */
{
public:
    static void Handler();
};

class PWMGen0_IRQHandler      /* PWM Generator 0              */
{
public:
    static void Handler();
};

class PWMGen1_IRQHandler      /* PWM Generator 1              */
{
public:
    static void Handler();
};

class PWMGen2_IRQHandler      /* PWM Generator 2              */
{
public:
    static void Handler();
};

class QEI0_IRQHandler         /* Quadrature Encoder 0         */
{
public:
    static void Handler();
};

class ADCSeq0_IRQHandler      /* ADC Sequence 0               */
{
public:
    static void Handler();
};

class ADCSeq1_IRQHandler      /* ADC Sequence 1               */
{
public:
    static void Handler();
};

class ADCSeq2_IRQHandler      /* ADC Sequence 2               */
{
public:
    static void Handler();
};

class ADCSeq3_IRQHandler      /* ADC Sequence 3               */
{
public:
    static void Handler();
};

class Watchdog_IRQHandler     /* Watchdog timer               */
{
public:
    static void Handler();
};

class Timer0A_IRQHandler      /* Timer 0 subtimer A           */
{
public:
    static void Handler();
};

class Timer0B_IRQHandler      /* Timer 0 subtimer B           */
{
public:
    static void Handler();
};

class Timer1A_IRQHandler      /* Timer 1 subtimer A           */
{
public:
    static void Handler();
};

class Timer1B_IRQHandler      /* Timer 1 subtimer B           */
{
public:
    static void Handler();
};

class Timer2A_IRQHandler      /* Timer 2 subtimer A           */
{
public:
    static void Handler();
};

class Timer2B_IRQHandler      /* Timer 2 subtimer B           */
{
public:
    static void Handler();
};

class Comp0_IRQHandler        /* Analog Comparator 0          */
{
public:
    static void Handler();
};

class Comp1_IRQHandler        /* Analog Comparator 1          */
{
public:
    static void Handler();
};

class Comp2_IRQHandler        /* Analog Comparator 2          */
{
public:
    static void Handler();
};

class SysCtrl_IRQHandler      /* System Control (PLLOSCBO)  */
{
public:
    static void Handler();
};

class FlashCtrl_IRQHandler    /* FLASH Control                */
{
public:
    static void Handler();
};

class GPIOPortF_IRQHandler    /* GPIO Port F                  */
{
public:
    static void Handler();
};

class GPIOPortG_IRQHandler    /* GPIO Port G                  */
{
public:
    static void Handler();
};

class GPIOPortH_IRQHandler    /* GPIO Port H                  */
{
public:
    static void Handler();
};

class UART2_IRQHandler        /* UART2 Rx and Tx              */
{
public:
    static void Handler();
};

class SSI1_IRQHandler         /* SSI1 Rx and Tx               */
{
public:
    static void Handler();
};

class Timer3A_IRQHandler      /* Timer 3 subtimer A           */
{
public:
    static void Handler();
};

class Timer3B_IRQHandler      /* Timer 3 subtimer B           */
{
public:
    static void Handler();
};

class I2C1_IRQHandler         /* I2C1 Master and Slave        */
{
public:
    static void Handler();
};

class QEI1_IRQHandler         /* Quadrature Encoder 1         */
{
public:
    static void Handler();
};

class CAN0_IRQHandler         /* CAN0                         */
{
public:
    static void Handler();
};

class CAN1_IRQHandler         /* CAN1                         */
{
public:
    static void Handler();
};

class CAN2_IRQHandler         /* CAN2                         */
{
public:
    static void Handler();
};

class Hibernate_IRQHandler    /* Hibernate                    */
{
public:
    static void Handler();
};

class USB0_IRQHandler         /* USB0                         */
{
public:
    static void Handler();
};

class PWMGen3_IRQHandler      /* PWM Generator 3              */
{
public:
    static void Handler();
};

class uDMAST_IRQHandler       /* uDMA Software Transfer       */
{
public:
    static void Handler();
};

class uDMAError_IRQHandler    /* uDMA Error                   */
{
public:
    static void Handler();
};

class ADC1Seq0_IRQHandler     /* ADC1 Sequence 0              */
{
public:
    static void Handler();
};

class ADC1Seq1_IRQHandler     /* ADC1 Sequence 1              */
{
public:
    static void Handler();
};

class ADC1Seq2_IRQHandler     /* ADC1 Sequence 2              */
{
public:
    static void Handler();
};

class ADC1Seq3_IRQHandler     /* ADC1 Sequence 3              */
{
public:
    static void Handler();
};

class GPIOPortJ_IRQHandler    /* GPIO Port J                  */
{
public:
    static void Handler();
};

class GPIOPortK_IRQHandler    /* GPIO Port K                  */
{
public:
    static void Handler();
};

class GPIOPortL_IRQHandler    /* GPIO Port L                  */
{
public:
    static void Handler();
};

class SSI2_IRQHandler         /* SSI2 Rx and Tx               */
{
public:
    static void Handler();
};

class SSI3_IRQHandler         /* SSI3 Rx and Tx               */
{
public:
    static void Handler();
};

class UART3_IRQHandler        /* UART3 Rx and Tx              */
{
public:
    static void Handler();
};

class UART4_IRQHandler        /* UART4 Rx and Tx              */
{
public:
    static void Handler();
};

class UART5_IRQHandler        /* UART5 Rx and Tx              */
{
public:
    static void Handler();
};

class UART6_IRQHandler        /* UART6 Rx and Tx              */
{
public:
    static void Handler();
};

class UART7_IRQHandler        /* UART7 Rx and Tx              */
{
public:
    static void Handler();
};

class I2C2_IRQHandler         /* I2C2 Master and Slave        */
{
public:
    static void Handler();
};

class I2C3_IRQHandler         /* I2C3 Master and Slave        */
{
public:
    static void Handler();
};

class Timer4A_IRQHandler      /* Timer 4 subtimer A           */
{
public:
    static void Handler();
};

class Timer4B_IRQHandler      /* Timer 4 subtimer B           */
{
public:
    static void Handler();
};

class Timer5A_IRQHandler      /* Timer 5 subtimer A           */
{
public:
    static void Handler();
};

class Timer5B_IRQHandler      /* Timer 5 subtimer B           */
{
public:
    static void Handler();
};

class WideTimer0A_IRQHandler  /* Wide Timer 0 subtimer A      */
{
public:
    static void Handler();
};

class WideTimer0B_IRQHandler  /* Wide Timer 0 subtimer B      */
{
public:
    static void Handler();
};

class WideTimer1A_IRQHandler  /* Wide Timer 1 subtimer A      */
{
public:
    static void Handler();
};

class WideTimer1B_IRQHandler  /* Wide Timer 1 subtimer B      */
{
public:
    static void Handler();
};

class WideTimer2A_IRQHandler  /* Wide Timer 2 subtimer A      */
{
public:
    static void Handler();
};

class WideTimer2B_IRQHandler  /* Wide Timer 2 subtimer B      */
{
public:
    static void Handler();
};

class WideTimer3A_IRQHandler  /* Wide Timer 3 subtimer A      */
{
public:
    static void Handler();
};

class WideTimer3B_IRQHandler  /* Wide Timer 3 subtimer B      */
{
public:
    static void Handler();
};

class WideTimer4A_IRQHandler  /* Wide Timer 4 subtimer A      */
{
public:
    static void Handler();
};

class WideTimer4B_IRQHandler  /* Wide Timer 4 subtimer B      */
{
public:
    static void Handler();
};

class WideTimer5A_IRQHandler  /* Wide Timer 5 subtimer A      */
{
public:
    static void Handler();
};

class WideTimer5B_IRQHandler  /* Wide Timer 5 subtimer B      */
{
public:
    static void Handler();
};

class FPU_IRQHandler          /* FPU                          */
{
public:
    static void Handler();
};

class I2C4_IRQHandler         /* I2C4 Master and Slave        */
{
public:
    static void Handler();
};

class I2C5_IRQHandler         /* I2C5 Master and Slave        */
{
public:
    static void Handler();
};

class GPIOPortM_IRQHandler    /* GPIO Port M                  */
{
public:
    static void Handler();
};

class GPIOPortN_IRQHandler    /* GPIO Port N                  */
{
public:
    static void Handler();
};

class QEI2_IRQHandler         /* Quadrature Encoder 2         */
{
public:
    static void Handler();
};

class GPIOPortP0_IRQHandler   /* GPIO Port P (Summary or P0)  */
{
public:
    static void Handler();
};

class GPIOPortP1_IRQHandler   /* GPIO Port P1                 */
{
public:
    static void Handler();
};

class GPIOPortP2_IRQHandler   /* GPIO Port P2                 */
{
public:
    static void Handler();
};

class GPIOPortP3_IRQHandler   /* GPIO Port P3                 */
{
public:
    static void Handler();
};

class GPIOPortP4_IRQHandler   /* GPIO Port P4                 */
{
public:
    static void Handler();
};

class GPIOPortP5_IRQHandler   /* GPIO Port P5                 */
{
public:
    static void Handler();
};

class GPIOPortP6_IRQHandler   /* GPIO Port P6                 */
{
public:
    static void Handler();
};

class GPIOPortP7_IRQHandler   /* GPIO Port P7                 */
{
public:
    static void Handler();
};

class GPIOPortQ0_IRQHandler   /* GPIO Port Q (Summary or Q0)  */
{
public:
    static void Handler();
};

class GPIOPortQ1_IRQHandler   /* GPIO Port Q1                 */
{
public:
    static void Handler();
};

class GPIOPortQ2_IRQHandler   /* GPIO Port Q2                 */
{
public:
    static void Handler();
};

class GPIOPortQ3_IRQHandler   /* GPIO Port Q3                 */
{
public:
    static void Handler();
};

class GPIOPortQ4_IRQHandler   /* GPIO Port Q4                 */
{
public:
    static void Handler();
};

class GPIOPortQ5_IRQHandler   /* GPIO Port Q5                 */
{
public:
    static void Handler();
};

class GPIOPortQ6_IRQHandler   /* GPIO Port Q6                 */
{
public:
    static void Handler();
};

class GPIOPortQ7_IRQHandler   /* GPIO Port Q7                 */
{
public:
    static void Handler();
};

class GPIOPortR_IRQHandler    /* GPIO Port R                  */
{
public:
    static void Handler();
};

class GPIOPortS_IRQHandler    /* GPIO Port S                  */
{
public:
    static void Handler();
};

class PWM1Gen0_IRQHandler     /* PWM 1 Generator 0            */
{
public:
    static void Handler();
};

class PWM1Gen1_IRQHandler     /* PWM 1 Generator 1            */
{
public:
    static void Handler();
};

class PWM1Gen2_IRQHandler     /* PWM 1 Generator 2            */
{
public:
    static void Handler();
};

class PWM1Gen3_IRQHandler     /* PWM 1 Generator 3            */
{
public:
    static void Handler();
};

class PWM1Fault_IRQHandler     /* PWM 1 Fault                  */
{
public:
    static void Handler();
};

#endif //__CSTARTUP__