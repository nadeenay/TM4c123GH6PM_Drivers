/*
 * UARTs.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Nadeen
 */

#ifndef REPO_MCAL_UARTS_UARTS_H_
#define REPO_MCAL_UARTS_UARTS_H_

#define F_CPU 16000000 /*16 MH*/

struct UART_Config{
    UART_Num U_Num;          /* required UART Module */
    u8 Port;                 /* required Port Module */
    u8 Pin;                  /* required Pin */
    Pin_Current C_strength;  /* Required current strength */
};

void UART_Enable_Clock(UART_Num U_Num);


void Pin_Config_Uart(u8 Port,u8 Pin_num,Pin_Current current,UART_Num U_Num);

void UART_Config(struct UART_Config * U_Config);





#endif /* REPO_MCAL_UARTS_UARTS_H_ */
