/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"

#include "DHT11.h"  // only this

char LCD_str[32];

extern int temperature;
extern int humidity;
extern uint8 DHT_bytes[5];

CY_ISR_PROTO(DMA_Done);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */ 
    dma_config();
    LCD_Start();
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("Sensor");
    
    isr_DHT_DONE_StartEx(DMA_Done);
    
    // Sensor init
    VDAC_Start();
    Opamp_Start();
    Pin_1_Write(0);
    for(;;) 
    { 
        DHTread();
        CyDelay(100);  //Delay in milli seconds. 
        
        LCD_Position(1, 0);
        sprintf(LCD_str, "t, h = %i,%i    ", temperature,  humidity);
        LCD_PrintString(LCD_str);
        CyDelay(1000);
   }

 }


        

/* [] END OF FILE */
