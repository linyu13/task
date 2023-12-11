#include <stdio.h>
#include <string.h>
#include<stdlib.h>
unsigned int rotate_1(unsigned int x, int num) {
    int i=0;
    unsigned int a=x;
    while(a>0){
        a/=10;
        i++;
    }
    char *str=(char *)malloc(sizeof(char)*i);
    a=x;
    long long num_size=1;
    for(int j=0;j<i-1;j++){
        num_size*=10;
    }
    int k=0;
    while(a>0){
        str[k]=a%num_size;
        num_size/=10;
        a/=10;
        printf("%d\n",str[k]);
        k++;
    }
    char *str_1=(char *)malloc(sizeof(char)*num);
    for(int i=0;i<num;i++){
        str_1[i]=str[i];
        printf("%d\n",str_1[i]);
    }
    char *str_2=(char *)malloc(sizeof(char)*(i-num));
    for(int j=num;j<i;j++){
        str_2[j]=str[j];
        printf("%d\n",str_2[j]);
    }
    strcat(str_2,str_1);
    unsigned int sum=0;
    int cnt=i-1;
    while(str_2[cnt]!='\0'){
        sum=sum*10+str_2[cnt];
        cnt--;
    }
    return sum;
}
int main()
{
    unsigned int x=123456;
    unsigned int sum=rotate_1(x,4);
    printf("%u\n",sum);
    return 0;
}