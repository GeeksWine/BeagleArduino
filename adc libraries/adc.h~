#include <tsc_adc.h>
#include <hw_tsc_adc_ss.h>
# include <soc_AM335x.h>

/**
 * \brief   This API sets the ADC Power Up
 **/
void TSCADCSetADCPowerUp(unsigned int baseAdd)
{
    HWREG(baseAdd + TSC_ADC_SS_CTRL) &= ~TSC_ADC_SS_CTRL_POWER_DOWN;
}

/**
 * \brief   This API gets the Channel ID which captured the data.
 * \param   FIFOSel    Selects the FIFO
 *
 * \return  returns the channel ID  
 *
 **/
unsigned int TSCADCFIFOChannelIDRead(unsigned int baseAdd,unsigned int FIFOSel)
{
    return ((HWREG(baseAdd + TSC_ADC_SS_FIFODATA(FIFOSel)) &
		                TSC_ADC_SS_FIFODATA_ADCCHLNID) 
                      >> TSC_ADC_SS_FIFODATA_ADCCHLNID_SHIFT);
}

/**
 * \brief  This API selects the FIFO to store the ADC data
 * \param   stepSel    Step to be configured
 * \param   FIFOSel    Selects the FIFO.\n
 *
 *          FIFOSel can take following macros.\n
 * 
 *          TSCADC_FIFO_0.\n
 *          TSCADC_FIFO_1.\n
 *
 * \return  none  
 *
 **/
void TSCADCTSStepFIFOSelConfig(unsigned int baseAdd, unsigned int stepSel,
	                    unsigned int FIFOSel)
{
    HWREG(baseAdd + TSC_ADC_SS_STEPCONFIG(stepSel)) &= 
                          ~TSC_ADC_SS_STEPCONFIG_FIFO_SELECT;

    HWREG(baseAdd + TSC_ADC_SS_STEPCONFIG(stepSel)) |= 
                           FIFOSel << TSC_ADC_SS_STEPCONFIG_FIFO_SELECT_SHIFT;
}

/**
 * \brief   This API gets the ADC Sampled data
 * \param   FIFOSel    Selects the FIFO.\n
 *
 * \return  returns the channel ID  
 *
 **/
unsigned int TSCADCFIFOADCDataRead(unsigned int baseAdd,unsigned int FIFOSel)
{
    return (HWREG(baseAdd + TSC_ADC_SS_FIFODATA(FIFOSel)) &
		                TSC_ADC_SS_FIFODATA_ADC_DATA);
}

/** 

/**
 * \brief   This API sets the ADC Power Down
 *
 * \param   baseAdd   Base Address of the TouchScreen Module Registers.
 *
 * \return  None 
 *
 **/
void TSCADCSetADCPowerDown(unsigned int baseAdd)
{
    HWREG(baseAdd + TSC_ADC_SS_CTRL) &= ~TSC_ADC_SS_CTRL_POWER_DOWN;
    HWREG(baseAdd + TSC_ADC_SS_CTRL) |= TSC_ADC_SS_CTRL_POWER_DOWN_AFEPOWERDOWN << \
										TSC_ADC_SS_CTRL_POWER_DOWN_SHIFT;
}


/**
 * \brief   This API Enables/Disables the TSCADCSS Module			// written by me 
 * \param   enableModule   Whether the module is to be enabled.
 *
 *          enableModule can take following values.\n
 *
 *          TSCADC_MODULE_DISABLE - Disables  module.\n
 *          TSCADC_MODULE_ENABLE  - Enables the module.\n
 *
 * \return  None 
 *
 **/
void TSCADCModuleStateSet(unsigned int baseAdd,unsigned int enableModule)
{
    HWREG(baseAdd + TSC_ADC_SS_CTRL) &= ~TSC_ADC_SS_CTRL_ENABLE;
    HWREG(baseAdd + TSC_ADC_SS_CTRL) |= enableModule;
}




/**
 * \brief   This API Enables/Disables the TSCADC Module 
 *
 * \param   baseAdd       Base Address of the TouchScreen Module Registers.
 * \param   enableModule   Whether the module is to be enabled.
 *
 *          enableModule can take following values.\n
 *
 *          TSCADC_MODULE_DISABLE - Disables  module.\n
 *          TSCADC_MODULE_ENABLE  - Enables the module.\n
 *
 * \return  None 
 *
 **/
void TSCADCModuleStateSet(unsigned int baseAdd, unsigned int enableModule)
{
    HWREG(baseAdd + TSC_ADC_SS_CTRL) &= ~TSC_ADC_SS_CTRL_ENABLE;
    HWREG(baseAdd + TSC_ADC_SS_CTRL) |= enableModule;
}


/**
 * \brief  This API Configures the number of samples to average
 *
 * \param   baseAdd   Base Address of the TouchScreen Module Registers.
 * \param   stepSel    Step to be configured
 * \param   average    Number of Samples to average.\n
 *
 *          average can take following values.\n
 *
 *          TSCADC_TWO_SAMPLES_AVG.\n
 *          TSCADC_FOUR_SAMPLES_AVG.\n
 *          TSCADC_EIGHT_SAMPLES_AVG.\n
 *          TSCADC_SIXTEEN_SAMPLES_AVG.\n
 *
 * \return  none  
 *
 **/
void TSCADCTSStepAverageConfig(unsigned int baseAdd, unsigned int stepSel,
	                       unsigned int average)
{
    HWREG(baseAdd + TSC_ADC_SS_STEPCONFIG(stepSel))
	        &= ~TSC_ADC_SS_STEPCONFIG_AVERAGING;

    HWREG(baseAdd + TSC_ADC_SS_STEPCONFIG(stepSel))
	        |= average <<  TSC_ADC_SS_STEPCONFIG_AVERAGING_SHIFT;
}


/**
 * \brief   This API enables/disables the channel ID store along with the
 * 	     captured ADC data 
 *
 * \param   baseAdd	      Base Address of the TouchScreen Module Registers.
 * \param   enableStepIDTag   Whether or not step ID is to be stored.
 *
 * \return  None 
 *
 **/
void TSCADCStepIDTagConfig(unsigned int baseAdd, unsigned int enableStepIDTag)
{
    HWREG(baseAdd + TSC_ADC_SS_CTRL) &= ~TSC_ADC_SS_CTRL_STERP_ID_TAG;
    HWREG(baseAdd + TSC_ADC_SS_CTRL) |= enableStepIDTag <<
	                                 TSC_ADC_SS_CTRL_STERP_ID_TAG_SHIFT;
}


