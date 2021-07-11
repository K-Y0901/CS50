#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 高さ入力
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);


    // ブロック表示

    for (int count = 1; count <= height ; count++)
    {
        for (int k = height - count; k > 0; k--)
        {
            printf(" ");
        }

        for (int n = 0; n < 2; n++)
        {


            for (int j = count; j > 0; j--)
            {
                printf("#");
            }
            if (n != 1)
            {
                printf("  ");
            }

        }

        printf("\n");


    }



}