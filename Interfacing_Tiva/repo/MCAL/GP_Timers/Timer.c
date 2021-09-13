#include "../DIO/Important_Mac.h"
#include "GPTM_Types.h"
#include "GPTM_REG.h"
#include "Timer.h"
#include "../DIO/STD_Data_Types.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------->Public Functions <-----------------------------------------//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Function_Name:GPTM_Enable_Interrupt
 * Function_Description:this function will Enable Interrupt
*/
void GPTM_Enable_Interrupt(Timer_Num T,Interrupt_T_Type I_T)
{
    SETBIT(GET_REG(GPTM_Get_Base(T),GPTMIMR),I_T);
}


/*
 * Function_Name:GPTM_Get_Base
 * Function_Description:this function will take the Timer number(0-->A,1-->B,..) and return it's base
*/

ul GPTM_Get_Base(Timer_Num T)
{
    switch(T)
    {
    case Timer_0:  return (ul)Timer_0_B;
    case Timer_1:  return (ul)Timer_1_B;
    case Timer_2:  return (ul)Timer_2_B;
    case Timer_3:  return (ul)Timer_3_B;
    case Timer_4:  return (ul)Timer_4_B;
    case Timer_5:  return (ul)Timer_5_B;
    default:      return 0;

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

void Timer_Module_Config(struct Timer_Config TM_Config,Interrupt_T_Type I_T)
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


              /*4-Set state of Counter (Count_Down) and Timer Mode (Periodic or one shot) */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR)|=(TM_Config.TM_Mode);

              /* Set state of Counter (Count_Down or UP) */
             if(TM_Config.C_Sate==Count_Down)
              CLEARBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR),4);
             else if(TM_Config.C_Sate==Count_Up)
              SETBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR),4);



              /* 5- Set the initial value of the timer */
              if(TM_Config.TM_State==Single||(TM_Config.TM_State==Concatenated&&TM_Config.TM_Size==Timer))
              {
               /*in case we are in 16 timer mode the start value should be less than 0xFFFF*/
                GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAILR)=TM_Config.TM_Start_Value;

              }
              else if(TM_Config.TM_State==Concatenated) /* In the timer is Concatenated and wide */
              {
                  /*Lower bits in GPTMTAILR */
                  GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAILR)=TM_Config.TM_Start_Value;

                   /*Lower bits in GPTMTBILR */
                  GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTBILR)=(TM_Config.TM_Start_Value>>32);

              }

              /*6- If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register.*/
              if(I_T!=Dis)
              GPTM_Enable_Interrupt( TM_Config.T_Num, I_T);

              /* 7- Enable the timer and start counting */
              SETBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),0);

      }
      else if(TM_Config.TM_Type==B)      /*we will Configure GPTMTBMR*/
      {

              /*2-Ensure disable the timer before any changes */
              CLEARBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),8); /*Disbale B*/


              /*3-Select the  size required for the timer */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCFG)=TM_Config.TM_State;  /*Select 32 for 16/32-bit timer or 64 for wide timer (Concatenated Mode ) */
                                                                                   /*Select 16 for 16/32-bit timer or 32 for wide timer (Single Mode) */
              /*4-Set state of Counter (Count_Up or Down) and Timer Mode (one shot or periodic) */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTBMR)|=(TM_Config.TM_Mode);

              /* Set state of Counter (Count_Down or UP) */
              if(TM_Config.C_Sate==Count_Down)
              CLEARBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR),4);
              else if(TM_Config.C_Sate==Count_Up)
              SETBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAMR),4);


              /* 5- Set the initial value of the timer */
              GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMTAILR)=TM_Config.TM_Start_Value;

              /*6- If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register.*/


              /* 7- Enable the timer and start counting */
               SETBIT(GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMCTL),8);

      }


}

/*
 * Function_Name:GPTM_Poll
 * Function_Description:Poll until the RIS flag set
 *
*/


void GPTM_Poll(struct Timer_Config TM_Config,Interrupt_T_Type I_T)
{
    while(1)
        {
         if((TM_Config.TM_State==Single&&TM_Config.TM_Type==A)||TM_Config.TM_State==Concatenated) /* we will Configure GPTMTAMR */
          {
        if((GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMRIS)& 0x00000001)==1)
          {
           GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMICR)  |=(1<<0);
           break;
          }

          }

          else if(TM_Config.TM_Type==B)    /*  we will Configure GPTMTBMR */
          {
            if(((GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMRIS)>>8)& 0x00000001)==1)
           {
           GET_REG(GPTM_Get_Base(TM_Config.T_Num),GPTMICR)  |=(1<<0);
           break;
           }
          }

}
}



//----------------------------------------->END Public Functions <-----------------------------------------//
