#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    double sum=0,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&temp);
        sum+=temp*(i+1)*(n-i);
    }
    printf("%.2lf",sum);
    return 0;
}

