#include <msp430.h>
#include "GPIO_Driver.h"

void gpioInitIn(unsigned int Port, unsigned char Pin){ //Input Initialization

    if ( Port ==1)

    {   P1DIR &= ~Pin;  // Set GPIO_PIN as input (0)
        P1REN |= Pin;   // Enable pull-up/pull-down resistor
        P1OUT |= Pin;   // Set as output
    }

    else if ( Port ==2)

    {   P2DIR &= ~Pin;  // Set GPIO_PIN as input (0)
        P2REN |= Pin;   // Enable pull-up/pull-down resistor
        P2OUT |= Pin;   // Set as output
    }

    else if ( Port ==4)

        {   P4DIR &= ~Pin;  // Set GPIO_PIN as input (0)
            P4REN |= Pin;   // Enable pull-up/pull-down resistor
            P4OUT |= Pin;   // Set as output
        }


    else if ( Port ==6)

    {  P6DIR &= ~Pin;  // Set GPIO_PIN as input (0)
        P6REN |= Pin;   // Enable pull-up/pull-down resistor
        P6OUT |= Pin;   // Set as output
    }
}

void gpioInitOut(unsigned int Port, unsigned char Pin){ //output initialization
    if ( Port ==1)

        {   P1DIR |= Pin;  // Set GPIO_PIN as input (0)
            P1OUT &= ~ Pin;   // Set as input
        }

        else if ( Port ==2)

        {   P2DIR |= Pin;  // Set GPIO_PIN as input (0)
            P2OUT &= ~ Pin;   // Set as input
        }

        else if ( Port ==4)

        {   P4DIR |= Pin;  // Set GPIO_PIN as input (0)
            P4OUT &= ~ Pin;   // Set as input
        }


        else if ( Port ==6)

        {  P6DIR |= Pin;  // Set GPIO_PIN as input (0)
           P6OUT &= ~ Pin;   // Set as input
        }
}

void gpioWrite(unsigned int Port, unsigned char Pin, unsigned char value) {


    if ( Port ==1)

            {    if (value == 1) {
                    P1OUT |= Pin;  // Write value in P1OUT to see output as 1
                }

                else if (value == 0) {
                    P1OUT &=~ Pin;  // Write value in P1OUT to see output as 0
               }
            }

    else if ( Port ==2)

    {    if (value == 1) {
                        P2OUT |= Pin;  // Write value in P1OUT to see output as 1
                    }

                    else if (value == 0) {
                        P2OUT &=~ Pin;  // Write value in P1OUT to see output as 0
                   }
                }
    else if ( Port ==4)

    {    if (value == 1) {
                        P4OUT |= Pin;  // Write value in P1OUT to see output as 1
                    }

                    else if (value == 0) {
                        P4OUT &=~ Pin;  // Write value in P1OUT to see output as 0
                   }
                }


    else if ( Port ==6)

    {    if (value == 1) {
                        P6OUT |= Pin;  // Write value in P1OUT to see output as 1
                    }

                    else if (value == 0) {
                        P6OUT &=~ Pin;  // Write value in P1OUT to see output as 0
                   }
                }
}


unsigned char gpioInitStatus(unsigned int Port, unsigned char Pin) {
    if (Port == 1) {
        return P1IN & Pin;
    }
    if (Port == 2) {
            return P2IN & Pin;
        }
    if (Port == 3) {
            return P3IN & Pin;
        }
    if (Port == 4) {
            return P4IN & Pin;
        }
    if (Port == 5) {
            return P5IN & Pin;
        }
    if (Port == 6) {
            return P6IN & Pin;
        }
    return 0;
}




