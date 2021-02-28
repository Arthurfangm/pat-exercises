#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int isPrime(int a){
    if(a==1) return 0;
    for(int i=2;i<a/2;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,d;
    while(scanf("%d",&n)){
        if(n<0) break;
        scanf("%d",&d);
        if(isPrime(n)){
            int s[15],lena=0,b=0;
            memset(s,0,sizeof(s));
            int temp=n;
            while(temp>0){
                s[lena++]=temp%d;
                temp/=d;
            }
            for(int i=0;i<lena;i++){
                b=d*b+s[i];
            }
            if(isPrime(b)){
                printf("Yes\n");
            }else {
                printf("No\n");
            }
        }else{
            printf("No\n");
            continue;
        }
    }
    return 0;
}

