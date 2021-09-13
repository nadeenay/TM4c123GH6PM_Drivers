

#define NVIC 0xE000E000    /* nested vector interrupt controller */


#define  EN0 0x100 /*Interrupt 0-31 Set Enable  */
#define  EN1 0x104 /*Interrupt 32-63 Set Enable */
#define  EN2 0x108 /*Interrupt 64-95 Set Enable */
#define  EN3 0x10C /*Interrupt 96-127 Set Enable*/
#define  EN4 0x110 /*Interrupt 128-138Set Enable*/
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





