/*
 * Interrupt.h
 *
 *  Created on: Sep 10, 2021
 *      Author: Nadeen
 */

#ifndef REPO_MCAL_DIO_INTERRUPT_H_
#define REPO_MCAL_DIO_INTERRUPT_H_
#include "STD_Data_Types.h"

//-------------------------------------------->Struct for the interrupt <---------------------------------------//

struct Interrupt_config
{
    ul port;                         /*Port_Base required for interrupt */
    u8 Pin;                           /*Pin required  for interrupt */
    Interrupt_Type Type;             /*Interrupt type */
    Level_O_Edge__Type LE_Type;      /*Edge type or Level type (rising or falling) */
    Edge_Num Ed_Num;                 /*Sense in both Edges or one */
};



//-------------------------------------------->Public Functions <---------------------------------------//

void INT_Config(struct Interrupt_config C1,u8 IRQ);

void GPIOF_Handler(void);

void Enable_NVIC_IRQ( u8 IRQ );

void Processor_Enable_Interrupt();

#endif /* REPO_MCAL_DIO_INTERRUPT_H_ */
