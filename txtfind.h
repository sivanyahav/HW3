#define LINE 256
#define WORD 30
#define NUM_LINE 250

int getLine(char s[]);

int getword(char w[]);
int isEqualsStr(char str1[] , char str2[] , int n);
int substring( char * str1, char * str2);

int similar (char *s, char *t, int n);

void print_lines(char * str);

void print_similar_words(char * str);