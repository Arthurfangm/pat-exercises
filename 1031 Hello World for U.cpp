#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char str[90];
    scanf("%s",str);
    int len=strlen(str);
    int n1=(len+2)/3;
    int n2=len-2*n1;
    for(int i=0;i<n1-1;i++){
        printf("%c",str[i]);
        for(int j=0;j<n2;j++){
            printf(" ");
        }
        printf("%c\n",str[len-1-i]);
    }
    for(int i=n1-1;i<=len-n1;i++){
        printf("%c",str[i]);
    }
    return 0;
}

