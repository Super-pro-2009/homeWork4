#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

int main()
{
    const char *text = "     hello      world with       a blue sky and green grass       ";

    int max_start = 0;
    int max_len = 0;
    int words_counter = 0;
    int letter = 0;
    int insideWord = false;
    int len = 0;
    int start = 0;

    for (int i = 0; i < strlen(text); i++) {
        if(text[i]!=' ' && insideWord==false){
            words_counter++;
            insideWord=true;
            start = i;
        }
        
        if(insideWord==true){
            len++;
        }
        
        if(text[i]==' ' && insideWord==true){
            insideWord=false;
            if(len > max_len){
                max_len = len;
                max_start = start;
            }
            len = 0;
        }
    }
    
    printf("words in text: %d\n", words_counter);

    printf("longest word: ");
    for (int i = 0; i < max_len; i++) {
        putchar(text[max_start + i]);
    }
    putchar('\n');
    

    return 0;
}

