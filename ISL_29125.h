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
*/#if !defined(__ISL_29125_H) 
#define __ISL_29125_H
    
#include <project.h>
    
    
#define DMA_TIMER_BYTES_PER_BURST 2
#define DMA_TIMER_REQUEST_PER_BURST 1
#define DMA_TIMER_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_TIMER_DST_BASE (CYDEV_SRAM_BASE)    
    
    
uint8 DMA_Timer_Chan;
uint8 DMA_Timer_TD;


/***************************************
*        Function Prototypes
***************************************/  

void dma_config();
void calc_temp_humidty();
void Lightread();
    
#endif

/* [] END OF FILE */


/* [] END OF FILE */
