/*****************************************************************************
* | File      	:   DEV_Config.h
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master 
*                and enhance portability
*----------------
* |	This version:   V1.0
* | Date        :   2019-03-12
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "beobot_control/Constants.h"



/******************************************************************************
function:	Initialization pin
parameter:
Info:
******************************************************************************/
static void DEV_GPIOConfig(void)
{
    //output
    bcm2835_gpio_fsel(DEV_CS_PIN, BCM2835_GPIO_FSEL_OUTP);
	
}

/******************************************************************************
function:	Module Initialize, the BCM2835 library and initialize the pins, SPI protocol
parameter:
Info:
******************************************************************************/
UBYTE DEV_ModuleInit(void)
{
    if(!bcm2835_init()) {
        printf("bcm2835 init failed  !!! \r\n");
        return 1;
    } else {
        printf("bcm2835 init success !!! \r\n");
    }
	
	DEV_GPIOConfig();

    bcm2835_spi_begin();                                         //Start spi interface, set spi pin for the reuse function
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);     //High first transmission
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE1);                  //spi mode 0
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_8);  //Frequency
    
    DEV_Digital_Write(DEV_CS_PIN, 1);
    return 0;
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
DEV_Config::void DEV_ModuleExit(void)
{
    bcm2835_spi_end();
    bcm2835_close();
}



/******************************************************************************
function:   Write a data to the DAC channel
parameter:
    Channel: Channel number  channel_A and channel_B
    Data   : Written data  0-65535
Info:
******************************************************************************/
static void Write_DAC8532(UBYTE Channel, UWORD Data)
{
    DEV_Digital_Write(DEV_CS_PIN, 1);
    DEV_Digital_Write(DEV_CS_PIN, 0);
    DEV_SPI_WriteByte(Channel);
    DEV_SPI_WriteByte((Data>>8));
    DEV_SPI_WriteByte((Data&0xff));  
    DEV_Digital_Write(DEV_CS_PIN, 1);
}

/******************************************************************************
function:   Specify a channel output voltage value
parameter:
    Channel: Channel number,  channel_A and channel_B
    Voltage: Output voltage value, 0-DAC_VREF
Info:
******************************************************************************/
void DAC8532_Out_Voltage(UBYTE Channel, float Voltage)
{
    UWORD temp = 0;
    if((Voltage <= DAC_VREF) && (Voltage >= 0)){
        temp = (UWORD)(Voltage * DAC_Value_MAX / DAC_VREF);
        Write_DAC8532(Channel, temp);
    }
}

//Handler for the ADC/DAC Board interfaced by SPI
void  Handler(int signo)
{
    //System Exit
    printf("\r\nEND                  \r\n");
    DEV_ModuleExit();

    exit(0);
}

//DAC8532_Out_Voltage(channel_A, DAC_VREF * i / 33);
//DEV_Delay_ms(100);


