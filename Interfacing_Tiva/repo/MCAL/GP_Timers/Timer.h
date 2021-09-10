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
#define TM_Start_Val  0x00F42400

//-------------------------------------------------> STRUCT FOR TIMER CONFIG <-----------------------------------------------//
struct Timer_Config
{
 const Timer_Num    T_Num;   /*Timer required */
 const Count_State  C_Sate ; /*Count_Up ,Count_Down*/
 const Timer_State  TM_State;/* Single or Concatenated */
 const Timer_Mode   TM_Mode; /* Periodic ,one shoot,...*/
 const Timer_Type   TM_Type; /* A or B*/
 const Timer_Size   TM_Size; /*Normal or Wide*/
 ul TM_Start_Value;
};

const ul* GPTM_Get_Base(Timer_Num T_Num);

void GPTM_Enable_Clock_Timer(Timer_Num T,Timer_Size S);

void Timer_Module_Config(struct Timer_Config TM_Config);



#endif /* REPO_MCAL_GP_TIMERS_TIMER_H_ */
