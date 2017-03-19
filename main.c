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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxCountForTurns 300 //count for 2 rotations of the motor

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
     
    uint16 onCount = 0x00;
    uint16 offCount = 0x00;
    uint8 gateClose = 0x00;
    uint8 motorON = 0x00;
    uint8 pirValue = 0x00;  
        
    UART_Start();       
    CyDelay(5000); //delay for PIR sensor setup
    
    
    for(;;)
    {
        if (gateClose == 0x00) {
            pirValue =  pirInput_Read() & 0x01;
        }
        
        if (pirValue) {
            motorON = 0x01;
            UART_PutString("Pet movement detected : Motor will be turned ON\n");
            CyDelay(50); 
        }
        if(motorON) {
            onCount++;
            Control_Reg_Write(0x0c);
            CyDelay(10);          
            Control_Reg_Write(0x06);
            CyDelay(10);           
            Control_Reg_Write(0x03);
            CyDelay(10);          
            Control_Reg_Write(0x09);
            CyDelay(10);            
         }   
            
            if (gateClose) {
                offCount++;
                Control_Reg_Write(0x09);
                CyDelay(10);          
                Control_Reg_Write(0x03);
                CyDelay(10);           
                Control_Reg_Write(0x06);
                CyDelay(10);          
                Control_Reg_Write(0x0c);
                CyDelay(10);                
            }
            
            // turns in fwd direction
            if(onCount > MaxCountForTurns) {
                motorON = 0x00;
                onCount = 0x00;
                pirValue = 0x00;
                CyDelay(50);
                gateClose = 0x01;
            }
            
            // turns in reverse direction
            if(offCount > MaxCountForTurns) {                
                gateClose &= 0x00;
                offCount &= 0x00;
                pirValue = 0x00;
                CyDelay(50);
            }
        }        
    }


/* [] END OF FILE */
