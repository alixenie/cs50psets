#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void ciphertext(char *text, int key);
int main(int argc, char *argv[])
{
    // check if we have 2 command line arguments
    if (argc != 2) 
    {
        printf("Usage: ./ceasar key \n");
        return 1;
    }
    else 
        // check if the second command line argument is a number
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (! isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //turn the string into an integer
        int cnumber = atoi(argv[1]);        
        //cipher time
        printf("Plaintext: ");
        char plaintext[256];
        scanf("%s", plaintext);
        ciphertext(plaintext, cnumber);
        return 0;
    }
}
void ciphertext(char *text, int key)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i])) 
            {
                text[i] = ((text[i] - 65/*big a in ASCII*/) + key) % 26 + 65/*big a in ASCII*/;
            }
            else 
            {
                text[i] = ((text[i] - 97/*small a in ASCII*/) + key) % 26 + 97/*small a in ASCII*/;
            }
        }
    }
    printf("ciphertext: %s\n", text);
}
