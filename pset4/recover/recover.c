#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 512
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    FILE *file = fopen(argc[1], "r");
    
    if (FILE == NULL)
    {
        fprintf(stderr, "Your image cannot be opened. \n");
        return 1;
    }
    
    
}