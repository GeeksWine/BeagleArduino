#include "soc_AM335x.h"
#include "gpio_v2.h"


/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/


#define GPIO_INSTANCE_ADDRESS           (SOC_GPIO_1_REGS)
#define GPIO_INSTANCE_PIN_NUMBER        (23)

void pinMode(unsigned int pin, unsigned int mode)
{
    GPIO_INSTANCE_PIN_NUMBER = pin;		//setting pin number to GPIO pin
    
    /* Enabling functional clocks for GPIO1 instance. */
    GPIO1ModuleClkConfig();

    /* Selecting GPIO1[23] pin for use. */
    GPIO1Pin23PinMuxSetup();
    
    /* Enabling the GPIO module. */
    GPIOModuleEnable(GPIO_INSTANCE_ADDRESS);

    /* Resetting the GPIO module. */
    GPIOModuleReset(GPIO_INSTANCE_ADDRESS);

    /* Setting the GPIO pin as an output or input pin. */
    if (mode=="OUTPUT")	
    {
	GPIODirModeSet(GPIO_INSTANCE_ADDRESS,GPIO_INSTANCE_PIN_NUMBER,GPIO_DIR_OUTPUT); // as output
    }
    else
    {
	GPIODirModeSet(GPIO_INSTANCE_ADDRESS,GPIO_INSTANCE_PIN_NUMBER,GPIO_DIR_INPUT);  // as input
    }
   
}

void digitalWrite(unsigned int pin, unsigned int val)
{
    GPIO_INSTANCE_PIN_NUMBER = pin;
    GPIOPinWrite(GPIO_INSTANCE_ADDRESS,GPIO_INSTANCE_PIN_NUMBER,val);
}

int digitalRead(unsigned int pin)
{
    GPIO_INSTANCE_PIN_NUMBER = pin;
    GPIOPinRead(GPIO_INSTANCE_ADDRESS,GPIO_INSTANCE_PIN_NUMBER);

}
