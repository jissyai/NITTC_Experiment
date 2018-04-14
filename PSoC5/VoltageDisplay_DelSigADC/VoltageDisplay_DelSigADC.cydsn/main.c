#include <device.h>
#include "stdio.h"
#include "stdlib.h"

#define MAX_SAMPLE	((uint8)128)
#define SIGNAL_SLOPE	1000
#define DIV	7

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

/* The size of the buffer is equal to maximum packet size of the 
*  IN and OUT bulk endpoints. 
*/
#define BUFFER_LEN  64u

char8 *parity[] = { "None", "Odd", "Even", "Mark", "Space" };
char8 *stop[] = { "1", "1.5", "2" };

int main(void)
{
    uint8 i;
    
    int32 adcCounts[MAX_SAMPLE] = {0};
    int32 result = 0;
    int32 sum = 0;
    int16 diff = 0;
    int32 microVolts = 0;
    int32 averageCounts = 0;
    uint8 index = 0;
    
    char displayStr[15] = {'\0'};        

    char8 lineStr[20];
    uint8 state;
	
    CYGlobalIntEnable;

	/* Start USBUART */
	USBUART_1_Start(0u, USBUART_1_3V_OPERATION);
	
    /* Start ADC */
    ADC_Start();
    ADC_StartConvert();

    /* Start LCD */
    LCD_Start();
    
	while(!USBUART_1_GetConfiguration());
	USBUART_1_CDC_Init();
	
    /* Read one sample from the ADC and initialize the filter */
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    result = ADC_GetResult32();
    
    for(i = 0; i < MAX_SAMPLE; i++)
    {
        adcCounts[i] = result;
    }
    
    sum = result << DIV;
    
    averageCounts = result;
    
    for(;;)
    {
		state = USBUART_1_IsLineChanged();
        if(state != 0u)
        {  
            if(state & USBUART_1_LINE_CODING_CHANGED)
            {
                sprintf(lineStr,"BR:%4ld,DB:%d",USBUART_1_GetDTERate(),(uint16)USBUART_1_GetDataBits());
                LCD_Position(0u, 0u);
                LCD_PrintString("                    ");
                LCD_Position(0u, 0u);
                LCD_PrintString(lineStr);
                sprintf(lineStr,"SB:%s,Parity:%s", stop[(uint16)USBUART_1_GetCharFormat()], \
                                                     parity[(uint16)USBUART_1_GetParityType()]);
                LCD_Position(1u, 0u);
                LCD_PrintString("                    ");
                LCD_Position(1u, 0u);
                LCD_PrintString(lineStr);
            }
            if(state & USBUART_1_LINE_CONTROL_CHANGED)
            {   
                state = USBUART_1_GetLineControl();
                sprintf(lineStr,"DTR:%s,RTS:%s",  (state & USBUART_1_LINE_CONTROL_DTR) ? "ON" : "OFF", \
                                                    (state & USBUART_1_LINE_CONTROL_RTS) ? "ON" : "OFF");
                LCD_Position(1u, 0u);
                LCD_PrintString("                    ");
                LCD_Position(1u, 0u);
                LCD_PrintString(lineStr);
            
            }
        }
		
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        result = ADC_GetResult32();
        
        diff = abs(averageCounts - result);

        if(diff > SIGNAL_SLOPE)
        {
            for(i = 0; i < MAX_SAMPLE; i++)
            {
                adcCounts[i] = result;
            }
            
            sum = result << DIV;
    
            averageCounts = result;
            index = 0;
        }
        
        else
        {
            sum = sum - adcCounts[index];
            sum = sum + result;
            averageCounts = sum >> DIV;
            
            adcCounts[index] = result;
            index++;
            if (index == MAX_SAMPLE)
            {
                index = 0;
            }
        }
        microVolts = ADC_CountsTo_uVolts(averageCounts);
            
        /* Convert micro volts to string and display */
		if(SW_Read()==0){
			USBUART_1_PutString("ADC input volt = ");
			CyDelay(10);
			sprintf(displayStr,"%7ld",microVolts);
			USBUART_1_PutString(displayStr);
			CyDelay(10);
			USBUART_1_PutString("uV");
			CyDelay(10);
			USBUART_1_PutCRLF();
			CyDelay(1000);
		}
    }	
}

/* [] END OF FILE */

