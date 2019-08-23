#include "hw_types.h"
#include "hw_cm_per.h"
#include "soc_AM335x.h"
#include "GPIO.h"
#include "interrupt.h"

unsigned int ENUM_PIN[4][32] = {\
	{PIN_GPIO0_00, PIN_GPIO0_01, PIN_GPIO0_SPI_02, PIN_GPIO0_SPI_03, PIN_GPIO0_SPI_04, PIN_GPIO0_SPI_05, PIN_GPIO0_SPI_06, PIN_GPIO0_07, PIN_GPIO0_LCD_08, PIN_GPIO0_LCD_09, PIN_GPIO0_LCD_10, PIN_GPIO0_LCD_11, PIN_GPIO0_UART_12, PIN_GPIO0_UART_13, PIN_GPIO0_UART_14, PIN_GPIO0_UART_15, PIN_GPIO0_16, PIN_GPIO0_17, PIN_GPIO0_18, PIN_GPIO0_19, PIN_GPIO0_20, PIN_GPIO0_21, PIN_GPIO0_22, PIN_GPIO0_23, PIN_GPIO0_24, PIN_GPIO0_25, PIN_GPIO0_26, PIN_GPIO0_27, PIN_GPIO0_28, PIN_GPIO0_29, PIN_GPIO0_30, PIN_GPIO0_31},\
	{PIN_GPIO1_00, PIN_GPIO1_01, PIN_GPIO1_02, PIN_GPIO1_03, PIN_GPIO1_04, PIN_GPIO1_05, PIN_GPIO1_06, PIN_GPIO1_07, PIN_GPIO1_UART_08, PIN_GPIO1_UART_09, PIN_GPIO1_UART_10, PIN_GPIO1_UART_11,PIN_GPIO1_12, PIN_GPIO1_13, PIN_GPIO1_14, PIN_GPIO1_15, PIN_GPIO1_16, PIN_GPIO1_17, PIN_GPIO1_18, PIN_GPIO1_19, PIN_GPIO1_20, PIN_GPIO1_21, PIN_GPIO1_22, PIN_GPIO1_23, PIN_GPIO1_24, PIN_GPIO1_25, PIN_GPIO1_26, PIN_GPIO1_27, PIN_GPIO1_28, PIN_GPIO1_29, PIN_GPIO1_30, PIN_GPIO1_31},\
	{PIN_GPIO2_00, PIN_GPIO2_01, PIN_GPIO2_02, PIN_GPIO2_03, PIN_GPIO2_04, PIN_GPIO2_05, PIN_GPIO2_06, PIN_GPIO2_07, PIN_GPIO2_08, PIN_GPIO2_09, PIN_GPIO2_10, PIN_GPIO2_11, PIN_GPIO2_12, PIN_GPIO2_13, PIN_GPIO2_14, PIN_GPIO2_15, PIN_GPIO2_16,PIN_GPIO2_17, PIN_GPIO2_18, PIN_GPIO2_19, PIN_GPIO2_20, PIN_GPIO2_21, PIN_GPIO2_22, PIN_GPIO2_23, PIN_GPIO2_24, PIN_GPIO2_25,PIN_GPIO2_26, PIN_GPIO2_27, PIN_GPIO2_28, PIN_GPIO2_29, PIN_GPIO2_30, PIN_GPIO2_31},\
	{PIN_GPIO3_00, PIN_GPIO3_01, PIN_GPIO3_02, PIN_GPIO3_03, PIN_GPIO3_04, PIN_GPIO3_05, PIN_GPIO3_06, PIN_GPIO3_07, PIN_GPIO3_08, PIN_GPIO3_09, PIN_GPIO3_10, PIN_GPIO3_11, PIN_GPIO3_12, PIN_GPIO3_13, PIN_GPIO3_14, PIN_GPIO3_15, PIN_GPIO3_16, PIN_GPIO3_17, PIN_GPIO3_18, PIN_GPIO3_19, PIN_GPIO3_20, PIN_GPIO3_21}};


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  watchdog_disable
 *  Description:
 * =====================================================================================
 */ 

