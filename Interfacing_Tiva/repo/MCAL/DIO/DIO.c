
#include <repo/MCAL/DIO/Important_Mac.h>
#include "DIO_Types.h"
#include "GPIO_REG.h"
#include "DIO.h"
#include "STD_Data_Types.h"

/*
 * Function_Name:GPIO_Set_Current_Str
 * Function_Description:this function will take the current strength wanted (2_mA,4_mA,8_mA) and set the Drive control registers
*/
void GPIO_Set_Current_Str(Pin_Current Drive,ul BASE,u8 Pin_Num)
{
    switch(Drive)
    {
    case Drive_2_mA:  SETBIT(GET_REG(BASE,GPIODR2R),Pin_Num);break; /* The corresponding GPIO Pin_Num drive  2-mA  */
    case Drive_4_mA:  SETBIT(GET_REG(BASE,GPIODR4R),Pin_Num);break; /* The corresponding GPIO Pin_Num drive 4-mA  */
    case Drive_8_mA:  SETBIT(GET_REG(BASE,GPIODR8R),Pin_Num);break; /* The corresponding GPIO Pin_Num drive 8-mA  */
    default : break;
    }
}



/*
 * Function_Name:GPIO_Set_Pin_Functionality
 * Function_Description:this function will take Pin_Func (pull_up,pull_down,...) ,port and the pin,and set the pin Func
 *
*/
void GPIO_Set_Pin_Functionality(Pin_Func Func,ul BASE,u8 Pin_Num)
{
    switch(Func)
    {
    case PULL_UP:    SETBIT(GET_REG(BASE,GPIOPUR),Pin_Num);break;   /* The corresponding GPIO Pin_Num has PULL_UP resistor */
    case PULL_DOWN:  SETBIT(GET_REG(BASE,GPIOPDR),Pin_Num);break;   /* The corresponding GPIO Pin_Num has PULL_Down resistor*/
    case OPEN_DRAIN: SETBIT(GET_REG(BASE,GPIOODR),Pin_Num);break;   /* The corresponding GPIO Pin_Num has PULL_OpenDrain resistor */
    default :    return;
    }
}



/*
 * Function_Name:GPIO_Get_Base
 * Function_Description:this function will take the port number(0-->A,1-->B,..) and return it's base
*/
 ul GPIO_Get_BASE(unsigned int Port)
{
    switch(Port)
    {
    case PORTAE:  return (ul)(PORTA);
    case PORTBE:  return (ul)(PORTB);
    case PORTCE:  return (ul)(PORTC);
    case PORTDE:  return (ul)(PORTD);
    case PORTEE:  return (ul)(PORTE);
    case PORTFE:  return (ul)(PORTF);
    default:      return 0;
    }
}


/*
 * Function_Name:DIO_SetPinDirection
 * Function_Description:Set the direction of the pin
*/
void GPIO_SetPinDirection(ul BASE,u8 Pin_Num, PIN_DIR Direction)
{
        if(Pin_Num<=BIT31)
        {
            if(Direction==OUTPUT) /* If the pin will be output then Set this pin   */
            SETBIT(GET_REG(BASE,GPIODIR),Pin_Num);

            else                  /* If the pin will be input then Clear this pin */
            CLEARBIT(GET_REG(BASE,GPIODIR),Pin_Num);
        }
}

/*
 * Function_Name:DIO_SetPinValue
 * Function_Description:Set the Value of the pin
*/
void GPIO_SetPinValue(const ul BASE,u8 Pin_Num,PIN_VAL Pin_Value)
{
    if(Pin_Num<=BIT31)
    {
        if(Pin_Value==HIGH)
        SETBIT(GET_REG(BASE,GPIODATA),Pin_Num);
        else
        CLEARBIT(GET_REG(BASE,GPIODATA),Pin_Num);

    }

}


/*
 * Function_Name:DIO_SetPinValue
 * Function_Description:Set the Value of the pin
*/
u8 GPIO_GetPinValue(const ul BASE,u8 Pin_Num)
{
    u8 PIN_VALUE;
    if(Pin_Num<=BIT31)
    {
     PIN_VALUE=GETBIT(GET_REG(BASE,GPIODATA),Pin_Num);
     return PIN_VALUE;
    }
    return 0;
}


/*
 * Function_Name:DIO_SetPinValue
 * Function_Description:enable digital pins
*/
void GPIO_Digital_Pin_Enable(ul BASE,u8 Pin_Num) /* Base A,B,C,D,E OR F*/
{
    SETBIT(GET_REG(BASE,GPIODEN),Pin_Num);
}


/*
 * Function_Name:GPIO_Port_Enable
 * Function_Description:this function take the GPIO port (PORTAE,PORTBE,...ETC) and enable it
 *
*/
void GPIO_Port_Enable(u8 Port)
{
   SETBIT(GET_REG(SYSTEM_CONTROL,RCGCGPIO),Port);
}


/*
 * Function_Name:GPIO_Config
 * Function_Description: Set the configuration of specific pin as an GPIO
*/
void GPIO_Config(struct GPIO_Config C1)
{
   /* 1-Enable clock */
    GPIO_Port_Enable(C1.PORT);

    /*2- Unlocking the Pin in case that it is from GPIO pins with special consideration
     * Set the direction of the GPIO port pins by programming the GPIODIR register*/

    GET_REG(GPIO_Get_BASE(C1.PORT),GPIOLOCK) =0x4C4F434B;    /*Unlock pin in case it is protected  */
    SETBIT(GET_REG(GPIO_Get_BASE(C1.PORT),GPIOCR),C1.PIN);     /* Set the required pin in GPIOCR*/


    GPIO_SetPinDirection(GPIO_Get_BASE(C1.PORT),C1.PIN,C1.DIR);/*Set direction */

    /*3- Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin */
    /* clear the pins in GPIOAFSEL to use this pins as GPIO pins */

     CLEARBIT(GET_REG(GPIO_Get_BASE(C1.PORT),GPIOAFSEL),C1.PIN); /* Set GPIO PIN */



     //-------------------------------------------<>--------------------------------------//
     /*  There are also two registers, GPIOADCCTL and GPIODMACTL,
      * which can be used to program a GPIO pin as a ADC or DMA trigger, respectively.*/

     /*
      * SETBIT(GET_REG(GPIO_GET_BASE(C1.PORT),GPIOADCCTL),C1.PIN); program a GPIO pin as a ADC Trigger
      * SETBIT(GET_REG(GPIO_GET_BASE(C1.PORT),GPIODMACTL),C1.PIN); program a GPIO pin as a ADC Trigger
      * */
     //-------------------------------------------<>--------------------------------------//

     /* 4- Set the current strength */
     GPIO_Set_Current_Str(C1.C_strength,GPIO_Get_BASE(C1.PORT),C1.PIN);

     /*5- Program the pin to have either pull-up, pull-down, or open drain functionality .*/
     GPIO_Set_Pin_Functionality(C1.FUNC,GPIO_Get_BASE(C1.PORT),C1.PIN);


     /* 6- Digital Enable */
     GPIO_Digital_Pin_Enable(GPIO_Get_BASE(C1.PORT),C1.PIN); /* Enable Pin as digital */

    /* step 7,8 in configuration related to the interrupts */

}









