#include "../DIO/Important_Mac.h"
#include "GPTM_Types.h"
#include "GPTM_REG.h"
#include "Timer.h"
#include "../DIO/STD_Data_Types.h"


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
void GPTM_Enable_Clock_Timer(Timer_Num T,Timer_Size S)
{
    if(S==Timer)             /* Not wide timer */
    SETBIT(GET_REG(SYSTEM_CONTROL,RCGCTIMER),T);

    else if(S==Wide_Timer)    /* wide timer */
    SETBIT(GET_REG(SYSTEM_CONTROL,RCGCWTIMER),T);
}


/*
 * Function_Name:Timer_Module_Config
 * Function_Description:this function will  make the configuration of the timers
 *
*/


 /* Configuration will be for the One shot or periodic mode */

void Timer_Module_Config(struct Timer_Config TM_Config)
{
      /* 1-Enable Clock for the timer required */
      GPTM_Enable_Clock_Timer(TM_Config.T_Num,TM_Config.TM_Size);

      if((TM_Config.TM_State==Single&&TM_Config.TM_Type==A)||TM_Config.TM_State==Concatenated) /*we will Configure GPTMTAMR */
      {

              /*2-Ensure disable the timer before any changes */
              CLEARBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),0); /*Disbale A*/



              /*3-Select the  size required for the timer */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCFG)=TM_Config.TM_State; /*Select 32 for 16/32-bit timer or 64 for wide timer (Concatenated Mode ) */
                                                                                  /*Select 16 for 16/32-bit timer or 32 for wide timer (Single Mode  ) */


              /*4-Set state of Counter (Count_Up or Down) and Timer Mode (one shot or periodic) */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR)|=(TM_Config.TM_Mode)|(TM_Config.C_Sate<<4);


              /* 5- Set the initial value of the timer */
              if(TM_Config.TM_State==Single)
              {
               /*in case we are in 16 timer mode the start value should be less than 0xFFFF*/
               // if(TM_Config.TM_Size==Timer&&TM_Config.TM_Start_Value<=0xFFFF)
                GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAILR)=TM_Config.TM_Start_Value;
               /* else
                 #warning Error in setting the Timer_start value
                 */
              }
              else if(TM_Config.TM_State==Concatenated)
              {    /*Lower bits in GPTMTAILR */
                  GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAILR)=TM_Config.TM_Start_Value;

                   /*Lower bits in GPTMTBILR */
                  GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTBILR)=(TM_Config.TM_Start_Value>>32);

              }

              /*6- If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register.*/

              /* 7- Enable the timer and start counting */
                 SITBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),0);

      }
      else if(TM_Config.TM_Type==B)      /*we will Configure GPTMTBMR*/
      {

              /*2-Ensure disable the timer before any changes */
              CLEARBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),8); /*Disbale B*/


              /*3-Select the  size required for the timer */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCFG)=TM_Config.TM_State;  /*Select 32 for 16/32-bit timer or 64 for wide timer (Concatenated Mode ) */
                                                                                   /*Select 16 for 16/32-bit timer or 32 for wide timer (Single Mode) */
              /*4-Set state of Counter (Count_Up or Down) and Timer Mode (one shot or periodic) */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTBMR)|=(TM_Config.TM_Mode)|(TM_Config.C_Sate<<4);

              /* 5- Set the initial value of the timer */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAILR)=TM_Config.TM_Start_Value;

              /*6- If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register.*/


              /* 7- Enable the timer and start counting */
                 SITBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),8);

      }


}

//----------------------------------------->END Public Functions <-----------------------------------------//
