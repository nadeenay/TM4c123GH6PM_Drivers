/*Includes for GPIO*/
#include "../MCAL/DIO/DIO_Types.h"
#include "../MCAL/DIO/DIO.h"


/*Includes for GPTM*/
#include "../MCAL/GP_Timers/GPTM_Types.h"
#include "../MCAL/GP_Timers/Timer.h"


void LED_Test(){

while(1)
{

struct GPIO_Config C1={PORTFE,BIT1,OUTPUT,Drive_2_mA,Def}; /*Set the port of the pin ,Dir,Current St,Function*/
struct GPIO_Config C2={PORTFE,BIT2,OUTPUT,Drive_2_mA,Def};
struct GPIO_Config C3={PORTFE,BIT3,OUTPUT,Drive_2_mA,Def};


/************************************** Configuration for Pins  *********************************************/
GPIO_Config(C1);
GPIO_Config(C2);
GPIO_Config(C3);


/************************************** Configuration for Timer  *********************************************/
/* use Timer_0
 * The timer Count down
 * The Timer is in Single Mode use A or B not both
 * The Timer is in Periodic Mode
 * Timer will start with 1500 and Count Down..
 */
struct Timer_Config T1={Timer_0,Count_Down,Single,Periodic,A,Timer,1500};



GPIO_SetPinValue(GPIO_Get_BASE(C1.PORT),C1.PIN,HIGH); /* the Red Led should illuminate */

GPTM_Poll(T1); /* delay */

GPIO_SetPinValue(GPIO_Get_BASE(C1.PORT),C1.PIN,LOW);  /* the Red Led should close */
GPIO_SetPinValue(GPIO_Get_BASE(C2.PORT),C2.PIN,HIGH); /* the blue Led should illuminate */

GPTM_Poll(T1); /* delay */

GPIO_SetPinValue(GPIO_Get_BASE(C2.PORT),C2.PIN,LOW);  /* the blue Led should close */
GPIO_SetPinValue(GPIO_Get_BASE(C3.PORT),C3.PIN,HIGH); /* the green Led should illuminate */

}

}




