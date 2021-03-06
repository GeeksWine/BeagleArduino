#include <tsc_adc.c>

#define TSC_ADC_INSTANCE          (SOC_ADC_TSC_0_REGS) //this uses <soc_AM335x.h>


/* Since using it only for ADC purpose, no touchscreen purpose 
therefore, only configured in SW mode */


/* initializes the ADC step configuration bits */

void adc_step_configure()
{
	
	/* using one shot software enable mode */
	TSCADCTSStepModeConfig(TSC_ADC_INSTANCE, 1 ,TSCADC_ONE_SHOT_SOFTWARE_ENABLED);

	/* averaging 8 samples */	
	TSCADCTSStepAverageConfig(TSC_ADC_INSTANCE, 1 ,TSCADC_EIGHT_SAMPLES_AVG);
	
	
	/* sampled data will be stored in FIFO1 */	
	TSCADCTSStepFIFOSelConfig(TSC_ADC_INSTANCE, 1 ,TSCADC_FIFO_1);

	/* enable step 1 */
	TSCADCConfigureStepEnable(TSC_ADC_INSTANCE, 1,1);
}

/*initializes ADC ctrl bits*/
void adc_ctrl()
{	
	/* enabling the TSC_ADC_SS module */
	TSCADCModuleStateSet(TSCADC_MODULE_ENABLE);

	/* enabling this will store channel id and captured ADC data */
	TSCADCStepIDTagConfig(TSC_ADC_INSTANCE, 1);
	
	/*power up the ADC module*/	
	TSCADCSetADCPowerUp(TSC_ADC_INSTANCE);
}


/*initializes ADC idle config bits*/
void adc_idle_config(unsigned int pin)
{
	unsigned int adcPositiveInp
	if (pin == 1)
	{
		adcPositiveInp = TSCADC_POSITIVE_INP_CHANNEL1;
	}
	/* This enable the analog channel 1 */
 TSCADCIdleStepConfig(TSC_ADC_INSTANCE,TSCADC_NEGATIVE_REF_ADCREFM,adcPositiveInp,TSCADC_NEGATIVE_INP_ADCREFRM,TSCADC_POSITIVE_REF_ADCREFP);
}
 

/* enable or disable interrupt */
void interrupt_enable(unsigned int enable)
{
	if (enable==1)
	{
		TSCADCEventInterruptEnable(TSC_ADC_INSTANCE, TSCADC_END_OF_SEQUENCE_INT);
	}
	else
	{
		TSCADCEventInterruptDisable(TSC_ADC_INSTANCE, TSCADC_END_OF_SEQUENCE_INT);
	}
}

/*red interrupt status*/
unsigned int interrupt_status()
{
	return(TSCADCIntStatusRead(TSC_ADC_INSTANCE, TSCADC_END_OF_SEQUENCE_INT));
}


/*reading data from ADC*/
unsigned int adc_read()
{
	/* gives the ADC sampled data */
	return(TSCADCFIFOADCDataRead(TSC_ADC_INSTANCE, TSCADC_FIFO_1));
}


/*initializes the ADC module by setting all registers*/
void adc_init(unsigned int pin)
{
	adc_step_configure();
	adc_ctrl();
	adc_idle_config(unsigned int pin);
	interrupt_enable(1); // enabling interrupt
}

void adc_exit(unsigned int pin)
{
	/* for SW one shot mode, after one sequence, automatically bits will be reset*/
	interrupt_enable(0);
	TSCADCSetADCPowerDown(TSC_ADC_INSTANCE); // power down the ADC
}

void main ()
{
	int pin =1;
	int output; 
	adc_init(pin);
	while(interrupt_status()==1);
	output = adc_read();
	adc_exit(pin);
}
