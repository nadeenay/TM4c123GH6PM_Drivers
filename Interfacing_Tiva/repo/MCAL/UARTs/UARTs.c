
#include "UARTs.h"

/*
 * Function_Name:UART_Get_Base
 * Function_Description:this function take the UART Module Number and return it's base address
 *
*/

ul UART_Get_BASE(u8 Uart_Num)
{
    switch(Uart_Num)
    {
    case UART_0:  return UART0;
    case UART_1:  return UART1;
    case UART_2:  return UART2;
    case UART_3:  return UART3;
    case UART_4:  return UART4;
    case UART_5:  return UART5;
    default:      return 0;

    }
}


/*
 * Function_Name:Pin_Config_Uart
 * Function_Description:Set all the Configuration the pin need to use in UART function
 *
 * Parameters :
 * Port: Port number (PORTAE ,PORTBE,PORTCE,PORTDE,PORTEE)
 * Pin_num:Pin number (PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7)
 * current: Current strength  of the pin (Drive_2_mA,Drive_4_mA,Drive_8_mA)
 * U_Num : Uart_Number (UART_0,UART_1,....)
*/
void Pin_Uart_Config(u8 Port,u8 Pin_numRx,u8 Pin_numTx,u8 U_Num)
{

    /*1- Unlock the Pins */

    GET_REG(GPIO_Get_BASE(Port),GPIOLOCK) = Unlock_Code;       /*Unlock pin in case it is protected  */

    SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOCR),Pin_numRx);     /* Set the required pin in GPIOCR for Rx & Tx */
    SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOCR),Pin_numTx);

    /*2- Set the pin to use in Alternative function  (UART) */
    SETBIT(GET_REG(SYSTEM_CONTROL, GPIOAFSEL),Pin_numRx);
    SETBIT(GET_REG(SYSTEM_CONTROL, GPIOAFSEL),Pin_numTx);




    /*4- Set the pin to work for UART functionality */

    switch(Port)
    {
    case PORTAE:
    case PORTBE:
        {
            SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT0);
            SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT4);
            break;

        }
    case PORTCE:
        {
            if(Pin_numRx==PIN4&(U_Num==UART_4))
            {
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT16);
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT20);
            }
            else if(Pin_numRx==PIN6)
            {
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT24);
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT28);
            }
            else if((Pin_numRx==PIN4)&(U_Num==UART_1))
            {
                GET_REG(GPIO_Get_BASE(Port),GPIOPCTL) |=(2<<15);
                GET_REG(GPIO_Get_BASE(Port),GPIOPCTL) |=(2<<19);
            }
            break;

        }
    case PORTDE:
       {
            if(U_Num==UART_6)
            {
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT16);
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT20);

            }
            else if(U_Num==UART_2)
            {
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT24);
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT28);
            }

            break;

        }
    case PORTEE:
        {
            if(U_Num==UART_7)
            {
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT0);
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT4);

            }
            else if(U_Num==UART_5)
            {
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT16);
                SETBIT(GET_REG(GPIO_Get_BASE(Port),GPIOPCTL),BIT20);
            }
            break;
        }
    default: break;
    }

}
/*
 * Function_Name:UART_Enable_Clock
 * Function_Description:Enable clock to the UART module so we can use the module
 * Parameters:UART Number
*/
void UART_Enable_Clock(uint8_t U_Num)
{
    SETBIT(GET_REG(SYSTEM_CONTROL, RCGCUART),U_Num);
}

/*
 * Function_Name:UART_Config
 * Function_Description:Configuration of the UART
 * Parameters:UART_Config  :
 *  UART Number
 *  PinRx
 *  PinTx
 *  Port_Pins
 *  Baud_Rate
 *  Data_Length
 *  Stop_Bit
 *  Parity_Bit
*/
void UART_Config(struct UART_Config * U_Config)
{

   /* 1- Enable the UART module */
    UART_Enable_Clock(U_Config->U_Num);

    /*2- the clock to the appropriate GPIO module */
    GPIO_Port_Enable(U_Config->Port_Pins);


    /*3- Set Pin Configuration For UART*/
    Pin_Uart_Config(U_Config->Port_Pins,U_Config->PinRx,U_Config->PinTx,U_Config->U_Num);


    /*4- Disable UART To set the BOUD rate safely  */
    CLEARBIT(GET_REG(UART_Get_BASE(U_Config->U_Num),UARTCTL),BIT0);

    /*5- Set the UART Configuration (Baud rate ,Data Length ....) */
    float BRD = (float)F_CPU / (16 *(U_Config->Baud_Rate) );
    /*Set the integer part of the BOUD rate */
    GET_REG(UART_Get_BASE(U_Config->U_Num),UARTIBRD)=(int)BRD;

    /*Set the flaut part of the BOUD rate*/
    GET_REG(UART_Get_BASE(U_Config->U_Num),UARTFBRD)=(int)((BRD-(int)BRD) * 64 + 0.5);

    /* 6- Set BOUD clock source i will  use the source system and let it at the default state */


    /*7- Set the Parity bit & stop bit and the Data_Length */
    GET_REG(UART_Get_BASE(U_Config->U_Num),UARTLCRH) |=U_Config->Data_Length|U_Config->Parity_Bit|U_Config->Stop_Bit;


    /*8- Enable UART To set the Boud rate safely  */
    SETBIT(GET_REG(UART_Get_BASE(U_Config->U_Num),UARTCTL),BIT0);

}

/* Function Name: UART_Send_Char
*  Fucntion description: function that Transmits 1 byte
*
*/


void UART_Send_Char(const uint8_t Char)
{
    while( (BIT_IS_SET(UART0,UART_FR,TXFF)) != 0 ){}       /*staying in loop while the TXFF=1 and the FIFO is full*/
    ACCESS_REG(UART0,UART_DR) = data;
}

/* Function Name: UART_receiveByte
*  Fucntion description: function that returns the value(1 Byte) received from pc
*
*/
uint8 UART_receiveByte(void)
{
    while( (BIT_IS_SET(UART0,UART_FR,RXFE)) !=0 ){}       /*staying in loop while RXFF=1 and the FIFO is full*/

    return ( (uint8_t)(ACCESS_REG(UART0,UART_DR) & 0xFF ));   /*the receiver can receive data now*/
}

/* Function Name: UART_sendString
*  Fucntion description: Sends a string
*/
void UART_sendString(const uint8_t *Str)
{
    uint8 i = 0;
    while(Str[i] != '\0')
    {
        UART_sendByte(Str[i]);
        i++;
    }
    UART_sendByte('\r');
    UART_sendByte('\n');
}

/* Function Name: UART_receiveString
*  Fucntion description: Receives a string
*
*/
void UART_receiveString(uint8_t *Str)
{
    uint8 i = 0;
    Str[i] = UART_receiveByte();
    UART_sendByte(Str[i]);
    while(Str[i] != '\r')
    {
        i++;
        Str[i] = UART_receiveByte();
        UART_sendByte(Str[i]);

    }
    Str[i] = '\0';
    UART_sendByte('\n');
}


