#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *mystrncpy(char *s1,char *s2,int n){
    char *s;
    int i=0;
    s=calloc(200,sizeof(char));
    for(i=0;i<n;i++){
        s1[i]=s2[i];
    }
    s1[i+1]='\0';
    int j=0;
    while(s1[j]!='\0'){
        s[j]=s1[j];
        j++;
    }
    return s;
}
int main()
{
    char s1[100],s2[100];
    gets(s1);
    gets(s2);
    char* str=mystrncpy(s1,s2,10);
    puts(str);
    return 0;

}