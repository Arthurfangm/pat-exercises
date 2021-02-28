#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    double a;
    double sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a);
        double num=1.0*(i+1)*(n-i);
        sum+=num*a;
    }
    printf("%.2lf\n",sum);
    return 0;
}

