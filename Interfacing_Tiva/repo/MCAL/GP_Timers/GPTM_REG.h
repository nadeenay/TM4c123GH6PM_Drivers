/*
 * GPTM_REG.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Nadeen
 */

#ifndef REPO_MCAL_GP_TIMERS_GPTM_REG_H_
#define REPO_MCAL_GP_TIMERS_GPTM_REG_H_
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------->Timers Registers's Base Address <-----------------------------------------//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define Timer_0_B  0x40030000
#define Timer_1_B  0x40031000
#define Timer_2_B  0x40032000
#define Timer_3_B  0x40033000
#define Timer_4_B  0x40034000
#define Timer_5_B  0x40035000
#define Wide_Timer_0  0x40036000
#define Wide_Timer_1  0x40037000
#define Wide_Timer_2  0x4004C000
#define Wide_Timer_3  0x4004D000
#define Wide Timer_4  0x4004E000
#define Wide Timer_5  0x4004F000


//----------------------------------------->END Timers Registers's Base Address <-----------------------------------------//


//----------------------------------------->System Control Base<-----------------------------------------//
#define SYSTEM_CONTROL  0x400FE000


//----------------------------------------->Enable timer register <-----------------------------------------//
/* General-Purpose Timer Run Mode Clock Gating Control */
#define RCGCTIMER       0x604

//-----------------------------------------> Registers's OFFSET <-----------------------------------------//


#define  GPTMCFG   0x000
#define  GPTMTAMR  0x004
#define  GPTMTBMR  0x008
#define  GPTMCTL   0x00C
#define  GPTMSYNC  0x010
#define  GPTMIMR   0x018
#define  GPTMRIS   0x01C
#define  GPTMMIS   0x020
#define  GPTMICR   0x024
#define  GPTMTAILR 0x028
#define  GPTMTBILR 0x02C
#define  GPTMTAMATCHR 0x030
#define  GPTMTBMATCHR 0x034
#define  GPTMTAPR  0x038
#define  GPTMTBPR  0x03C
#define  GPTMTAPMR 0x040
#define  GPTMTBPMR 0x044
#define  GPTMTAR   0x048
#define  GPTMTBR   0x04C
#define  GPTMTAV   0x050
#define  GPTMTBV   0x054
#define  GPTMRTCPD 0x058
#define  GPTMTAPS  0x05C
#define  GPTMTBPS  0x060
#define  GPTMTAPV  0x064
#define  GPTMTBPV  0x068
#define  GPTMPP    0xFC0

//-----------------------------------------> END Registers's OFFSET <-----------------------------------------//

#endif /* REPO_MCAL_GP_TIMERS_GPTM_REG_H_ */
