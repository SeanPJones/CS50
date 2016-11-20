#include <stdio.h>
#include <cs50.h>
#include <math.h> 

//write a method that take input, then runs through and repeatedly modulos by 25, adding 1 to the "quarters" value each time. once modulo returns the same value as the previous thing, move on to next denomination
//write a method that converts a float (in dollars) to integer (pennies) by taking input and multiplying by 100 then converting it to integer then returning the value

int ConvertToPennies(float dollars)
{
    float floatPennies = dollars * 100.0;
    int intPennies = (int)roundf(floatPennies);
    return intPennies;
}

float GetFloatWithinLimits(float lowerLimit, float upperLimit)
{
    float input = GetFloat();
    if(input < lowerLimit || input > upperLimit)
    {
        printf("Retry: ");
        input = GetFloatWithinLimits(lowerLimit,upperLimit);
    }
    return input;
}

int main(void)
{
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    float dollars = 0.0;
    
    printf("How much change is owed?\n");
    dollars = GetFloatWithinLimits(0.0, INFINITY);
    
    int amount = ConvertToPennies(dollars);
    while(amount != 0)
    {
        if(amount >= 25)
        {
            quarters += 1;
            amount -= 25;
        }
        else if(amount >= 10)
        {
            dimes += 1;
            amount -= 10;
        }
        else if(amount >= 5)
        {
            nickels += 1;
            amount -= 5;
        }
        else if(amount >= 1)
        {
            pennies += 1;
            amount -= 1;
        }
        else
        {
            amount = 0;
        }
    }
    
    printf("%i\n",quarters + dimes + nickels + pennies);
    
   
}