#ifndef _GPIO_H_
#define _GPIO_H_

void watchdog_disable();
void delay();
void pinInit(int module, int pino, int state);
void clkConfig(int module);
void ledState(int module, int pino, int state);
void pinConfig(int module, int pino, int puden, int putypesel, int rxactiv);
void inputLedCheck();
void ledBlink(int module, int pin);
bool button_is_press(int modulo_input, int pino_input);
void ledBlink_10_pins();
void ledBlink_4_pins();
void gpioAintcConf(void);
static void gpioIsr(void);
int gpioPinIntConf(unsigned int baseAdd, unsigned int intLine, unsigned int pinNumber);
void gpioIntTypeSet(unsigned int baseAdd, unsigned int pinNumber, unsigned int eventType);
void gpioPinIntEnable(unsigned int baseAdd, unsigned int intLine, unsigned int pinNumber);
void GPIO1ModuleClkConfig(void);

unsigned int op;

enum pino{PIN_0 = 0, PIN_1 = 1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, PIN_8, PIN_9, PIN_10, PIN_11, PIN_12, PIN_13, PIN_14, PIN_15, PIN_16, PIN_17,
 PIN_18, PIN_19, PIN_20, PIN_21, PIN_22, PIN_23, PIN_24, PIN_25, PIN_26, PIN_27, PIN_28, PIN_29, PIN_30, PIN_31};

#define TIME												800000
#define IO													7

#define TOGGLE 												0x01

#define	HIGH												1																					
#define	LOW													0

#define OUTPUT                        						0
#define INPUT               	         					1



#define CONTROL_MODULE										(0x44E10000)		//Base address of control module memory mapped registers

#define MODULO_0											0
#define MODULO_1											1
#define MODULO_2											2
#define MODULO_3											3


/* Values denoting the Interrupt Line number to be used. */
#define GPIO_INTC_LINE_1       					            (0x0)
#define GPIO_INTC_LINE_2                  					(0x1)


/* DEBOUNCENABLE */
#define GPIO_DEBOUNCENABLE_DEBOUNCEENABLE   				(0xFFFFFFFFu)
#define GPIO_DEBOUNCENABLE_DEBOUNCEENABLE_SHIFT   			(0x00000000u)
#define GPIO_DEBOUNCENABLE_DEBOUNCEENABLE_DEBOUNCE   		(0x1u)
#define GPIO_DEBOUNCENABLE_DEBOUNCEENABLE_NODEBOUNCE   		(0x0u)


/* DEBOUNCINGTIME */
#define GPIO_DEBOUNCINGTIME_DEBOUNCETIME   					(0x000000FFu)
#define GPIO_DEBOUNCINGTIME_DEBOUNCETIME_SHIFT   			(0x00000000u)


/* Values used to enable/disable Debouncing feature for an input pin. */
#define GPIO_DEBOUNCE_FUNC_ENABLE        					(GPIO_DEBOUNCENABLE_DEBOUNCEENABLE_DEBOUNCE)
#define GPIO_DEBOUNCE_FUNC_DISABLE       					(GPIO_DEBOUNCENABLE_DEBOUNCEENABLE_NODEBOUNCE)


/* Values denoting the Interrupt Line number to be used. */
#define GPIO_INT_LINE_1                  					(0x0)
#define GPIO_INT_LINE_2                  					(0x1)


/*
** Values used to enable/disable interrupt generation due to level
** detection on an input GPIO pin.
*/
#define GPIO_INT_TYPE_NO_LEVEL          					(0x01)
#define GPIO_INT_TYPE_LEVEL_LOW          					(0x04)
#define GPIO_INT_TYPE_LEVEL_HIGH         					(0x08)
#define GPIO_INT_TYPE_BOTH_LEVEL         					(0x0C)


/*
** Values used to enable/disable interrupt generation due to edge
** detection on an input GPIO pin.
*/
#define GPIO_INT_TYPE_NO_EDGE            					(0x80)
#define GPIO_INT_TYPE_RISE_EDGE          					(0x10)
#define GPIO_INT_TYPE_FALL_EDGE          					(0x20)
#define GPIO_INT_TYPE_BOTH_EDGE          					(0x30)


/*************************************************************************\
 * Registers Definition
\*************************************************************************/

#define GPIO_REVISION   									(0x0)
#define GPIO_SYSCONFIG   									(0x10)
#define GPIO_IRQSTATUS_RAW(n)   							(0x24 + (n * 4))
#define GPIO_IRQSTATUS(n)   								(0x2C + (n * 4))
#define GPIO_IRQSTATUS_SET(n)   							(0x34 + (n * 4))
#define GPIO_IRQSTATUS_CLR(n)   							(0x3C + (n * 4))
#define GPIO_IRQWAKEN(n)   									(0x44 + (n * 4))
#define GPIO_SYSSTATUS   									(0x114)
#define GPIO_CTRL   										(0x130)
#define GPIO_DATAIN   										(0x138)
#define GPIO_DATAOUT   										(0x13C)
#define GPIO_LEVELDETECT(n)   								(0x140 + (n * 4))
#define GPIO_RISINGDETECT   								(0x148)
#define GPIO_FALLINGDETECT   								(0x14C)
#define GPIO_DEBOUNCENABLE   								(0x150)
#define GPIO_DEBOUNCINGTIME   								(0x154)
#define GPIO_CLEARDATAOUT   								(0x190)
#define GPIO_SETDATAOUT   									(0x194)

