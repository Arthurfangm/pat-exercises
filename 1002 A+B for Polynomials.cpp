#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int k1,k2,maxN,n;
    float l[1001],tem;
    memset(l,0,sizeof(l));
    scanf("%d",&k1);
    for(int i=0;i<k1;i++){
        scanf("%d %f",&n,&tem);
        if(n>maxN) maxN=n;
        l[n]=tem;
    }
    scanf("%d",&k2);
    for(int i=0;i<k2;i++){
        scanf("%d %f",&n,&tem);
        if(n>maxN) maxN=n;
        if(l[n]==0) k1++;
        l[n]+=tem;
        if(l[n]==0) k1--;
    }
    printf("%d",k1);
    for(int i=maxN;i>-1;i--){
        if(l[i]!=0) printf(" %d %.1f",i,l[i]);
    }
    return 0;
}
