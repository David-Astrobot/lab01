#include <msp430.h>
#define RED_LED BIT0 //P1.0
#define GREEN_LED BIT6 //P6.6
#define BUTTON1 BIT1 //push button P4.1 (1 in position 1 of the 8 bit value) (these are just numbers that we later use for xor)
#define BUTTON2 BIT3 //push button P2.3 (1 in position 3 of the 8 bit value) (these are just numbers that we later use for xor)



void main(void)
{
WDTCTL = WDTPW | WDTHOLD;
P1OUT &= ~BIT0;  //p1.0 red led     //turn of red led, &~BITn always generates a zero at position n eg. position 0 in p1
P6OUT &= ~BIT6; //p6.6 green led    //turn of green led, &~BITn always generates a zero at position n eg. position 6 in p1
P1DIR |= BIT0;  //set output mode (0 = input mode, 1 = output mode)
P6DIR |= BIT6;  //set output mode (0 = input mode, 1 = output mode)


P4DIR &= ~BIT1;//clear P4.1(s1)
P4REN |= BIT1;//Enable pull up/down resistor
P4OUT |= BIT1;//Make resistor a pull up (assumes you are not pressing the button, if it can't figure out whether you are pressing the button or not.)

P2DIR &= ~BIT3;//clear P2.3(s2)
P2REN |= BIT3;//Enable pull up/down resistor
P2OUT |= BIT3;//Make resistor a pull up (assumes you are not pressing the button, if it can't figure out whether you are pressing the button or not.)



PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                        // to activate previously configured port settings
                                        // AKA allow the LED to turn on, give it enough power
int count = 0;
while(1){
        if((P4IN & BUTTON1) == 0x00){
        _delay_cycles(5000); // button must be pressed for some time.
        if((P4IN & BUTTON1) == 0x00){
            P1OUT ^= RED_LED; //switch state
//            if ((P1OUT&RED_LED) == 0x00) {
//            _delay_cycles(100000);
//            P1OUT ^= RED_LED;
//            _delay_cycles(100000);
//            P1OUT ^= RED_LED;
//            P6OUT ^= GREEN_LED;
//            }
            }
        while((P4IN & BUTTON1) == 0x00); // wait for change in state AKA this quantity isn't going to be equal to 0 once you press the button again.
        }

       else if((P2IN & BUTTON2) == 0x00){
         _delay_cycles(5000);  // button must be pressed for some time.
        if((P2IN & BUTTON2) == 0x00){
            P6OUT ^= GREEN_LED; //switch state
            }
        while((P2IN & BUTTON2) == 0x00); // wait for change in state AKA this quantity isn't going to be equal to 0 once you press the button again.
       }

}
//return 0;
}
