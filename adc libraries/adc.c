#include <tsc_adc.c>

#define ADC_Address          (SOC_ADC_TSC_0_REGS) //this uses <soc_AM335x.h>


/* Since using it only for ADC purpose, no touchscreen purpose 
therefore, only sonfigured in SW mode */


/* this initializes the ADC step configuration bits */

void adc_step_configure()
{
	
	/* here we are using one shot software enable mode */
	TSCADCTSStepModeConfig(ADC_Address, 1 ,TSCADC_ONE_SHOT_SOFTWARE_ENABLED);

	/* here we are averaging 8 samples */	
	TSCADCTSStepAverageConfig(ADC_Address, 1 ,TSCADC_EIGHT_SAMPLES_AVG);
	
	
	/* sampled data is stored in FIFO1 */	
	TSCADCTSStepFIFOSelConfig(ADC_Address, 1 ,TSCADC_FIFO_1);

	/* enabling the the step 1 */
	TSCADCConfigureStepEnable(ADC_Address, 1,1);
}

void adc_ctrl()
{	
	/* enabling the TSC_ADC_SS module */
	TSCADCModuleStateSet(TSCADC_MODULE_ENABLE);

	/* enabling this will store channel id and captured ADC data */
	TSCADCStepIDTagConfig(ADC_Address, 1);
	
	/*power up the ADC module*/	
	TSCADCSetADCPowerUp();
}


void adc_idle_config(unsigned int pin)
{
	unsigned int adcPositiveInp
	if (pin == 1)
	{
		adcPositiveInp = TSCADC_NEGATIVE_INP_CHANNEL1;
	}
	/* This enable the analog channel 1 */
	TSCADCIdleStepConfig(ADC_Address, TSCADC_NEGATIVE_REF_ADCREFM,adcPositiveInp,             TSCADC_NEGATIVE_INP_ADCREFRM,TSCADC_POSITIVE_REF_ADCREFP);
}
 
unsigned int adc_read()
{
	/* gives the ADC sampled data */
	return(TSCADCFIFOADCDataRead(ADC_Address, TSCADC_FIFO_1));
}


void adc_init(unsigned int pin)
{
	adc_step_configure();
	adc_ctrl();
	adc_idle_config(unsigned int pin);
}



int main ()
{
	int pin =1;
	int output; 
	adc_init(pin);
	output = adc_read();
}
 
