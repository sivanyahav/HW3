#include "txtfind.h"
#include <stdio.h>


int main()
{

char choice; // will save the option selected by the user
char s[WORD]; // An empty string that will save the word selected by the user 

//get the word selected by the user 
getword(s);

scanf("%c\n",&choice);

if(choice=='a'){
print_lines(s);
}

else if(choice=='b'){
print_similar_words(s);
}

    return 0;
}


