#include<stdio.h>
#include<stdbool.h>
bool isLongPressedName(char* name, char* typed) {
    int i=0;
    int j=0;
    while(typed[j]!='\0'){
        if(typed[j]==name[i]){
            i++;
        }
        j++;
    }
    if(name[i]=='\0' && typed[j-1]==name[i-1]){
        return true;
    }else{
        return false;
    }
}
int main()
{
    char *str1="alex";
    char *str2="aalleexa";
    isLongPressedName(str1,str2);
    return 0;
}