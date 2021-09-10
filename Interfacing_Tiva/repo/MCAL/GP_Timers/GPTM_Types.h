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
    Single=0x0,       /* use A or B as single Timer */
    Concatenated=0x4  /* use A and B as Timer */
}Timer_State;

//---------------------------------------------> Timer_Type <---------------------------------------------//
typedef enum {
    A,
    B
}Timer_Type;

//---------------------------------------------> Timer_Size <---------------------------------------------//
typedef enum {
    Timer,
    Wide_Timer
}Timer_Size;

//--------------------------------------------->Timer  Mode <---------------------------------------------
typedef enum{
 One_Shot=0x01,
 Periodic=0x2
}Timer_Mode;







#endif /* REPO_MCAL_GP_TIMERS_GPTM_TYPES_H_ */
