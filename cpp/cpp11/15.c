#include<stdio.h>
#include<string.h>
int atoi(char *s){
    int flag=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0' && s[i]<='9'){
            flag=1;
        }else{
            flag=0;
            break;
        }
    }
    return flag;
}
int main()
{
    char s[100];
    gets(s);
    int n=atoi(s);
    printf("%d\n",n);
    return 0;
}