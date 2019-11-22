#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("What's your name?\n");
    char name[20];
    scanf("%s", name);
    
    if (strlen(name) > 20)
    {
        printf("Name can't be longer than 20 characters\n");
        return 1;
    }
    printf("hello, %s\n", name);
}