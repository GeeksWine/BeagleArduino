#include "adc.h"

#define ADC_Address          (SOC_ADC_TSC_0_REGS) //this uses <soc_AM335x.h>

int main ()
{

unsigned int output;
	 
/*Before enabling the TSC_ADC_SS module, first of all we programe 
the Step Configuration registers in order to 
configure a channel input to be sampled. For now only few of them is enabled */


/* selects the FIFO to store the ADC data and also selects the step  which means 
number of times the channel is sampled and stored in FIFO.  
In this case it is 2. It can be 1,2,4,8,16 */
TSCADCTSStepFIFOSelConfig(ADC_Address,2,TSCADC_FIFO_0); 


/* This enables the channel ID store along with the captured ADC data */
TSCADCStepIDTagConfig(ADC_address, 1);


/* this enables the TSC_ADC_SS module*/
TSCADCModuleStateSet(1);


/* Power up the ADC module */	
TSCADCSetADCPowerUp();


/* this gives the ADC Sampled data */
output = TSCADCFIFOADCDataRead(ADC_address,TSCADC_FIFO_0);


/* this gives the channel ID which captured the data */
TSCADCFIFOChannelIDRead(unsigned int baseAdd,unsigned int FIFO1);

/* shut down the ADC */
TSCADCSetADCPowerDown(); 	// power down the ADC

/* disable the TSC_ADC_SS module */
TSCADCModuleStateSet(0);	// disable TSC_ADC_SS module

}
 