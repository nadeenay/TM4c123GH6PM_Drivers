#include "../DIO/DIO_Types.h"
#include "../DIO/Important_Mac.h"
#include "GPTM_Types.h"
#include "GPTM_REG.h"
#include "Timer.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------->Public Functions <-----------------------------------------//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Function_Name:GPTM_Get_Base
 * Function_Description:this function will take the Timer number(0-->A,1-->B,..) and return it's base
*/

const ul* GPTM_Get_Base(Timer_Num T)
{
    switch(T)
    {
    case Timer_0:  return (ul*)Timer_0_B;
    case Timer_1:  return (ul*)Timer_1_B;
    case Timer_2:  return (ul*)Timer_2_B;
    case Timer_3:  return (ul*)Timer_3_B;
    case Timer_4:  return (ul*)Timer_4_B;
    case Timer_5:  return (ul*)Timer_5_B;
    default:      return null;

    }
}






/*
 * Function_Name:GPTM_Enable_Timer_Reg
 * Function_Description:this function to enable the timer module registers
 *
*/
/*Set bit 0--> enable timer 0, 1-->enable 1 ....*/
void GPTM_Enable_Timer_Reg(Timer_Num T)
{
    SETBIT(GET_REG(SYSTEM_CONTROL,RCGCTIMER),T);
}


/*
 * Function_Name:Timer_Module_Config
 * Function_Description:this function will  make the configuration of the timers
 *
*/
/*
 /* Configuration will be for the One shot or periodic mode */

void Timer_Module_Config(struct Timer_Config TM_Config)
{
    /* 1-Enable Timer required */
    GPTM_Enable_Timer_Reg(TM_Config.T_Num);


    /*2-Ensure disable the timer before any changes */
    CLEARBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),0);


    /*3-Select the Size of the timer */
    switch(TM_Config.TM_Mode)
    {
    case One_Shoot_Periodic:  GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCFG)= 0x00000000;break;
    case RTC:                 GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCFG)= 0x00000001;break;
    default :                 GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCFG)= 0x00000004;break; /* Others Modes */
    }

    /*4-
     * Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
        a. Write a value of 0x1 for One-Shot mode.
        b. Write a value of 0x2 for Periodic mode.
     */
    /* set periodic timer mode 0x10-->for periodic mode 1:0 bit in GPTMTAMR */
      GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR)=TM_Config.TM_Mode_TnMR;


    /*5-Set the timer count up or count down  */
    if(TM_Config.C_Sate==Count_Down)
    CLEARBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR),4);

    else if(TM_Config.C_Sate==Count_Up)
    SETBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR),4);


    /* 6- Set the initial value of the timer */
    GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAILR)=TM_Start_Val;


    /*7- If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register.*/


    /* 8- Enable the timer and start counting */
    SITBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),0);

    /*  End of configuration */

}


//----------------------------------------->END Public Functions <-----------------------------------------//
