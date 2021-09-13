

#include "repo/APP/LED.h"
#include "repo/APP/Interrupt_Test.h"

int main(void)
{
    // LED_Test();       /* Uncomment this line to test the GPIO and Timers */

    Interrupt_Test();  /* Uncomment this line to test the GPIO Interrupts */

	return 0;
}

