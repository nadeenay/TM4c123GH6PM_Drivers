/*
 * Timer.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Nadeen
 */

#ifndef REPO_MCAL_GP_TIMERS_TIMER_H_
#define REPO_MCAL_GP_TIMERS_TIMER_H_

#include "../DIO/STD_Data_Types.h"
//------------------------------------------------->CPU FREQUANCY <-----------------------------------------------//
#define F_CPU  16000000000           /* 16 MHZ*/



//------------------------------------------------->Start value of the Timer <-----------------------------------------------//
#define TM_Start_Val  0x00F42400    /* the Start value of the timer and this value will make 1 second delay */

//-------------------------------------------------> STRUCT FOR TIMER CONFIG <-----------------------------------------------//
struct Timer_Config
{
  Timer_Num    T_Num;   /*Timer required */
  Count_State  C_Sate ; /*Count_Up ,Count_Down*/
  Timer_State  TM_State;/* Single or Concatenated */
  Timer_Mode   TM_Mode; /* Periodic ,one shoot,...*/
  Timer_Type   TM_Type; /* A or B*/
  Timer_Size   TM_Size; /*Normal or Wide*/
 ul TM_Start_Value;
};

ul GPTM_Get_Base(Timer_Num T_Num);

void GPTM_Enable_Clock_Timer(Timer_Num T,Timer_Size S);

void Timer_Module_Config(struct Timer_Config TM_Config,Interrupt_T_Type I_T);

void GPTM_Poll(struct Timer_Config TM_Config,Interrupt_T_Type I_T);


void GPTM_Enable_Interrupt(Timer_Num T,Interrupt_T_Type I_T);

#endif /* REPO_MCAL_GP_TIMERS_TIMER_H_ */
