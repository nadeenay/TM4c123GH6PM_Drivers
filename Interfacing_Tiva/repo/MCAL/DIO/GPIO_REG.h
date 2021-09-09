

#ifndef REPO_MCAL_DIO_GPIO_REG_H_
#define REPO_MCAL_DIO_GPIO_REG_H_
//------------------------------->REGISTERS NEEDED FOR CONFIG OFFSET <------------------------------//

/* General-Purpose Input/Output Run Mode Clock Gating Control OFFSET */
#define RCGCGPIO  0x608

/* General-Purpose Input/Output Run Mode Clock Gating Control BASE */
#define SYSTEM_CONTROL 0x400FE000

//------------------------------->GPIO REGISTERS OFFSET <------------------------------//

#define GPIODATA  0x000

/* GPIO DIRECTION 0-->INPUT 1-->OUTPUT */
#define GPIODIR   0x400

/*
 * 0--> The edge on the corresponding pin is detected (edge-sensitive).
 * 1-->The level on the corresponding pin is detected (level-sensitive).
 */
/* GPIO Interrupt Sense */
#define GPIOIS    0x404


/*
 *0-->Interrupt generation is controlled by the GPIO Interrupt Event
 *(GPIOIEV) register (see page 666).
 *
 *1-->Both edges on the corresponding pin trigger an interrupt in case you have set GPIOIS
 */
/* GPIO Interrupt Both Edges */
#define GPIOIBE   0x408


/*0--> A falling edge or a Low level on the corresponding pin triggers an interrupt.
 *1--> A rising edge or a High level on the corresponding pin triggers an interrupt.
 */
/* GPIO Interrupt Event */
#define GPIOIEV   0x40C


/*0--> The interrupt from the corresponding pin is masked.
 *1--> The interrupt from the corresponding pin is sent to the interrupt controller.
 */
/* GPIO Interrupt Mask */
#define GPIOIM    0x410


/*0-->An interrupt condition has not occurred on the corresponding pin.
 *1--> An interrupt condition has occurred on the corresponding pin.
 */
/* GPIO Raw Interrupt Status */
#define GPIORIS   0x414

/*0--> An interrupt condition on the corresponding pin is masked or has not occurred.
 *1-->An interrupt condition on the corresponding pin has triggered an interrupt to the interrupt controller
 */
/* GPIO Masked Interrupt Status */
#define GPIOMIS   0x418


/*
0-->The corresponding interrupt is unaffected.
1--> The corresponding interrupt is cleared.
*/
/* GPIO Interrupt Clear */
#define GPIOICR   0x41C


/*
0-->The associated pin functions as a peripheral signal and is controlled by the GPIO registers
1-->controlled by the alternate hardware function
*/
/*GPIO Alternate Function Select*/
#define GPIOAFSEL 0x420

/*
0--> The drive for the corresponding GPIO pin is controlled by the GPIODR4R or GPIODR8R register.
1--> The corresponding GPIO pin has 2-mA drive.
*/
/* GPIO 2-mA Drive Select */
#define GPIODR2R  0x500

/*
0--> The drive for the corresponding GPIO pin is controlled by the GPIODR2R or GPIODR8R register.
1--> The corresponding GPIO pin has 4-mA drive.
*/
/* GPIO 4-mA Drive Select */
#define GPIODR4R  0x504

/*
0--> The drive for the corresponding GPIO pin is controlled by the GPIODR4R or GPIODR2R register.
1--> The corresponding GPIO pin has 8-mA drive.
*/
/* GPIO 8-mA Drive Select */
#define GPIODR8R  0x508

/* GPIO Open Drain Select */
#define GPIOODR   0x50C

/* GPIO Pull-Up Select */
#define GPIOPUR   0x510

/* GPIO Pull-Down Select */
#define GPIOPDR   0x514


/*
0-->The digital functions for the corresponding pin are disabled.
1-->The digital functions for the corresponding pin are enabled.
*/
/*  GPIO Digital Enable */
#define GPIODEN   0x51C


/*
0x1--> The GPIOCR register is locked and may not be modified.
0x0--> The GPIOCR register is unlocked and may be modified.
*/
/* GPIO Lock */
#define GPIOLOCK 0x520



#define GPIOCR 0x524

/*
0--> The corresponding pin is not used to trigger the ADC.
1--> The corresponding pin is used to trigger the ADC.
*/
/*  GPIO ADC Control */
#define GPIOADCCTL 0x530


/*
0-->The corresponding pin is not used to trigger the DMA.
1-->The corresponding pin is used to trigger the DMA.
*/
/*  GPIO DMA Control */
#define GPIODMACTL 0x534




#endif /* REPO_MCAL_DIO_GPIO_REG_H_ */
