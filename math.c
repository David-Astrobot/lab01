/*This program does some arithmatic operation
Author:Jannatun Naher*/

#include <msp430.h> 
#include <math.h>

int cal_add (int a, int b);
int cal_sub (int a, int b);
int cal_mult (int a, int b);
float cal_div (int a, int b);

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    int num1, num2;   // Declare two integer variables 'num1' and 'num2'.
    int sum, sub, mult, mod, power;   // Declare variables to store the results of arithmetic operations.
    float div;   // Declare a float variable 'div' to store the result of division.

    num1=10;
    num2=5;

    sum = cal_add (num1,num2);
    sub = cal_sub (num1,num2);
    mult = cal_mult (num1,num2);
    div = cal_div (num1,num2);

    //Performs all arithmetic operations
    //sum = num1 + num2;   // Calculate the sum of 'num1' and 'num2'.
    //sub = num1 - num2;   // Calculate the difference between 'num1' and 'num2'.
    //mult = num1 * num2;  // Calculate the product of 'num1' and 'num2'.
    //div = (float)num1 / num2;   // Calculate the division of 'num1' by 'num2' and cast the result to a float.
    mod = num1 % num2;   // Calculate the modulus of 'num1' and 'num2'.
    power = pow(num1,num2); //// Calculate power of 'num1' is 'num2'.
    //power = num1*num1*num1*num1*num1;
    while(1);

    return 0;   // Return 0 to indicate successful execution of the program.

    }

int cal_add (int a, int b)
{
    int result_add;
    result_add = a+b;
    return result_add;
}

int cal_sub (int a, int b)
{
    int result_sub;
    result_sub = a-b;
    return result_sub;
}

int cal_mult (int a, int b)
{
    int result_mult;
    result_mult = a*b;
    return result_mult;
}

float cal_div (int a, int b)
{
    float result_div;
    result_div = (float) a/b;
    return result_div;
}
