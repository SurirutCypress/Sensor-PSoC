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
#include <project.h>
#include "DHT11.h"

uint8 DMA_Timer_TD;
uint8 index_DHT11 = 0;
uint8 DHT_bytes[5];
uint16 values[50];
int temperature = 0;
int humidity = 0;


CY_ISR(DMA_Done)
{
    CyDmaChDisable(DMA_Timer_TD);
    calc_temp_humidty();
    Timer_DHT_WriteCounter(9999);
    Timer_DHT_Sleep();
    
}

void DHTread(){
    /* start sensor  */
    for (uint8 i=0; i< 5; i++)  
       DHT_bytes[i] = 0; 
   
    DHT_Write(0u); // MCU sends out start signal
    CyDelay(19); 
    DHT_Write(1u); //  for up and wait for response

    while(DHT_Read()==1) 
    { //LCD_Position(1,0); LCD_PrintString("11");
    }
    while(DHT_Read()==0) 
    {//LCD_Position(1,0); LCD_PrintString("12");
    }
    while(DHT_Read()==1) 
    {//LCD_Position(1,0); LCD_PrintString("12");
    }
    CyDmaChDisable(DMA_Timer_TD);
    
    /* read sensor  */
    Timer_DHT_Start();
    index_DHT11 = 0;
}

void calc_temp_humidty() {
    uint8 cnt=7;
    uint8 idx=0;
    for (uint8 i=4; i < 40; i++) {  
        if ((values[i-1]-values[i])>50){
            DHT_bytes[idx] |= (1<<cnt);
        }
        if (cnt==0){
           idx++;
           cnt=7;
        }
        else {
            cnt--;
        }
    }
    humidity    = DHT_bytes[0];  
    temperature = DHT_bytes[2]; 
}

/* [] END OF FILE */
