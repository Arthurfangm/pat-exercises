#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int isPrime(int a){
    if(a==1) return 0;
    int t=(int)sqrt(1.0*a);
    for(int i=2;i<=t;i++){
        if(a%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int msize,n,table[10010]={0},a[10010];
    scanf("%d %d",&msize,&n);
    while(!isPrime(msize)){
        msize++;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    table[a[0]%msize]=1;
    printf("%d",a[0]%msize);
    for(int i=1;i<n;i++){
        if(table[a[i]%msize]==1){
            int step=1;
            while(step<msize){
                if(table[(a[i]+step*step)%msize]==0){
                    printf(" %d",(a[i]+step*step)%msize);
                    table[(a[i]+step*step)%msize]=1;
                    break;
                }
                step++;
            }
            if(step>=msize)
                printf(" -");
        }else{
            printf(" %d",a[i]%msize);
            table[a[i]%msize]=1;
        }
    }
    return 0;
}

