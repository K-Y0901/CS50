#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string letters);
int count_words(string words);
int count_sentences(string sentences);

int main(void)
{
    string text = get_string("Text: ");
    
    int l_count = count_letters(text);
    int w_count = count_words(text);
    int s_count = count_sentences(text);
    
    double L = 100.0 * l_count / w_count;
    double S = 100.0 * s_count / w_count;
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string letters)
{
    int count = 0;
    for (int i = 0, len = strlen(letters); i < len; i++)
    {
        if ((letters[i] > 64 && letters[i] < 91) || (letters[i] > 96 && letters[i] < 123))
        {
            count++;
        }
    }
    return count;
}