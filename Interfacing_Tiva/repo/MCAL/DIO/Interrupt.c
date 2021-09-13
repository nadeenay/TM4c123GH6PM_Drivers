#include "Important_Mac.h"
#include "Interrupt_REG.h"
#include "Interrupt_Types.h"
#include "Interrupt.h"
#include "STD_Data_Types.h"
#include "DIO_Types.h"
#include "GPIO_REG.h"




//-------------------------------------------------->Interrupt functions<-----------------------------------------//
/* Function Name: Processor_Enable_Interrupt
 * Fucntion description: enables the interrupt
 */
 void Processor_Enable_Interrupt()
 {
     asm(" CPSIE i");            /*Assembly instruction to enable interrupts "Change Processor State Interrupt Enable"*/
 }

 /* Function Name: Processor_Disable_Interrupt
  * Fucntion description: enables the interrupt
  */
 void Processor_Disable_Interrupt()
 {
     asm(" CPSID i");            /*Assembly instruction to enable interrupts "Change Processor State Interrupt Enable"*/
 }


 /* Function Name: Enable_NVIC_IRQ
  * Fucntion description: enables the interrupt by Enable NVIC for specific IRQ
  */
void Enable_NVIC_IRQ(u8 IRQ )
{
    if(IRQ<=31 && IRQ >=0)
    {
        SETBIT(GET_REG(NVIC,EN0),IRQ);
    }
    else if (IRQ<=63 && IRQ>=32)
    {
        SETBIT(GET_REG(NVIC,EN1),IRQ-32);
    }
    else if (IRQ<=95 && IRQ >=64)
    {
        SETBIT(GET_REG(NVIC,EN2),IRQ-64);
    }
    else if (IRQ<=127 && IRQ >=96)
    {
        SETBIT(GET_REG(NVIC,EN3),IRQ-96);
    }
    else if (IRQ<=138 && IRQ >=128)
    {
        SETBIT(GET_REG(NVIC,EN4),IRQ-128);
    }
}

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
   * Function_Name:GPIOF_Handler
   * Function_Description:Hadler for Interrupt on Pin4 in PORTF this handler will Toggle the red Led in Pin1
  */

 void GPIOF_Handler(void)
 {

     TOGGLEBIT(GET_REG(PORTF,GPIODATA),1);
     GET_REG(PORTF,GPIOICR)|=(1<<4);
 }
 /*
  * Function_Name:INT_Prevent_False_Interrupts
  * Function_Description:Prevent false interrupt and set the interrupt type and edge type or level type
 */
void INT_Config(struct Interrupt_config C1,u8 IRQ)
{

    /*1- Disable Interrupt*/
    Processor_Disable_Interrupt() ;
    //ul* Port_Base;
   /* 2- Mask the corresponding port */
   // GETREG(INT_Get_BASE(port),GPIOIM)|=Interrupt_Port_Disable;
    GET_REG(C1.port,GPIOIM)|=Interrupt_Port_Disable;

   /* 3- Set the Type of the Interrupt (Edge ,Level) */
    GET_REG(C1.port,GPIOIS)|=(C1.Type<<C1.Pin);

    /*4- Set the number of edges to sense in it */
    GET_REG(C1.port,GPIOIBE)|=(C1.Ed_Num<<C1.Pin);

    /* 5- Set the Type of the Edge or Level (high ,Low) */
    GET_REG(C1.port,GPIOIEV)|=(C1.LE_Type<<C1.Pin);


   /* 6- Clear the GPIORIS register by set 0xFF in GPIOICR register */
    GET_REG(C1.port,GPIOICR)=0xFF;


   /* There are three functions to enable Interrupt */

   /* 1- Unmask the port */
    GET_REG(C1.port,GPIOIM)|=Interrupt_Port_Enable ;

    /*2- Enable NVIC for required IRQ*/
    Enable_NVIC_IRQ(IRQ);

    /*3- Enable Interrupt*/
    Processor_Enable_Interrupt();

}


