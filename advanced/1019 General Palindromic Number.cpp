#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int len=0,r[33];
    while(a!=0){
        r[len++]=a%b;
        a/=b;
    }
    int flag=1;
    for(int i=0;i<len;i++){
        if(r[i]!=r[len-1-i]){
            flag=0;
            break;
        }
    }
    if(flag==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    printf("%d",r[len-1]);
    for(int i=len-2;i>-1;i--){
        printf(" %d",r[i]);
    }
    return 0;
}

