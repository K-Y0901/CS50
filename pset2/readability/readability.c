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
    
    double L = 100.0 * l_count / w_count
}