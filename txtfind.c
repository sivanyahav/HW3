#include <stdio.h>
#include "txtfind.h"
#include <string.h>


/**
This function receives an empty 
String and fills it according to the lines in the given text.
@returns number of char at line
*/

int getLine(char s[])
{
    int i=0;
    char c;
    scanf("%c",&c);

    while (i<LINE && c != '\0' && c!='\n')
    {

    s[i]=c;
    i++;
    scanf("%c",&c);

    }
    s[i]='\0';

    return i;
}

/**
This function receives an empty 
String and fills it according to the words in the given text.
@returns number of char at word
*/

int getword(char w[]){
    
    int i=0;
    char c;
    scanf("%c",&c);
    while (i<WORD && c != '\0' && c!='\n'&& c!='\t' && c!=' ' && c!= '\r')
    {

    w[i]=c;
    i++;
    scanf("%c",&c);

    }

    w[i]='\0';

    return i;
}

/**
This function receives two Strings
and their size, and check if they are equals.
@returns 0 if its false , 1 if its true. 
*/

int isEqualsStr(char str1[] , char str2[] , int n)
{

    /**Go through the two strings 
    character by character and compare the characters*/

    for(int i=0 ; i<n ; i++)
    { 

    //if there are different chars, return false.
        if(str1[i]!=str2[i])
            return 0; 
    }
    return 1; 
}


/**
This function receives two Strings
and check if str2 contained in str1.
@returns 0 if its false , 1 if its true. 
*/

int substring(char * str1, char * str2)
{
    
    int len1=strlen(str1);
    int len2=strlen(str2);

 /**
    Take sub-sections from str1 and compare them with str2
    */
    for(int i=0 ; i<=len1-len2;i++)
    {

   //if there is sub-section that equals to str2-->return true.
    if(isEqualsStr(str2 , str1+i ,len2))
        {
        return 1;
        }
    }
return 0;
}

/**
This function receives two Strings and number n of chars
and checks whether it is possible to get from s to t 
by omitting n characters.
@returns 0 if its false , 1 if its true. 
*/

int similar (char *s, char *t, int n)
{

    int len1=strlen(s);
    int len2=strlen(t);
    int count=0; // count the number of different chars between s to t. 

    //if the strings are the same size and equals-->return true.
    if(len1==len2&& isEqualsStr(s , t , len1))
        return 1;

    /**if the size of s-n is bigger than size of t-->
    we cant get from s to t by omitting characters.
    if it equals-->continue 
    */

    if((len1-n)==len2)
    {

        //if t containd in s-->return true. 
        
        if(substring(s,t))
            return 1;

        int i=0; int j=0;


        while(i<len1 && j<len2 )
        {

            if(s[i]==t[j])

            {
            i++ ; j++;
            }

            else
            {
                count++; i++;

                //if the number of different char bigger than n-->return false.
                if(count>n)
                {
                return 0;
                }
            
            }
        }



        if(count==n)
        {
            return 1;
        }
    }

return 0;
}


/**
The function receives a string and prints all 
the lines from a given text in which the string
 is contained
*/

void print_lines(char * str)
{

    char s[LINE]; // empty String.
    int i=0;

    /**go through all the lines in the text
    that the user entered and get line by line 
    */

    while(i<NUM_LINE)
    {

    //get a line from the text.
    getLine(s);

        //check if the given word is contained in the line
    if(substring(s,str))
    {
        //if it does-->we will print the line. 
        printf("%s\n",s);
    }

    i++;      

    }

}

/**
The function receives a string and prints all 
the words from a given text that are similar
to it to the point of ommiting one character.
*/
void print_similar_words(char * str)
{
    char s[LINE];

    int i=0;

    while(i<NUM_LINE*LINE)
    {
    
    //get word from the text.
    getword(s);

    /**if the givven word and the word from the text 
    are similar-->we will print the word from the text.
    */
    if(similar(s,str,1))
    {

     printf("%s\n",s);

    }

    i++;
    
    }


}