#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long sum=0,temp1,temp2,temp3;
    for(int i=0;i<2;i++){
        scanf("%lld.%lld.%lld",&temp1,&temp2,&temp3);
        sum+=temp1*17*29+temp2*29+temp3;
    }
    long long a=sum/17/29;
    printf("%lld.",a);
    sum-=a*17*29;
    long long b=sum/29;
    printf("%lld.",b);
    sum-=b*29;
    printf("%lld",sum);
    return 0;
}
