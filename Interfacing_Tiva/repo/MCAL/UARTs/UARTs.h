/*
 * UARTs.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Nadeen
 */

#ifndef REPO_MCAL_UARTS_UARTS_H_
#define REPO_MCAL_UARTS_UARTS_H_

/* Includes for the GPIO Configuration */
#include "../DIO/Important_Mac.h"
#include "UATR_Types.h"
#include "UARTs_REG.h"
#include "../DIO/STD_Data_Types.h"
#include "../DIO/DIO.h"
#include "../DIO/GPIO_REG.h"
#include  "../DIO/DIO_Types.h"

/* Data Types */
#include <stdint.h>
#define F_CPU 16000000 /*16 MH*/

struct UART_Config{
    uint8_t U_Num;          /* required UART Module */
    uint8_t PinRx;
    uint8_t PinTx;
    uint8_t Port_Pins;
    uint8_t Data_Length;
    uint8_t Stop_Bit;
    uint8_t Parity_Bit;
    uint32_t Baud_Rate;

};

void UART_Enable_Clock(uint8_t U_Num);


void Pin_Uart_Config(u8 Port,u8 Pin_numRx,u8 Pin_numTx,u8 U_Num);

void UART_Config(struct UART_Config * U_Config);


#endif /* REPO_MCAL_UARTS_UARTS_H_ */
