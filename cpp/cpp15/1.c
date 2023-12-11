#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int trans_str(char *str)
{
    char *s;
    s=calloc(strlen(str),sizeof(char));
    int i=strlen(str);
    int j=0;
    int sum=0;
    for(j=0;j<i;j++){
        s[j]=str[i-1];
        i--;
    }
    for(int k=0;k<=j;k++){
        int a=0;
        if(s[k]==1){
            a=1;
            for(int cnt=0;cnt<k;cnt++){
                a*=k;
            }
        }
        sum+=a;
    }
    return sum;
}
int main()
{
    char *s="1101";
    int sum=trans_str(s);
    printf("%d\n",sum);
    return 0;
}