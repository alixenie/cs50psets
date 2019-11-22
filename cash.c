#include <math.h>
#include <stdio.h>

int main(void) 
{
    float amount;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    do
    {
        printf("Amount: ");
        scanf("%f", &amount);
    }
    while (amount <= 0);
    float cents = round(amount * 100);    
    int coins;
    for (coins = 0; cents > 0; coins++) 
    {
        if (cents > 24) {
            cents = cents - quarter;
        }
        else if (cents > 9) {
            cents = cents - dime;
        } 
        else if (cents > 4)
        {
            cents = cents - nickel;
        }
        else 
        {
            cents = cents - penny;
        }
    }
    printf ("%i\n", coins);
}