void watchdog_disable(){
	/*BEGIN_OF_WATCH_DOG_DISABLE*/
		HWREG(WDT + WDT_WSPR) = WDT_STOP_PART_1;
		delay();
		HWREG(WDT + WDT_WSPR) = WDT_STOP_PART_2;
	/*FINAL_OF_WATCH_DOG_DISABLE*/
	}
/* -----  end of function watchdog_disable  ----- */




/*FUNCTION*-------------------------------------------------------
*
* Function Name : Delay
* Comments      :
*END*-----------------------------------------------------------*/

	void delay(){
		volatile unsigned int ra;
		for(ra = 0; ra < TIME; ra ++);
	}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  clkConfig
 *  Description:
 * =====================================================================================
 */

void clkConfig(int module){
	if(module == 0){
		/*-------------------------------------------------------------------------------
		 *  configure clock GPIO in clock module
		 *-----------------------------------------------------------------------------*/
		HWREG(CM_WKUP + CM_WKUP_GPIO0) |= (CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_0_1_2_3_GDBCLK | CM_PER_GPIO_0_1_2_3_CLKCTRL_MODULEMODE_ENABLE);

	}else if(module == 1){
		HWREG(CM_PER + CM_PER_GPIO1) |= (CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_0_1_2_3_GDBCLK | CM_PER_GPIO_0_1_2_3_CLKCTRL_MODULEMODE_ENABLE);

	}else if(module == 2){
		HWREG(CM_PER + CM_PER_GPIO2) |= (CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_0_1_2_3_GDBCLK | CM_PER_GPIO_0_1_2_3_CLKCTRL_MODULEMODE_ENABLE);

	}else if(module == 3){
		HWREG(CM_PER + CM_PER_GPIO3) |= (CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_0_1_2_3_GDBCLK | CM_PER_GPIO_0_1_2_3_CLKCTRL_MODULEMODE_ENABLE);
	}

}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  pinInit
 *  Description:
 * =====================================================================================
 */


void pinInit(int module, int pino, int state){
	if(module == 0){
		if(state == INPUT){
			/*--------------------------+---------------------------------------------------
		 	* configure mux pin in control module
		 	*-----------------------------------------------------------------------------*/
			HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= IO;
			/*-----------------------------------------------------------------------------
			 *  set pin direction
			 *-----------------------------------------------------------------------------*/
			HWREG(GPIO_0_REGS + GPIO_OE) |= (1 << pino);

		}else if(state == OUTPUT){
			
			HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= IO;

			HWREG(GPIO_0_REGS + GPIO_OE) &= ~(1 << pino);
		}
	}else if(module == 1){
		if(state == INPUT){
				/*--------------------------+---------------------------------------------------
			 	* configure mux pin in control module
			 	*-----------------------------------------------------------------------------*/
				HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= IO;
				/*-----------------------------------------------------------------------------
				 *  set pin direction
				 *-----------------------------------------------------------------------------*/
				HWREG(GPIO_1_REGS + GPIO_OE) |= (1 << pino);

		}else if(state == OUTPUT){
				
				HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= IO;

				HWREG(GPIO_1_REGS + GPIO_OE) &= ~(1 << pino);

		}
	}else if(module == 2){
		if(state == INPUT){

				HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= IO;

				HWREG(GPIO_2_REGS + GPIO_OE) |= (1 << pino);

		}else if(state == OUTPUT){

				HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= IO;

				HWREG(GPIO_2_REGS + GPIO_OE) &= ~(1 << pino);

		}
	}else if(module == 3){
		if(state == INPUT){

				HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= IO;

				HWREG(GPIO_3_REGS + GPIO_OE) |= (1 << pino);

		}else if(state == OUTPUT){

				HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= IO;

				HWREG(GPIO_3_REGS + GPIO_OE) &= ~(1 << pino);

		}
	}
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  ledBlink
 *  Description:
 * =====================================================================================
 */


void ledBlink(int module, int pin){
	ledState(module, pin, HIGH);
	ledState(module, pin, LOW);
}



/*
 * ===  FUNCTION  ======================================================================
 *         Name:  ledState
 *  Description:
 * =====================================================================================
 */



void ledState(int module, int pin, int state){
	if(state){

		switch(module){
			case 1:
				HWREG(GPIO_1_REGS + GPIO_SETDATAOUT) = (1 << pin);
				delay();
			break;
			case 2:
				HWREG(GPIO_2_REGS + GPIO_SETDATAOUT) = (1 << pin);
				delay();
			break;
			case 3:
				HWREG(GPIO_3_REGS + GPIO_SETDATAOUT) = (1 << pin);
				delay();
			break;
		}

	}else{

		switch(module){
			case 1:
				HWREG(GPIO_1_REGS + GPIO_CLEARDATAOUT) = (1 << pin);
				delay();
			break;
			case 2:
				HWREG(GPIO_2_REGS + GPIO_CLEARDATAOUT) = (1 << pin);
				delay();
			break;
			case 3:
				HWREG(GPIO_3_REGS + GPIO_CLEARDATAOUT) = (1 << pin);
				delay();
			break;

		}
	}
	
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  pinConfig
 *  Description:
 * =====================================================================================
 */


void pinConfig(int module, int pino, int puden, int putypesel, int rxactiv){
	if(puden){
		HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= (1 << 3);
	}else{
		HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) &= ~(1 << 3);
	}

	if(putypesel){
		HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= (1 << 4);
	}else{
		HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) &= ~(1 << 4);
	}

	if(rxactiv){
		HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) |= (1 << 5);
	}else{
		HWREG(CONTROL_MODULE + ENUM_PIN[module][pino]) &= ~(1 << 5);
	}

}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  inputLedCheck
 *  Description:
 * =====================================================================================
 */


