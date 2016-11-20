#include <stdio.h>
#include <cs50.h>

int GetIntWithinLimits(int lowerLimit, int upperLimit)
{
    int input = GetInt();
    if(input < lowerLimit || input > upperLimit)
    {
        printf("Retry: ");
        input = GetIntWithinLimits(lowerLimit,upperLimit);
    }
    return input;
}

int main(void)
{
    int layerLength = 0;
    
    printf("height: ");
    int height = GetIntWithinLimits(0,23);

    for(int i = 1; i <= height; i++ )
    {
        layerLength = height - (height-i);
        for(int j = height; j >= 0; j--)
        {
            if(j > layerLength)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    } 
}




/**

To draw the pyramid,

    Get the height (solved)
    
    loop to draw pyramid, using int i as iterative value (starting at 1)
    
        Draw each layer of pyramid. A loop will print this many "#", with each iteration of the loop checking to see if the number of "#" currently printed is equal to the value: (height - (height-i))

*/