/*****************************************************************************
**                		PULLUP/PULLDOWN
*****************************************************************************/

#define PULLUP_PULLDOWN_ENABLE								0
#define PULLUP_PULLDOWN_DISABLE								1
#define PULLUP_SELECTED										1
#define PULLDOWN_SELECTED									0
#define RECEIVER_DISABLE									0
#define RECEIVER_ENABLE										1

/*****************************************************************************
**                		WATCHDOG ADRESSES
*****************************************************************************/

#define WDT 												(0x44E35000)		// Base Adress of WatchDog Timer
#define WDT_WSPR											(0x48)	   			// WatchDog Start/Stop Register	
#define WDT_STOP_PART_1										(0xaaaa)
#define WDT_STOP_PART_2										(0x5555)

/*****************************************************************************
**                		BASE CLOCK ADRESS
*****************************************************************************/

#define CM_PER                	        					(0x44E00000)
#define CM_WKUP												(0x44E00400)

/*****************************************************************************
**                		OFFSETS OF CLOCK GPIO
*****************************************************************************/

#define CM_WKUP_GPIO0										(0x08)
#define CM_PER_GPIO1										(0xAC)
#define CM_PER_GPIO2										(0xB0)
#define CM_PER_GPIO3										(0xB4)

/*****************************************************************************
**                	   SHIFT OF CLOCK GPIO ENABLE
*****************************************************************************/

#define CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_0_1_2_3_GDBCLK 	(1 << 18)

/*****************************************************************************
**                	   MODULE MODE OF CLOCK GPIO ENABLE
*****************************************************************************/

#define CM_PER_GPIO_0_1_2_3_CLKCTRL_MODULEMODE_ENABLE	   		(0x2)

/*****************************************************************************
**                	   BASE ADRESS OF GPIO MEMORY MAPPED REGISTERS
*****************************************************************************/

#define GPIO_0_REGS                      					(0x44E07000)
#define GPIO_1_REGS                      					(0x4804C000)
#define GPIO_2_REGS                      					(0x481AC000)
#define GPIO_3_REGS                      					(0x481AE000)

/*****************************************************************************
**                	   OFFSET OF PIN DIRECTION
*****************************************************************************/

#define GPIO_OE                 							(0x134)

/*****************************************************************************
**                	   OFFSET OF PIN_GPIO_0
*****************************************************************************/

#define PIN_GPIO0_00										(0x948)
#define	PIN_GPIO0_01 	                                    (0x94C)
#define	PIN_GPIO0_SPI_02                                    (0x950)
#define	PIN_GPIO0_SPI_03                                    (0x954)
#define	PIN_GPIO0_SPI_04			   					    (0x958)
#define	PIN_GPIO0_SPI_05 							        (0x95C)
#define	PIN_GPIO0_SPI_06                                    (0x960)
#define	PIN_GPIO0_07	                                    (0x964)
#define PIN_GPIO0_LCD_08									(0x8D0)
#define PIN_GPIO0_LCD_09									(0x8D4)
#define PIN_GPIO0_LCD_10									(0x8D8)
#define PIN_GPIO0_LCD_11									(0x8DC) 
#define	PIN_GPIO0_UART_12	                                (0x978)	
#define	PIN_GPIO0_UART_13 			   			     	    (0x97C)
#define	PIN_GPIO0_UART_14	                                (0x980)
#define	PIN_GPIO0_UART_15 									(0x984)
#define	PIN_GPIO0_16										(0x91C)
#define	PIN_GPIO0_17										(0x920)
#define PIN_GPIO0_18										(0xA1C)
#define PIN_GPIO0_19										(0x9B0)
#define PIN_GPIO0_20										(0x9B4)
#define PIN_GPIO0_21										(0x924)
#define PIN_GPIO0_22										(0x820)
#define PIN_GPIO0_23										(0x824)
#define PIN_GPIO0_24										(-1)
#define PIN_GPIO0_25										(-1)
#define PIN_GPIO0_26										(0x828)
#define PIN_GPIO0_27										(0x82C)
#define PIN_GPIO0_28										(0x928) 
#define	PIN_GPIO0_29 										(0x944)
#define	PIN_GPIO0_30 										(0x870)
#define	PIN_GPIO0_31 	                                    (0x874)

/*****************************************************************************
**                	   OFFSET OF PIN_GPIO_1
*****************************************************************************/

