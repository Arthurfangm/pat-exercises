#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char temp[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    char str1[101],str2[1000];
    memset(str1,0,sizeof(str1));
    memset(str2,0,sizeof(str2));
    scanf("%s",str1);
    int n=0,len=strlen(str1);
    for(int i=0;i<len;i++)
        n+=str1[i]-'0';
    sprintf(str2,"%d",n);
    len=strlen(str2);
    printf("%s",temp[str2[0]-'0']);
    for(int i=1;i<len;i++)
        printf(" %s",temp[str2[i]-'0']);
    return 0;
}