void inputLedCheck(int module_pin_in, int pin_in, int module_pin_out, int pin_out){

	switch(module_pin_in){
		case 1:
			if(HWREG(GPIO_1_REGS + GPIO_DATAIN) & (1 << pin_in)){
				ledState(module_pin_out, pin_out, HIGH);
				ledState(module_pin_out, pin_out, LOW);
			}
							
		break;
		case 2:
			if(HWREG(GPIO_2_REGS + GPIO_DATAIN) & (1 << pin_in)){
				ledState(module_pin_out, pin_out, HIGH);
				ledState(module_pin_out, pin_out, LOW);
			}
		break;
		case 3:
			if(HWREG(GPIO_3_REGS + GPIO_DATAIN) & (1 << pin_in)){
				ledState(module_pin_out, pin_out, HIGH);
				ledState(module_pin_out, pin_out, LOW);
			}
		break;
	}				
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  button_is_press
 *  Description:
 * =====================================================================================
 */

bool button_is_press(int modulo_input, int pino_input){
	switch(modulo_input){
		case 1:
			if(HWREG(GPIO_1_REGS + GPIO_DATAIN) & (1 << pino_input)){
				return TRUE;
			}
			return FALSE;
		break;
		case 2:
			if(HWREG(GPIO_2_REGS + GPIO_DATAIN) & (1 << pino_input)){
				return TRUE;
			}
			return FALSE;
		break;
		case 3:
			if(HWREG(GPIO_3_REGS + GPIO_DATAIN) & (1 << pino_input)){
				return TRUE;
			}
			return FALSE;
		break;
	}
	return FALSE;
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  ledBlink_10_pins
 *  Description:
 * =====================================================================================
 */


void ledBlink_10_pins(){

	while(1){

			if(button_is_press(MODULO_2, PIN_6)){
				ledState(MODULO_1, PIN_3, HIGH);
				ledState(MODULO_1, PIN_12, HIGH);
				ledState(MODULO_1, PIN_14, HIGH);
				ledState(MODULO_1, PIN_5, HIGH);
				ledState(MODULO_1, PIN_1, HIGH);

				if(button_is_press(MODULO_1, PIN_GPIO3_16)){
					ledBlink(MODULO_1, PIN_2);
					ledBlink(MODULO_1, PIN_13);
					ledBlink(MODULO_1, PIN_15);
					ledBlink(MODULO_1, PIN_30);
					ledBlink(MODULO_1, PIN_0);

					ledBlink(MODULO_1, PIN_30);
					ledBlink(MODULO_1, PIN_15);
					ledBlink(MODULO_1, PIN_13);
					ledBlink(MODULO_1, PIN_2);
				}

				ledState(MODULO_1, PIN_1, LOW);
				ledState(MODULO_1, PIN_5, LOW);
				ledState(MODULO_1, PIN_14, LOW);
				ledState(MODULO_1, PIN_12, LOW);
				ledState(MODULO_1, PIN_3, LOW);
			}

			delay();
			if(button_is_press(MODULO_1, PIN_16)){
				break;
			}
		}
		while(1){
			if(button_is_press(MODULO_2, PIN_6)){
				ledState(MODULO_1, PIN_3, HIGH);
				delay();
				if(button_is_press(MODULO_1, PIN_16)){
					ledState(MODULO_1, PIN_0, HIGH);

				}
				ledState(MODULO_1, PIN_12, HIGH);
				delay();
				if(button_is_press(MODULO_1, PIN_16)){
					ledState(MODULO_1, PIN_30, HIGH);

				}
				ledState(MODULO_1, PIN_14, HIGH);
				delay();
				if(button_is_press(MODULO_1, PIN_16)){
					ledState(MODULO_1, PIN_15, HIGH);

				}
				ledState(MODULO_1, PIN_5, HIGH);
				delay();
				if(button_is_press(MODULO_1, PIN_16)){
					ledState(MODULO_1, PIN_13, HIGH);

				}
				ledState(MODULO_1, PIN_1, HIGH);
				delay();
				if(button_is_press(MODULO_1, PIN_16)){
					ledState(MODULO_1, PIN_2, HIGH);

				}
				delay();

				ledState(MODULO_1, PIN_1, LOW);
				ledState(MODULO_1, PIN_5, LOW);
				ledState(MODULO_1, PIN_14, LOW);
				ledState(MODULO_1, PIN_12, LOW);
				ledState(MODULO_1, PIN_3, LOW);
				ledState(MODULO_1, PIN_2, LOW);
				ledState(MODULO_1, PIN_13, LOW);
				ledState(MODULO_1, PIN_15, LOW);
				ledState(MODULO_1, PIN_30, LOW);
				ledState(MODULO_1, PIN_0, LOW);
			}

			delay();
			if(button_is_press(MODULO_1, PIN_16)){
				break;
			}
		}
		while(1){
			if(button_is_press(MODULO_2, PIN_6)){
				ledState(MODULO_1, PIN_3, HIGH);
				ledState(MODULO_1, PIN_12, HIGH);
				ledState(MODULO_1, PIN_14, HIGH);
				ledState(MODULO_1, PIN_5, HIGH);
				ledState(MODULO_1, PIN_1, HIGH);
				ledState(MODULO_1, PIN_2, HIGH);
				ledState(MODULO_1, PIN_13, HIGH);
				ledState(MODULO_1, PIN_15, HIGH);
				ledState(MODULO_1, PIN_30, HIGH);
				ledState(MODULO_1, PIN_0, HIGH);

				ledState(MODULO_1, PIN_3, LOW);
				ledState(MODULO_1, PIN_12, LOW);
				ledState(MODULO_1, PIN_14, LOW);
				ledState(MODULO_1, PIN_5, LOW);
				ledState(MODULO_1, PIN_1, LOW);
				ledState(MODULO_1, PIN_2, LOW);
				ledState(MODULO_1, PIN_13, LOW);
				ledState(MODULO_1, PIN_15, LOW);
				ledState(MODULO_1, PIN_30, LOW);
				ledState(MODULO_1, PIN_0, LOW);
			}
			
			delay();
			if(button_is_press(MODULO_1, PIN_16)){
				break;
			}	
		}
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  ledBlink_4_pins
 *  Description:
 * =====================================================================================
 */


void ledBlink_4_pins(){
		while(1){

			if(button_is_press(MODULO_2, PIN_6)){
				ledBlink(MODULO_1, PIN_1);
				ledBlink(MODULO_1, PIN_31);
				ledBlink(MODULO_1, PIN_14);
				ledBlink(MODULO_1, PIN_12);
				ledBlink(MODULO_1, PIN_14);
				ledBlink(MODULO_1, PIN_31);
				ledBlink(MODULO_1, PIN_1);
			}


			if(button_is_press(MODULO_2, PIN_6)){
				break;
			}
			delay();

		}
		while(1){
			if(button_is_press(MODULO_2, PIN_6)){
				ledBlink(MODULO_1, PIN_1);
				ledBlink(MODULO_1, PIN_12);
				ledBlink(MODULO_1, PIN_31);
				ledState(MODULO_1, PIN_14, HIGH);
				ledState(MODULO_1, PIN_5, HIGH);
				ledState(MODULO_1, PIN_12, HIGH);
				ledState(MODULO_1, PIN_1, HIGH);

				ledState(MODULO_1, PIN_14, LOW);
				ledState(MODULO_1, PIN_31, LOW);
				ledState(MODULO_1, PIN_12, LOW);
				ledState(MODULO_1, PIN_1, LOW);			
			}	
			if(button_is_press(MODULO_2, PIN_6)){
				break;
			}
			delay();		
		}
		while(1){
			if(button_is_press(MODULO_2, PIN_6)){
				ledState(MODULO_1, PIN_1, HIGH);
				ledState(MODULO_1, PIN_5, HIGH);
				ledState(MODULO_1, PIN_14, HIGH);
				ledState(MODULO_1, PIN_12, HIGH);

				ledState(MODULO_1, PIN_12, LOW);
				ledState(MODULO_1, PIN_14, LOW);
				ledState(MODULO_1, PIN_31, LOW);
				ledState(MODULO_1, PIN_1, LOW);
			}
			if(button_is_press(MODULO_2, PIN_6)){
				break;
			}
			delay();
		}
}




//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------



/*FUNCTION*-------------------------------------------------------
*
* Function Name : gpioAintcconfigure
* Comments      : Do the necessary gpio configurations on to AINTC.
*END*-----------------------------------------------------------*/
void gpioAintcConf(void){

    /* Initialize the ARM interrupt control */
    IntAINTCInit();
 
    /* Registering gpioIsr */
    IntRegister(SYS_INT_GPIOINT1A, gpioIsr);
    
    /* Set the priority */
    IntPrioritySet(SYS_INT_GPIOINT1A, 0, AINTC_HOSTINT_ROUTE_IRQ);
    
    /* Enable the system interrupt */
    IntSystemEnable(SYS_INT_GPIOINT1A);
   
}


//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------



/*FUNCTION*-------------------------------------------------------
*
* Function Name : gpioIsr
* Comments      : DMTimer interrupt service routine. This will 
* send a character to serial.
*END*-----------------------------------------------------------*/    
static void gpioIsr(void) {
	//flagIsr = 1;
	op++;	
    	/*	Clear wake interrupt	*/
	//HWREG(SOC_GPIO_1_REGS + 0x3C) = 0x1000;
	//HWREG(SOC_GPIO_1_REGS + 0x34) = 0x1000;
	//ConsoleUtilsPrintf("\nAAAAAA\n");
	//HWREG(SOC_GPIO_1_REGS + 0x2C) = 0x10000;
	HWREG(GPIO_1_REGS + 0x2C) = (1 << 16);
	
	//vel += 100;

}


//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------



/*FUNCTION*-------------------------------------------------------
*
* Function Name : gpioPinIntConfig
* Comments      :
*END*-----------------------------------------------------------*/
int gpioPinIntConf(unsigned int baseAdd, unsigned int intLine,
                  unsigned int pinNumber){

    	/* Setting interrupt GPIO pin. */
    	gpioPinIntEnable(baseAdd,
               intLine,
               pinNumber);
    
    	return(0);
}


//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------


/*FUNCTION*-------------------------------------------------------
*
* Function Name : gpioAintcconfigure
* Comments      : This API configures the event type for a specified 
* input GPIO pin. Whenever the selected event occurs on that GPIO pin 
* and if interrupt generation is enabled for that pin, the GPIO module 
* will send an interrupt to CPU.
*
* \param  baseAdd    The memory address of the GPIO instance being used
* \param  pinNumber  The number of the pin in the GPIO instance
* \param  eventType  This specifies the event type on whose detection,
*                    the GPIO module will send an interrupt to CPU,
*                    provided interrupt generation for that pin is enabled.
*
* 'pinNumber' can take one of the following values:
* (0 <= pinNumber <= 31)\n
*
* 'eventType' can take one of the following values:
* - GPIO_INT_TYPE_NO_LEVEL - no interrupt request on occurence of either a
*   logic LOW or a logic HIGH on the input GPIO pin\n
* - GPIO_INT_TYPE_LEVEL_LOW - interrupt request on occurence of a LOW level
*   (logic 0) on the input GPIO pin\n
* - GPIO_INT_TYPE_LEVEL_HIGH - interrupt request on occurence of a HIGH level
*   (logic 1) on the input GPIO pin\n
* - GPIO_INT_TYPE_BOTH_LEVEL - interrupt request on the occurence of both the
*   LOW level and HIGH level on the input GPIO pin\n
* - GPIO_INT_TYPE_NO_EDGE -  no interrupt request on either rising or
*   falling edges on the pin\n
* - GPIO_INT_TYPE_RISE_EDGE - interrupt request on occurence of a rising edge
*   on the input GPIO pin\n
* - GPIO_INT_TYPE_FALL_EDGE - interrupt request on occurence of a falling edge
*   on the input GPIO pin\n
* - GPIO_INT_TYPE_BOTH_EDGE - interrupt request on occurence of both a rising
*   and a falling edge on the pin\n
*
* \return  None
*
* \note  A typical use case of this API is explained below:
* 
*        If it is initially required that interrupt should be generated on a
*        LOW level only, then this API can be called with
*        'GPIO_INT_TYPE_LEVEL_LOW' as the parameter.
*        At a later point of time, if logic HIGH level only should be made as
*        the interrupt generating event, then this API has to be first called
*        with 'GPIO_INT_TYPE_NO_LEVEL' as the parameter and later with
*        'GPIO_INT_TYPE_LEVEL_HIGH' as the parameter. Doing this ensures that
*        logic LOW level trigger for interrupts is disabled.
*END*-----------------------------------------------------------*/

void gpioIntTypeSet(unsigned int baseAdd, unsigned int pinNumber, unsigned int eventType){
    eventType &= 0xFF;

    switch(eventType)
    {

        case GPIO_INT_TYPE_NO_LEVEL:

            /* Disabling logic LOW level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(0)) &= ~(1 << pinNumber);

            /* Disabling logic HIGH level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(1)) &= ~(1 << pinNumber);

        break;

        case GPIO_INT_TYPE_LEVEL_LOW:

            /* Enabling logic LOW level detect interrupt geenration. */
            HWREG(baseAdd + GPIO_LEVELDETECT(0)) |= (1 << pinNumber);

            /* Disabling logic HIGH level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(1)) &= ~(1 << pinNumber);

            /* Disabling rising edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_RISINGDETECT) &= ~(1 << pinNumber);

            /* Disabling falling edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_FALLINGDETECT) &= ~(1 << pinNumber);

        break;

        case GPIO_INT_TYPE_LEVEL_HIGH:

            /* Disabling logic LOW level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(0)) &= ~(1 << pinNumber);

            /* Enabling logic HIGH level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(1)) |= (1 << pinNumber);

            /* Disabling rising edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_RISINGDETECT) &= ~(1 << pinNumber);

            /* Disabling falling edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_FALLINGDETECT) &= ~(1 << pinNumber);
        
        break;

        case GPIO_INT_TYPE_BOTH_LEVEL:
            
            /* Enabling logic LOW level detect interrupt geenration. */
            HWREG(baseAdd + GPIO_LEVELDETECT(0)) |= (1 << pinNumber);

            /* Enabling logic HIGH level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(1)) |= (1 << pinNumber);

            /* Disabling rising edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_RISINGDETECT) &= ~(1 << pinNumber);

            /* Disabling falling edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_FALLINGDETECT) &= ~(1 << pinNumber);
            
        break;

        case GPIO_INT_TYPE_NO_EDGE:
            
            /* Disabling rising edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_RISINGDETECT) &= ~(1 << pinNumber);

            /* Disabling falling edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_FALLINGDETECT) &= ~(1 << pinNumber);

        break;

        case GPIO_INT_TYPE_RISE_EDGE:

            /* Enabling rising edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_RISINGDETECT) |= (1 << pinNumber);

            /* Disabling falling edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_FALLINGDETECT) &= ~(1 << pinNumber);

            /* Disabling logic LOW level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(0)) &= ~(1 << pinNumber);

            /* Disabling logic HIGH level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(1)) &= ~(1 << pinNumber);

        break;

        case GPIO_INT_TYPE_FALL_EDGE:

            /* Disabling rising edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_RISINGDETECT) &= ~(1 << pinNumber);

            /* Enabling falling edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_FALLINGDETECT) |= (1 << pinNumber);

            /* Disabling logic LOW level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(0)) &= ~(1 << pinNumber);

            /* Disabling logic HIGH level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(1)) &= ~(1 << pinNumber);

        break;

        case GPIO_INT_TYPE_BOTH_EDGE:

            /* Enabling rising edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_RISINGDETECT) |= (1 << pinNumber);

            /* Enabling falling edge detect interrupt generation. */
            HWREG(baseAdd + GPIO_FALLINGDETECT) |= (1 << pinNumber);

            /* Disabling logic LOW level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(0)) &= ~(1 << pinNumber);

            /* Disabling logic HIGH level detect interrupt generation. */
            HWREG(baseAdd + GPIO_LEVELDETECT(1)) &= ~(1 << pinNumber);

        break;

        default:
        break;
    }
}



//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------



/*FUNCTION*-------------------------------------------------------
*
* Function Name : GPIOPinIntEnable
* Comments      : This API enables the configured interrupt event on a specified input
* GPIO pin to trigger an interrupt request.
*
* \param  baseAdd     The memory address of the GPIO instance being used
* \param  intLine     This specifies the interrupt request line on which the
*                     interrupt request due to the transitions on a specified
*                     pin be propagated
* \param  pinNumber   The number of the pin in the GPIO instance
*
* 'intLine' can take one of the following two values:
* - GPIO_INT_LINE_1 - interrupt request be propagated over interrupt line 1\n
* - GPIO_INT_LINE_2 - interrupt request be propagated over interrupt line 2\n
* 
* 'pinNumber' can take one of the following values:
* (0 <= pinNumber <= 31)\n
*
* \return None
*
*END*-----------------------------------------------------------*/
void gpioPinIntEnable(unsigned int baseAdd, unsigned int intLine, unsigned int pinNumber){
    if(GPIO_INTC_LINE_1 == intLine){
        HWREG(baseAdd + GPIO_IRQSTATUS_SET(0)) = (1 << pinNumber);
    }else{
        HWREG(baseAdd + GPIO_IRQSTATUS_SET(1)) = (1 << pinNumber);
    }
}







void GPIO1ModuleClkConfig(void)
{

    /* Writing to MODULEMODE field of CM_PER_GPIO1_CLKCTRL register. */
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE !=
          (HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) &
           CM_PER_GPIO1_CLKCTRL_MODULEMODE));
    /*
    ** Writing to OPTFCLKEN_GPIO_1_GDBCLK bit in CM_PER_GPIO1_CLKCTRL
    ** register.
    */
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK;

    /*
    ** Waiting for OPTFCLKEN_GPIO_1_GDBCLK bit to reflect the desired
    ** value.
    */
    while(CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK !=
          (HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) &
           CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK));

    /*
    ** Waiting for IDLEST field in CM_PER_GPIO1_CLKCTRL register to attain the
    ** desired value.
    */
    while((CM_PER_GPIO1_CLKCTRL_IDLEST_FUNC <<
           CM_PER_GPIO1_CLKCTRL_IDLEST_SHIFT) !=
           (HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) &
            CM_PER_GPIO1_CLKCTRL_IDLEST));

    /*
    ** Waiting for CLKACTIVITY_GPIO_1_GDBCLK bit in CM_PER_L4LS_CLKSTCTRL
    ** register to attain desired value.
    */
    while(CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_1_GDBCLK !=
          (HWREG(SOC_CM_PER_REGS + CM_PER_L4LS_CLKSTCTRL) &
           CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_1_GDBCLK));
}