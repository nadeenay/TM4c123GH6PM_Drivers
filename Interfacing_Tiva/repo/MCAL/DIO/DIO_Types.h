
#ifndef REPO_MCAL_DIO_DIO_TYPES_H_
#define REPO_MCAL_DIO_DIO_TYPES_H_

#define null (void*)0

/* Pin Direction */
 typedef enum {
     INPUT ,
     OUTPUT
 }PIN_DIR;

 /* Pin Value*/
 typedef enum {
      LOW ,
      HIGH
  }PIN_VAL;

  /* Bits */

#define        BIT0    0
#define        BIT1    1
#define        BIT2    2
#define        BIT3    3
#define        BIT4    4
#define        BIT5    5
#define        BIT6    6
#define        BIT7    7
#define        BIT8    8
#define        BIT9    9
#define        BIT10   10
#define        BIT11   11
#define        BIT12   12
#define        BIT13   13
#define        BIT14   14
#define        BIT15   15
#define        BIT16   16
#define        BIT17   17
#define        BIT18   18
#define        BIT19   19
#define        BIT20   20
#define        BIT21   21
#define        BIT22   22
#define        BIT23   23
#define        BIT24   24
#define        BIT25   25
#define        BIT26   26
#define        BIT27   27
#define        BIT28   28
#define        BIT29   29
#define        BIT30   30
#define        BIT31   31



//------------------------------>Advanced Peripheral Bus (APB) BASE<------------------------------//
#define PORTA  0x40004000
#define PORTB  0x40005000
#define PORTC  0x40006000
#define PORTD  0x40007000
#define PORTE  0x40024000
#define PORTF  0x40025000

//------------------------------>PORTS ENABLE<------------------------------//

#define PORTAE  0
#define PORTBE  1
#define PORTCE  2
#define PORTDE  3
#define PORTEE  4
#define PORTFE  5

//------------------------------>Select Drive <------------------------------//
typedef enum{
 Drive_2_mA,
 Drive_4_mA,
 Drive_8_mA
}Pin_Current;


//------------------------------>PIN FUNCTIONALITY <------------------------------//
typedef enum{
  PULL_UP ,
  PULL_DOWN ,
  OPEN_DRAIN,
  Def
}Pin_Func;


#endif /* REPO_MCAL_DIO_DIO_TYPES_H_ */
