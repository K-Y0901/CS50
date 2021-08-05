from cs50 import get_string

def is_word_end(c):
    return c == " "

def is_sentence_end(c):
    return c == "." or c == "!" or c == "?"
    
def is_letter(c):
    return c.isalpha()
    

