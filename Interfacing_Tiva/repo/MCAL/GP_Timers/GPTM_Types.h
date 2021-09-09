/*
 * GPTM_Types.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Nadeen
 */

#ifndef REPO_MCAL_GP_TIMERS_GPTM_TYPES_H_
#define REPO_MCAL_GP_TIMERS_GPTM_TYPES_H_
//--------------------------------------------->Timer_Num<---------------------------------------------//
typedef enum{
    Timer_0,
    Timer_1,
    Timer_2,
    Timer_3,
    Timer_4,
    Timer_5
}Timer_Num;

//--------------------------------------------->Count State <---------------------------------------------//
typedef enum{
    Count_Up,
    Count_Down
}Count_State;

//---------------------------------------------> Timer Mode pit in GPTM_TnMR depend on the Mode of the Timer <---------------------------------------------//
typedef enum{
  Reserved,
  One_Shoot,
  Periodic,
  Capture       /* In case the timer is in Input Edge Mode (Edge_count,Edge_Time) */
}Timer_Mode_TnMR;

//--------------------------------------------->Timer  Mode <---------------------------------------------
typedef enum{
  One_Shoot_Periodic,
  RTC,
  Input_Edge_Count,      /* In case the timer is in Input Edge Mode (Edge_count,Edge_Time) */
  Input_Edge_Time,
  PWM
}Timer_Mode;


//--------------------------------------------->Timer Size <---------------------------------------------//
typedef enum{
    TM_32=0,   /* 32 for Timer and 64 for wide */
    TM_RTC=1,  /* 32 for Timer and 64 for wide */
    TM_16=4    /* 16 for Timer and 32 for wide */
}Timer_Size;




#endif /* REPO_MCAL_GP_TIMERS_GPTM_TYPES_H_ */
