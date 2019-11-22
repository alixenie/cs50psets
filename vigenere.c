#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);
void ciphertext(char *plaintext, char *keyword);

int main(int argc, char *argv[])
{
    char *keyword = argv[1];
    // check if we have 2 command line arguments
    if (argc != 2) 
    {
        printf("Usage: ./vigenere keyword \n");
        return 1;
    }
    else 
        // check if the second command line argument is a word
    {
        for (int i = 0, length = strlen(keyword); i < length; i++)
        {
            if (! isalpha(keyword[i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }            
        }
        //get user input
        printf("Plaintext: ");
        char plaintext[256];
        scanf("%s", plaintext);
            
        //cipher time
        ciphertext(plaintext, keyword);
    }
}
//transform characters into numbers
int shift(char c)
{
    int shiftkey = 0;
    if (isupper(c))
    {    
        shiftkey = c - 'A';
    }
    else
    {
        shiftkey = c - 'a';
    }
    return shiftkey;
}

//get the ciphertext
void ciphertext(char *text, char *keyword)
{
    for (int i = 0, j = 0, textLength = strlen(text); i < textLength; i++, j++)
    {
        //wrap to the beginning of the keyword when it's over
        int keyLength = strlen(keyword);
        if (j == keyLength) 
        {
            j = 0;
        }
        //get the cipher numbers from the keyword
        int key = shift(keyword[j]);
        //check if the character of the plaintext is a letter
        if (isalpha(text[i]))
        {
            //transform the character into a different character according to the cipher
            if (isupper(text[i])) 
            {
                text[i] = ((text[i] - 'A') + key) % 26 + 'A';
            }
            else 
            {
                text[i] = ((text[i] - 'a') + key) % 26 + 'a';
            }
        }
        //or don't, in which case bring j back a spot/a.k.a. don't let j increment
        else 
        {
            j -= 1;
        }
    }
    //finally... print the completed super secure word or phrase
    printf("ciphertext: %s\n", text);
}
