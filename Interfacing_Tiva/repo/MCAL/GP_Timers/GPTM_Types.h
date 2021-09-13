/*
 * GPTM_Types.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Nadeen
 */

#ifndef REPO_MCAL_GP_TIMERS_GPTM_TYPES_H_
#define REPO_MCAL_GP_TIMERS_GPTM_TYPES_H_

#define null (void*)0

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
typedef enum {
    Single=0x4,       /* use A or B as single Timer */
    Concatenated=0x0  /* use A and B as Timer */
}Timer_State;

//---------------------------------------------> Timer_Type <---------------------------------------------//
typedef enum {
    A,
    B,
    Both
}Timer_Type;

//---------------------------------------------> Timer_Size <---------------------------------------------//
typedef enum {
    Timer,
    Wide_Timer
}Timer_Size;

//--------------------------------------------->Timer  Mode <---------------------------------------------//
typedef enum{
 One_Shot=0x1,
 Periodic=0x2
}Timer_Mode;


//--------------------------------------------->Interrupt Type <---------------------------------------------//
typedef enum{
    Erro=16,
    Match_B=11,
    Capture_Mode_Event_B=10,
    Capture_Mode_Match_B=9,
    Time_Out_B=8,
    Match_A=4,
    RTC=3,
    Capture_Mode_Event_A=2,
    Capture_Mode_Match_A=1,
    Time_Out_A =0,
    Dis=5

}Interrupt_T_Type;






#endif /* REPO_MCAL_GP_TIMERS_GPTM_TYPES_H_ */
