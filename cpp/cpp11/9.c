#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * reverse(char *s){
    int len=strlen(s);
    char *str=NULL;
    int j=0;
    str=calloc(len,sizeof(char));
    for(int i=len-1;i>=0;i--){
        str[j]=s[i];
        j++;
    }
    return str;
}
int main()
{
    char s[100];
    gets(s);
    char *str=reverse(s);
    puts(str);
    return 0;
}