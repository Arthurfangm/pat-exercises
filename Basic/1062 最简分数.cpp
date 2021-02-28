#include <iostream>
#include <cstdio>
using namespace std;
int f(int a,int b)
{
    int min_=(a>b)?b:a;
    int max_=(a>b)?a:b;
    for(int i=2;i<=min_;i++){
        if(a%i==0&&b%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    float N1,N2,M1,M2;
    int K;
    float fz1,fz2;
    scanf("%f/%f %f/%f %d",&N1,&M1,&N2,&M2,&K);
    fz1=N1*K/M1;
    fz2=N2*K/M2;
    int min_fz=(fz1>fz2)?fz2:fz1;
    float max_fz=(fz1>fz2)?fz1:fz2;
    int flag=0;
    for(int i=min_fz+1;i<max_fz;i++){
        if(f(i,K)){
            if(flag==0){
                printf("%d/%d",i,K);
                flag=1;
            }
            else{
                printf(" %d/%d",i,K);
            }
        }
    }
    printf("\n");
    return 0;
}

