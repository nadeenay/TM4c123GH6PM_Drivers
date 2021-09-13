/*Includes for GPIO*/
#include "../MCAL/DIO/DIO_Types.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/Important_Mac.h"


/*Includes for GPTM*/
#include "../MCAL/GP_Timers/GPTM_Types.h"
#include "../MCAL/GP_Timers/Timer.h"
#include "../MCAL/GP_Timers/GPTM_REG.h"

/*Includes for Interrupts*/
#include "../MCAL/DIO/Interrupt_Types.h"
#include "../MCAL/DIO/Interrupt.h"


void Interrupt_Test(){



struct GPIO_Config LED1={PORTFE,BIT1,OUTPUT,Drive_2_mA,Def};    /*Set the port of the pin ,Dir,Current St,Function*/
struct GPIO_Config SW1={PORTFE,BIT4,INPUT,Drive_2_mA,PULL_UP};  /*Set the configuration of Switch 1*/



/************************************** Configuration for Pins  *********************************************/
GPIO_Config(LED1);
GPIO_Config(SW1);

/************************************** Configuration for Interrupt at pin F4 (SW1)  *********************************************/

struct Interrupt_config INT1={PORTF,BIT4,Edge,Low_L,One_Edge}; /*Set the Interrupt in Pin4 in Port F to Sense at the falling Edge*/

INT_Config(INT1,30);

GPIO_SetPinValue(GPIO_Get_BASE(PORTFE),BIT1,HIGH);  /* the Red Led should illuminate */

while(1)
{
 // Loop waiting for an interrupt
}


}




