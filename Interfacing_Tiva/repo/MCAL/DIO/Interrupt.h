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
    ul* port;                         /*Port_Base required for interrupt */
    Interrupt_Type Type;             /*Interrupt type */
    Level_O_Edge__Type LE_Type;      /*Edge type or Level type (rising or falling) */
};



//-------------------------------------------->Public Functions <---------------------------------------//

void INT_Prevent_False_Interrupts(ul*port_Base,Interrupt_Type Type,Level_O_Edge__Type LE_Type);

ul* INT_Get_BASE(ui Port_E);

void INT_Config(struct Interrupt_config C1);


#endif /* REPO_MCAL_DIO_INTERRUPT_H_ */
