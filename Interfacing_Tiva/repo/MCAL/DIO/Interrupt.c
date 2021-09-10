#include "Important_Mac.h"
#include "Interrupt_REG.h"
#include "Interrupt_Types.h"
#include "Interrupt.h"
#include "STD_Data_Types.h"
#include "DIO_Types.h"



//-------------------------------------------------->Interrupt functions<-----------------------------------------//


/*
 * Function_Name:GPIO_Get_Base
 * Function_Description:this function will take the port number(0-->A,1-->B,..) and return it's base
*/
 ul* INT_Get_BASE(ui Port_E)
{
    switch(Port_E)
    {
    case PORTAE:   return ((ul*)(PORTA));
    case PORTBE:   return ((ul*)(PORTB));
    case PORTCE:   return ((ul*)(PORTC));
    case PORTDE:   return ((ul*)(PORTD));
    case PORTEE:   return ((ul*)(PORTE));
    case PORTFE:   return ((ul*)(PORTF));
    default:       return null;
    }
}


 /*
  * Function_Name:INT_Prevent_False_Interrupts
  * Function_Description:Prevent false interrupt and set the interrupt type and edge type or level type
 */
void INT_Prevent_False_Interrupts(ul* port_Base,Interrupt_Type Type,Level_O_Edge__Type LE_Type)
{
    //ul* Port_Base;
   /* 1. Mask the corresponding port */
   // GETREG(INT_Get_BASE(port),GPIOIM)|=Interrupt_Port_Disable;
    (*((volatile unsigned long *)(0x40004000+GPIOIM)))|=Interrupt_Port_Disable;

   /* 2. Set the Type of the Interrupt (Edge ,Level) */
    GET_REG(port_Base,GPIOIS)|=Type;

    /* 3. Set the Type of the Edge or Level (high ,Low) */
    GET_REG(port_Base,GPIOIS)|=LE_Type;


   /* 4. Clear the GPIORIS register by set 0xFF in GPIOICR register */
    GET_REG(port_Base,GPIOICR)=0xFF;

   /* 5. Unmask the port */
    GET_REG(port_Base,GPIOIM)|=Interrupt_Port_Enable ;

}

/*
  * Function_Name:INT_Confi
  * Function_Description:Set the Configuration of the Interrupt
 */

void INT_Config(struct Interrupt_config C1)
{
    INT_Prevent_False_Interrupts(C1.port,C1.Type,C1.LE_Type);
}



