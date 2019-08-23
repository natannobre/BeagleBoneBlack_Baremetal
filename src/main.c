#include	"hw_types.h"
#include	"soc_AM335x.h"
#include	"GPIO.h"
#include	"interrupt.h"

/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/02/2017 20:05:55
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author:  Natan Nobre Chaves, natannobre37@hotmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

typedef enum _state{
			SEQ1=1,
			SEQ2,
			SEQ3,
			SEQ4,
			SEQ5
}state;

unsigned int op= SEQ1;

int main(void){
	unsigned int count= 21;

	watchdog_disable();

	/* Enable IRQ in CPSR */
  	IntMasterIRQEnable();

	GPIO1ModuleClkConfig();

	pinInit(MODULO_1, PIN_16, INPUT);
	pinConfig(MODULO_1, PIN_16, PULLUP_PULLDOWN_ENABLE, PULLDOWN_SELECTED, RECEIVER_ENABLE);

	pinInit(MODULO_1, PIN_21, OUTPUT);
	pinInit(MODULO_1, PIN_22, OUTPUT);
	pinInit(MODULO_1, PIN_23, OUTPUT);
	pinInit(MODULO_1, PIN_24, OUTPUT);

	// ENABLE PIN TO INTERRUPT   	
	gpioAintcConf();
	gpioPinIntConf(GPIO_1_REGS, GPIO_INTC_LINE_1, 16);
   	gpioIntTypeSet(GPIO_1_REGS, 16, GPIO_INT_TYPE_BOTH_EDGE);


	while(1){
		switch (op) {
			case SEQ1:
				ledState(MODULO_1, PIN_21, HIGH);
				delay();
				ledState(MODULO_1, PIN_21, LOW);
				delay();

			break;
			case SEQ2:	
				ledState(MODULO_1, PIN_22, HIGH);
				delay();
				ledState(MODULO_1, PIN_22, LOW);
				delay();

			break;
			case SEQ3:	
				ledState(MODULO_1, PIN_23, HIGH);
				delay();
				ledState(MODULO_1, PIN_23, LOW);
				delay();

			break;
			case SEQ4:	
				ledState(MODULO_1, PIN_24, HIGH);
				delay();
				ledState(MODULO_1, PIN_24, LOW);
				delay();

			break;
			case SEQ5:
				for(count=21; count<25; count++)
					ledState(MODULO_1, count, HIGH);
					delay();
					delay();
				for(count=21; count<25; count++)
					ledState(MODULO_1, count, LOW);
					delay();
					delay();

			break;
			default:	
			break;
		}

	}	


	return(0);
} 
