
#ifndef REPO_MCAL_DIO_INTERRUPT_TYPES_H_
#define REPO_MCAL_DIO_INTERRUPT_TYPES_H_


typedef enum{
    Edge,
    Level

}Interrupt_Type;


typedef enum{
    Low_L,
    High_L

}Level_O_Edge__Type;


typedef enum{
    One_Edge,        /*Control by the GPIOIEV rising edge or falling edge*/
    Both_Edges

}Edge_Num;



/* Interrupt Enable (Masked or not) */
#define Interrupt_Port_Enable   0xFF
#define Interrupt_Port_Disable  0x00


#endif /* REPO_MCAL_DIO_INTERRUPT_TYPES_H_ */
