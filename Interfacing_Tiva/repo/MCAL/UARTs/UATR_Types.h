/*
 * UATR_Types.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Nadeen
 */

#ifndef REPO_MCAL_UARTS_UATR_TYPES_H_
#define REPO_MCAL_UARTS_UATR_TYPES_H_

/* UART Num */

#define  UART_0 0
#define  UART_1 1
#define  UART_2 2
#define  UART_3 3
#define  UART_4 4
#define  UART_5 5
#define  UART_6 6
#define  UART_7 7


/* Pins */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


/*type of  Parity bit */
#define Even_Parity  0x16
#define Odd_Parity   0x12
#define No_Parity    0

/*Data length for the UART*/
#define Length_5   0
#define Length_6   0x20
#define Length_7   0x40
#define Length_8   0x60

/*Stop Bits*/
#define One_Stop_Bit  0
#define Two_Stop_Bit  0x4




#endif /* REPO_MCAL_UARTS_UATR_TYPES_H_ */
