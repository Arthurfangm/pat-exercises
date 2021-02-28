#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a[100010]={0},lena=0;
    long long sum=0;
    char s[100010];
    scanf("%s",s);
    int len=strlen(s),cp=0,ct=0;
    for(int i=0;i<len;i++){
        if(s[i]=='P') cp++;
        else if(s[i]=='A') a[lena++]=cp;
    }
    for(int i=len-1;i>=0;i--){
        if(s[i]=='T') ct++;
        else if(s[i]=='A') {
            sum=(sum+ct*a[--lena])%1000000007;
        }
    }
    printf("%lld",sum);
    return 0;
}

