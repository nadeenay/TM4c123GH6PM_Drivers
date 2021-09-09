#include "../MCAL/DIO/DIO_Types.h"
#include "../MCAL/DIO/DIO.h"

void LED_Test(){

struct GPIO_Config C1={PORTFE,BIT1,OUTPUT,Drive_2_mA,PULL_UP};

/************************************** Configuration *********************************************/
GPIO_Config(C1);

GPIO_SetPinValue(GPIO_Get_Base(C1.PORT),C1.PIN,HIGH); //the Red Led should illuminate


}




