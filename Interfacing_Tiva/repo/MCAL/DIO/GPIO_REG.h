

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