#define PIN_GPIO1_00										(0x800)
#define	PIN_GPIO1_01 	                                    (0x804)
#define	PIN_GPIO1_02 	                                    (0x808)
#define	PIN_GPIO1_03 	                                    (0x80C)
#define	PIN_GPIO1_04				   					    (0x810)
#define	PIN_GPIO1_05 								        (0x814)
#define	PIN_GPIO1_06 	                                    (0x818)
#define	PIN_GPIO1_07	                                    (0x81C)
#define PIN_GPIO1_UART_08									(0x968)
#define PIN_GPIO1_UART_09									(0x96C)
#define PIN_GPIO1_UART_10									(0x970)
#define PIN_GPIO1_UART_11									(0x974) 
#define	PIN_GPIO1_12	                                    (0x830)	
#define	PIN_GPIO1_13 			   						    (0x834)
#define	PIN_GPIO1_14	                                    (0x838)
#define	PIN_GPIO1_15 										(0x83C)
#define	PIN_GPIO1_16										(0x840)
#define	PIN_GPIO1_17										(0x844)
#define PIN_GPIO1_18										(0x848)
#define PIN_GPIO1_19										(0x84C)
#define PIN_GPIO1_20										(0x850)
#define PIN_GPIO1_21										(0x854)
#define PIN_GPIO1_22										(0x858)
#define PIN_GPIO1_23										(0x85C)
#define PIN_GPIO1_24										(0x860)
#define PIN_GPIO1_25										(0x864)
#define PIN_GPIO1_26										(0x868)
#define PIN_GPIO1_27										(0x86C)
#define PIN_GPIO1_28										(0x878) 
#define	PIN_GPIO1_29 										(0x87C)
#define	PIN_GPIO1_30 										(0x880)
#define	PIN_GPIO1_31 	                                    (0x884)

/*****************************************************************************
**                	   OFFSET OF PIN_GPIO_2
*****************************************************************************/

#define PIN_GPIO2_00										(0x888)
#define PIN_GPIO2_01										(0x88C)
#define PIN_GPIO2_02 										(0x890)
#define PIN_GPIO2_03 										(0x894)
#define PIN_GPIO2_04 										(0x898)
#define PIN_GPIO2_05 										(0x89C)
#define PIN_GPIO2_06										(0x8A0)
#define PIN_GPIO2_07 										(0x8A4)
#define PIN_GPIO2_08 										(0x8A8)
#define PIN_GPIO2_09 										(0x8AC)
#define PIN_GPIO2_10 										(0x8B0)
#define PIN_GPIO2_11 										(0x8B4)
#define PIN_GPIO2_12 										(0x8B8)
#define PIN_GPIO2_13 										(0x8BC)
#define PIN_GPIO2_14 										(0x8C0)
#define PIN_GPIO2_15 										(0x8C4)
#define PIN_GPIO2_16 										(0x8C8)
#define PIN_GPIO2_17 										(0x8CC)
#define PIN_GPIO2_18 										(0x934)
#define PIN_GPIO2_19 										(0x938)
#define PIN_GPIO2_20 										(0x93C)
#define PIN_GPIO2_21 										(0x940)
#define PIN_GPIO2_22 										(0x8E0)
#define PIN_GPIO2_23 										(0x8E4)
#define PIN_GPIO2_24 										(0x8E8)
#define PIN_GPIO2_25 										(0x8EC)
#define PIN_GPIO2_26 										(0x8F0)
#define PIN_GPIO2_27 										(0x8F4)
#define PIN_GPIO2_28 										(0x8F8)
#define PIN_GPIO2_29 										(0x8FC)
#define PIN_GPIO2_30 										(0x900)
#define PIN_GPIO2_31										(0x904)

/*****************************************************************************
**                	   OFFSET OF PIN_GPIO_3
*****************************************************************************/

#define	PIN_GPIO3_00 	                                    (0x908)
#define	PIN_GPIO3_01 	                                    (0x90C)
#define	PIN_GPIO3_02 	                                    (0x910)
#define	PIN_GPIO3_03 	                                    (0x914)
#define	PIN_GPIO3_04 	                                    (0x918)
#define	PIN_GPIO3_05 	                                    (0x988)
#define	PIN_GPIO3_06 	                                    (0x98C)
#define	PIN_GPIO3_07 	                                    (0x9E4)
#define	PIN_GPIO3_08 	                                    (0x9E8)
#define	PIN_GPIO3_09 	                                    (0x92C)
#define	PIN_GPIO3_10 	                                    (0x930)
#define	PIN_GPIO3_11 	                                    (-1)
#define	PIN_GPIO3_12 	                                    (-1)
#define	PIN_GPIO3_13 	                                    (0xA34)
#define	PIN_GPIO3_14 	                                    (0x990)
#define	PIN_GPIO3_15 	                                    (0x994)
#define	PIN_GPIO3_16 	                                    (0x998)
#define	PIN_GPIO3_17 	                                    (0x99C)
#define	PIN_GPIO3_18 	                                    (0x9A0)
#define	PIN_GPIO3_19 	                                    (0x9A4)
#define	PIN_GPIO3_20 	                                    (0x9A8)
#define	PIN_GPIO3_21 	                                    (0x9AC)


#endif //_GPIO_H_