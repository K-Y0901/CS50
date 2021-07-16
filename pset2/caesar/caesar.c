#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./ceasar key");
        return 1;
    }
    
    int key = atoi(argv[1]);
    
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; text[i] != "\0"; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%c", 'a' + ((text[i] - 'a' + key) % 26));
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", 'A' + ((text[i]) - 'A' + key) % 26));
        }
        else{
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}