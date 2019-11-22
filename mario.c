#include <stdio.h>

int main(void)
{
    int height;
    do 
    {
        printf("Height: ");
        scanf("%i", &height);
    }
    while (height < 1 || height > 8);
    for (int i = 0; i < height; i++)
    {
        for (int k = height; k > i + 1; k--) 
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) 
        {
            printf("#");
        }
        printf("\n");
    }
} 


