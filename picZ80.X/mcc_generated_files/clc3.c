 /**
   CLC3 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     clc3.c
 
   @Summary
     This is the generated driver implementation file for the CLC3 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CLC3.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
         Device            :  PIC18F47Q84
         Driver Version    :  1.0.0
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.36 and above or later
         MPLAB             :  MPLAB X 6.00
 */ 

 /*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
 
 /**
   Section: Included Files
 */

#include <xc.h>
#include "clc3.h"

/**
  Section: CLC3 APIs
*/

void CLC3_Initialize(void)
{
    // Set the CLC3 to the options selected in the User Interface
    
    // SLCT 2; 
    CLCSELECT = 0x02;
    // G1POL not_inverted; G2POL not_inverted; G3POL inverted; G4POL inverted; POL inverted; 
    CLCnPOL = 0x8C;
    // D1S CLC2_OUT; 
    CLCnSEL0 = 0x34;
    // D2S CLC2_OUT; 
    CLCnSEL1 = 0x34;
    // D3S CLC2_OUT; 
    CLCnSEL2 = 0x34;
    // D4S CLC2_OUT; 
    CLCnSEL3 = 0x34;
    // G1D3N disabled; G1D2N disabled; G1D4N disabled; G1D1T disabled; G1D3T disabled; G1D2T disabled; G1D4T disabled; G1D1N enabled; 
    CLCnGLS0 = 0x01;
    // G2D2N disabled; G2D1N enabled; G2D4N disabled; G2D3N disabled; G2D2T disabled; G2D1T disabled; G2D4T disabled; G2D3T disabled; 
    CLCnGLS1 = 0x01;
    // G3D1N disabled; G3D2N disabled; G3D3N enabled; G3D4N disabled; G3D1T disabled; G3D2T disabled; G3D3T disabled; G3D4T disabled; 
    CLCnGLS2 = 0x10;
    // G4D1N disabled; G4D2N disabled; G4D3N disabled; G4D4N enabled; G4D1T disabled; G4D2T disabled; G4D3T disabled; G4D4N disabled; 
    CLCnGLS3 = 0x40;
    // CLC3OUT 0; 
    CLCDATA = 0x00;
    // EN enabled; INTN enabled; INTP disabled; MODE SR latch; 
    CLCnCON = 0x8B;

    // Clear the CLC interrupt flag
    PIR7bits.CLC3IF = 0;
    // Enabling CLC3 interrupt.
    PIE7bits.CLC3IE = 1;
}
/*
void CLC3_ISR(void)
{
    // Clear the CLC interrupt flag
    PIR7bits.CLC3IF = 0;
}
*/
bool CLC3_OutputStatusGet(void)
{
    return(CLCDATAbits.CLC3OUT);
}
/**
 End of File
*/
