#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("minutes: ");
    
    int minutes = GetInt();
    
    int bottles = minutes * 12; //the average shower uses 12 bottles worth of water a minute, or 192 ounces.
    
    printf("bottles: %i\n", bottles);
}