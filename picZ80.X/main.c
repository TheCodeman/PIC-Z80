/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q84
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

#include <stdio.h>
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/pin_manager.h"
uint8_t I2C1_Read1ByteRegister(i2c1_address_t address, uint8_t reg);
#define READ 0x05
#define WRITE 0x03
uint8_t wreg_a = 0;
uint8_t wregs_a[8];
uint8_t rregs_a[3];
uint8_t wreg_b = 0;
uint8_t wregs_b[8];
uint8_t rregs_b[3];
uint8_t data = 0;
uint8_t add = 0;

uint8_t sioreset = 0;
uint8_t have_wreg_a = 0;
uint8_t have_wreg_b = 0;
//#define rc_mode
#ifdef rc_mode
#define data_a  0x81
#define cmd_a   0x80
#define data_b  0x83
#define cmd_b   0x82
#else
#define data_a  0x80
#define cmd_a   0x82
#define data_b  0x81
#define cmd_b   0x83
#endif
#define i2cAddress_r 0x86
#define i2cStatus_r  0x86
#define i2cData_r    0x87
#define i2cLength_r  0x88
#define dac 0x8a

uint8_t i2cAddress = 0;
uint8_t i2cData[255];
uint8_t i2cStatus = 0;
uint8_t i2cLength = 0;

void CLC3_ISR(void) {
    //LATCbits.LATC0 = 1;
    add = PORTA;
    RC1 = 1;
#if 0
    U1TXB = 0x00;
    __delay_us(100);
    U1TXB = PORTA;
    __delay_us(100);
    U1TXB = PORTE & 0x7;
    __delay_us(100);
    U1TXB = PORTD;
    __delay_us(100);
#endif


    if (((PORTE & 0x07) == WRITE) && add == dac) { //8a     
        DAC1_SetOutput(PORTD);
        DELAY_microseconds(105);
        goto done;
    }

    //i2c code
    // write i2c address
    if (((PORTE & 0x07) == WRITE) && add == i2cAddress_r) { //86
        printf("Address %02x\n\r", PORTD);
        i2cAddress = PORTD;
        goto done;
    }
    // read i2c status
    if (((PORTE & 0x07) == READ) && add == i2cStatus_r) { //86

        PORTD = i2cStatus;
        TRISD = 0x00;
        goto done;
    }
    // write i2c data
    if (((PORTE & 0x07) == WRITE) && add == i2cData_r) { //86
        printf("Data Out %02x\n\r", PORTD);
        i2cData[0] = PORTD;
        goto done;
    }
    // read i2c data
    if (((PORTE & 0x07) == READ) && add == i2cData_r) { //86
        i2cData[0]=I2C1_Read1ByteRegister(i2cAddress, i2cLength);
        printf("Data In %02x\n\r", PORTD);
        PORTD = i2cData[0];
        TRISD = 0x00;
        goto done;
    }
     // write i2c length
    if (((PORTE & 0x07) == WRITE) && add == i2cLength_r) { //86
        i2cLength = PORTD;
        goto done;
    }   



    if (((PORTE & 0x07) == WRITE) && add == data_b) { //81
        UART1_Write(PORTD);
        goto done;
    }
    if (((PORTE & 0x07) == WRITE) && add == cmd_a) { //82

        if (have_wreg_a == 2) {
            have_wreg_a = 0;
            goto done;
        }
        if (have_wreg_a == 1) {
            wregs_a[wreg_a] = PORTD;
            have_wreg_a = 2;
            goto done;
        }
        if (have_wreg_a == 0) {
            wreg_a = PORTD;
            have_wreg_a = 1;
            goto done;
        }

    }

    if (((PORTE & 0x07) == WRITE) && add == cmd_b) {//83
        if (have_wreg_b == 2) {
            have_wreg_b = 0;
            goto done;
        }
        if (have_wreg_b == 1) {
            wregs_b[wreg_b] = PORTD;
            have_wreg_b = 2;
            goto done;
        }
        if (have_wreg_b == 0) {
            wreg_b = PORTD;
            have_wreg_b = 1;
            goto done;
        }
    }
    if (((PORTE & 0x07) == READ) && add == data_a) {//80

        if (UART1_is_rx_ready()) {
            data = UART1_Read();
            PORTD = data;
            TRISD = 0x00;
        }
        goto done;
    }
    if (((PORTE & 0x07) == READ) && add == data_b) {//81

        if (UART1_is_rx_ready()) {
            data = UART1_Read();
            PORTD = data;
            TRISD = 0x00;
        }
        goto done;
    }
    if (((PORTE & 0x07) == READ) && add == cmd_a) {//82
        data = 0x68;
        if (UART1_is_rx_ready()) {
            data |= 0x01;
        }
        if (UART1_is_tx_ready()) {
            data |= 0x04;
        }
        if (have_wreg_a == 2 || have_wreg_a == 1) {
            data = wregs_a[wreg_a];
            have_wreg_a = 0;
            sioreset = 0;
        }
        PORTD = data;
        TRISD = 0x00;
        goto done;
    }
    if (((PORTE & 0x07) == READ) && add == cmd_b) {//83
        data = 0x68;
        if (UART1_is_rx_ready()) {
            data |= 0x01;
        }
        if (UART1_is_tx_ready()) {
            data |= 0x04;
        }
        if (have_wreg_b == 2 || have_wreg_b == 1) {
            data = wregs_b[wreg_b];
            have_wreg_b = 0;
            sioreset = 0;
        }
        PORTD = data;
        TRISD = 0x00;
        goto done;
    }
done:
    // Clear the CLC interrupt flag
    CLCSELECT = 0x02;
    CLCnPOL = 0x80;
    TRISD = 0xff;
    //LATCbits.LATC0 = 0;
#if 0
    NOP();
    NOP();
    NOP();
    NOP();
#endif
    NOP();
    NOP();
    NOP();
    NOP();
    PIR7bits.CLC3IF = 0;
    CLCnPOL = 0x8C;
    RC1 = 0;
}

void FatFsDemo_Tasks(void);
#include "mcc_generated_files/fatfs/ff.h"

void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:
#if 0
    uint8_t count;
    PWM1_16BIT_Enable();
    PWM1_16BIT_WritePeriodRegister(1000);
    while (1) {

    }
#endif
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    //FatFsDemo_Tasks();
    static FATFS drive;
    static FIL file;
    f_mount(&drive, "0:", 1);
    FRESULT res;
    FFDIR dir;
    res = f_opendir(&dir, &drive);
    FILINFO fileInfo;
    uint32_t totalFiles = 0;
    uint32_t totalDirs = 0;
    printf("--------\r\nRoot directory:\r\n");
    for (;;) {
        res = f_readdir(&dir, &fileInfo);
        if ((res != FR_OK) || (fileInfo.fname[0] == '\0')) {
            break;
        }

        if (fileInfo.fattrib & AM_DIR) {
            printf("  DIR  %s\r\n", fileInfo.fname);
            totalDirs++;
        } else {
            printf("  FILE %s %d\r\n", fileInfo.fname, fileInfo.fsize);
            totalFiles++;
        }
    }

    printf("(total: %lu dirs, %lu files)\r\n--------\r\n", totalDirs, totalFiles);
    LATCbits.LATC0 = 1;
    while (1) {
        // Add your application code
    }
}
/**
 End of File
 */