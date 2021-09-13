#include "../DIO/Important_Mac.h"
#include "UATR_Types.h"
#include "UARTs_REG.h"
#include "../DIO/STD_Data_Types.h"
#include "../DIO/DIO.h"
#include "../DIO/GPIO_REG.h"
#include  "../DIO/DIO_Types.h"
#include "UARTs.h"

/*
 * Function_Name:UART_Get_Base
 * Function_Description:this function take the UART Module Number and return it's base address
 *
*/

const ul* UART_Get_BASE(UART_Num T)
{
    switch(T)
    {
    case UART_0:  return (ul*)UART0;
    case UART_1:  return (ul*)UART1;
    case UART_2:  return (ul*)UART2;
    case UART_3:  return (ul*)UART3;
    case UART_4:  return (ul*)UART4;
    case UART_5:  return (ul*)UART5;
    default:      return null;

    }
}

/*
 * Function_Name:Pin_Config_Uart
 * Function_Description:Set all the Configuration the pin need to use in UART
 *
*/

void Set_UART_Config(ul Baud_Rate,u8 Data_Length,u8 Stop_bit,u8 Parity_bit,UART_Num U_Num)
{
   /* 1. Disable the UART  */
    CLEARBIT(GET_REG(UART_Get_BASE(U_Num), UARTCTL),0);


   /* 2. Write the integer portion of the BRD .*/
    GET_REG(UART_Get_BASE(U_Num),UARTIBRD)=(unsigned short)(F_CPU/(16*Baud_Rate));


    /* 3. Write the fractional portion of the BRD to the UARTFBRD register */
    GET_REG(UART_Get_BASE(U_Num),UARTFBRD)=((float)(F_CPU/(16*Baud_Rate))*(64)+0.5);

    /* 4- */



}

/*
 * Function_Name:Pin_Config_Uart
 * Function_Description:Set all the Configuration the pin need to use in UART
 *
*/
void Pin_Config_Uart(u8 Port,u8 Pin_num,Pin_Current current,UART_Num U_Num)
{

    /*1- Unlock the Pins */
    GET_REG(GPIO_Get_BASE(Port),GPIOLOCK) = Unlock_Code;     /*Unlock pin in case it is protected  */
    SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOCR),Pin_num);     /* Set the required pin in GPIOCR*/

    /*2- Set the pin to use in Alternative function  (UART) */
    SETBIT(GET_REG(SYSTEM_CONTROL, GPIOAFSEL),U_Num);

    /*3- Set the current Strength */
    GPIO_Set_Current_Str(current,GPIO_Get_BASE(Port),Pin_num);


    /*4- Set the pin to work for UART*/

    switch(Pin_num)
    {
    case PORTAE:
        {

           GET_REG(GPIO_Get_BASE(Port),GPIOPCTL) |=(1<<(Pin_num*3));
           break;

        }
    case PORTBE:
        {
            GET_REG(GPIO_Get_BASE(Port),GPIOPCTL) |=(1<<(Pin_num*3));
            break;

        }
    case PORTCE:
        {
            if(((Pin_num==PIN4|Pin_num==PIN5)&(U_Num==UART_4))|Pin_num==PIN6|Pin_num==PIN7)
            GET_REG(GPIO_Get_BASE(Port),GPIOPCTL) |=(1<<(Pin_num*3));
            else if((Pin_num==PIN4|Pin_num==PIN5)&(U_Num==UART_4))
            GET_REG(GPIO_Get_BASE(Port),GPIOPCTL) |=(2<<(Pin_num*3));
            break;

        }
    case PORTDE:
       {
            GET_REG(GPIO_Get_BASE(Port),GPIOPCTL) |=(1<<(Pin_num*3));
            break;

        }
    case PORTEE:
        {
            GET_REG(GPIO_Get_BASE(Port),GPIOPCTL) |=(1<<(Pin_num*3));
            break;
        }
    default: break;
    }

}
/*
 * Function_Name:UART_Enable_Clock
 * Function_Description:Enable clock to the UART module so we can use the module
 *
*/
void UART_Enable_Clock(UART_Num U_Num)
{
    SETBIT(GET_REG(SYSTEM_CONTROL, RCGCUART),U_Num);
}

/*
 * Function_Name:UART_Config
 * Function_Description:Configuration of the UART
 *
*/
void UART_Config(struct UART_Config * U_Config)
{

   /* 1- Enable the UART module */
    UART_Enable_Clock(U_Config->U_Num);

    /*2- the clock to the appropriate GPIO module */
    GPIO_Port_Enable(U_Config->Port);


    /*3- Set Pin Configuration For UART*/
    Pin_Config_Uart(U_Config->Port,U_Config->Pin,U_Config->C_strength, U_Config->U_Num);


    /*4- Set the UART Configuration (Baud rate ,Data Length ....) */








}


