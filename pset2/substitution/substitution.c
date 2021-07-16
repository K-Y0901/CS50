#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    char *keys = argv[1];
    int change_map[27];
    change_map[26] = 0;
    
    if (strlen(keys) != 26)
    {
        printf("key must contain 26 characters. \n");
        return 1;
    }
    
    for (in i = 0; i < 26; i++)
    {
        char key = tolower(keys[i]);
        
        if (key < 'a' || key > 'z')
        {
            printf("The key %c is not alphabet. \n", key);
            return 1;
        }
        
        for (int j = 0; j < 26; j++)
        {
            char _key = tolower(keys[j]);
            if (i != j && key == _key)
            {
                printf("Duplicate characters in key.\n");
                return 1;
            }
        }
        
        if (key >= 'a' && key <= 'z')
        {
            change_map[i] = key - ('a' + i);
        }
    }
    
    char *text = get_string("plaintext: ");
    
     printf("ciphertext:");
    for (int i = 0; text[i] != '\0'; i++)
    {
        int index = 26;
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            index = text[i] - 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            index = text[i] - 'A';
        }
        printf("%c", text[i] + change_map[index]);
    }
    printf("\n");
    return 0;
}