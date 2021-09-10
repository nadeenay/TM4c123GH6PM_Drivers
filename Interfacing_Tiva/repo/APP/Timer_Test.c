/*
 * Timer_Test.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Nadeen
 */

#include "../MCAL/GP_Timers/GPTM_Types.h"
#include "../MCAL/GP_Timers/Timer.h"
/*to make any Config for the timer
 1-make a struct
 2-choose
   T_Num;   Timer_0,Timer_1...
   C_Sate ; Count_Up ,Count_Down
   TM_Mode; One_Shoot_Periodic, RTC,Input_Edge_Count,Input_Edge_Time,PWM
   TM_Size;  TM_32-->32 for Timer and 64 for wide ,TM_RTC-->32 for Timer and 64 for wide,TM_16-->16 for Timer and 32 for wide
   TM_Mode_TnMR;
 */
void TM_Test()
{


   // struct Timer_Config T1={Timer_0,Count_Up,Periodic,TM_16};

   // Timer_Module_Config(T1);






}


