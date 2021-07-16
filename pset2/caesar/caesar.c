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
        
    }
}