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
#include "ISL_29125.h"

//uint8 wrBuf[10];
//uint8 userArray[10];
//uint8 byteCnt;

uint8 index_ISL_29125 = 0;
uint8 Light_bytes[5];
uint16 values[50];
int Light; 
int red = 0;
int green = 0;
int blue = 0;

void Lightread(){
    /* start sensor  */
    for (uint8 i=0; i< 5; i++)  
       Light_bytes[i] = 0; 
   
    Light_Write(0u); // MCU sends out start signal
    CyDelay(19); 
    Light_Write(1u); //  for up and wait for response

    while(Light_Read()==1) 
    { //LCD_Position(1,0); LCD_PrintString("11");
    }
    while(Light_Read()==0) 
    {//LCD_Position(1,0); LCD_PrintString("12");
    }
    while(Light_Read()==1) 
    {//LCD_Position(1,0); LCD_PrintString("12");
    }
    CyDmaChDisable(DMA_Timer_TD);
    
    /* read sensor  */
    Timer_DHT_Start();
    index_ISL_29125 = 0;
}



/* [] END OF FILE */



