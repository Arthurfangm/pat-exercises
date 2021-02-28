#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int N;
    float a[10010];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%f",&a[i]);
    }
    sort(a,a+N);
    float sum=0.0;
    sum+=(a[0]+a[1])/pow(2,(1.0*N-1.0));
    for(int i=2;i<N;i++){
        sum+=a[i]/pow(2,(1.0*N-1.0*i));
    }
    printf("%d\n",(int)sum);
    return 0;
}

