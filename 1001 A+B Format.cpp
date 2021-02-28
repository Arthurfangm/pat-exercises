#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    a=a+b;
    char s[10];
    sprintf(s,"%d",a);
    int l=strlen(s);
    int header=l%3;
    for(int i=0;i<header;i++)
        printf("%c",s[i]);
    for(int i=header;i<l;i+=3){
        if((i>1&&a<0)||(i>0&&a>0))
            printf(",");
        for(int j=i;j<i+3;j++)
            printf("%c",s[j]);
    }
    return 0;
}
