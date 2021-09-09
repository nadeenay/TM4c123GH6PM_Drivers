
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
  typedef enum {
        BIT0,
        BIT1,
        BIT2,
        BIT3,
        BIT4,
        BIT5,
        BIT6,
        BIT7,
        BIT8,
        BIT9,
        BIT10,
        BIT11,
        BIT12,
        BIT13,
        BIT14,
        BIT15,
        BIT16,
        BIT17,
        BIT18,
        BIT19,
        BIT20,
        BIT21,
        BIT22,
        BIT23,
        BIT24,
        BIT25,
        BIT26,
        BIT27,
        BIT28,
        BIT29,
        BIT30,
        BIT31
    }BIT_NUM;


//------------------------------>Advanced Peripheral Bus (APB) BASE<------------------------------//
#define PORTA  0x40004000
#define PORTB  0x40005000
#define PORTC  0x40006000
#define PORTD  0x40007000
#define PORTE  0x40024000
#define PORTF  0x40025000

//------------------------------>PORTS ENABLE<------------------------------//
typedef enum {
 PORTAE  ,
 PORTBE  ,
 PORTCE  ,
 PORTDE  ,
 PORTEE  ,
 PORTFE
}PORT_E;


//------------------------------>STD Types<------------------------------//
typedef unsigned long ul;
typedef unsigned char u8;


//------------------------------>Select Drive <------------------------------//
typedef enum{
 Drive_2_mA,
 Drive_4_mA,
 Drive_8_mA
}Pin_Drive_C;


//------------------------------>PIN FUNCTIONALITY <------------------------------//
typedef enum{
  PULL_UP ,
  PULL_DOWN ,
  OPEN_DRAIN
}Pin_Func;


#endif /* REPO_MCAL_DIO_DIO_TYPES_H_ */
