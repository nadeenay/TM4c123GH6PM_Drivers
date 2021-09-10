
#ifndef REPO_MCAL_DIO_IMPORTANT_MAC_H_
#define REPO_MCAL_DIO_IMPORTANT_MAC_H_

/* Set a specific bit in any specific register */
#define SETBIT(Reg,Pin_Num)     (Reg) |=(1<<(Pin_Num))

/* Get a specific bit in any specific register */
#define GETBIT(Reg,Pin_Num)     (((Reg) >> (Pin_Num)) & 0x01) //0 or 1

/* Clear a specific bit in any specific register */
#define CLEARBIT(Reg,Pin_Num)   (Reg)&=~(1<<(Pin_Num))

/* Toggel a specific bit in any specific register */
#define TOGGLEBIT(Reg,Pin_Num)  (Reg)^=(1<<(Pin_Num))

/* Get any register with  it's specific address */
#define GET_REG(BASE,OFFSET)  (*((volatile unsigned long *)(BASE+OFFSET)))





#endif /* REPO_MCAL_DIO_IMPORTANT_MAC_H_ */
