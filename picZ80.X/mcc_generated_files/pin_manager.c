/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB             :  MPLAB X 6.00

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include "pin_manager.h"





void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISA = 0xFF;
    TRISB = 0xC3;
    TRISC = 0x50;
    TRISD = 0xFF;

    /**
    ANSELx registers
    */
    ANSELD = 0x00;
    ANSELC = 0x00;
    ANSELB = 0xC0;
    ANSELE = 0x00;
    ANSELA = 0x00;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x04;
    ODCONC = 0x0D;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0x0F;





   
    
	
    RC3PPS = 0x38;   //RC3->I2C1:SDA1;    
    CLCIN5PPS = 0x05;   //RA5->CLC1:CLCIN5;    
    RB4PPS = 0x32;   //RB4->SPI1:SDO1;    
    RC2PPS = 0x37;   //RC2->I2C1:SCL1;    
    U1RXPPS = 0x16;   //RC6->UART1:RX1;    
    I2C1SCLPPS = 0x12;   //RC2->I2C1:SCL1;    
    SPI1SCKPPS = 0x0B;   //RB3->SPI1:SCK1;    
    I2C1SDAPPS = 0x13;   //RC3->I2C1:SDA1;    
    CLCIN0PPS = 0x07;   //RA7->CLC3:CLCIN0;    
    RB2PPS = 0x03;   //RB2->CLC3:CLC3;    
    RB3PPS = 0x31;   //RB3->SPI1:SCK1;    
    CLCIN2PPS = 0x08;   //RB0->CLC3:CLCIN2;    
    CLCIN1PPS = 0x06;   //RA6->CLC3:CLCIN1;    
    RC5PPS = 0x22;   //RC5->UART1:RTS1;    
    RC7PPS = 0x20;   //RC7->UART1:TX1;    
    SPI1SDIPPS = 0x09;   //RB1->SPI1:SDI1;    
    U1CTSPPS = 0x14;   //RC4->UART1:CTS1;    
}
  
void PIN_MANAGER_IOC(void)
{   
}

/**
 End of File
*/