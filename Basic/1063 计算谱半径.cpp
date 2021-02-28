#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int toInt(float a)
{
    return (int)(100.0*a+0.5)/100.0;
}
int main()
{
    int N;
    scanf("%d",&N);
    double max_=-1;
    int a,b;
    for(int i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        double sqrt_=sqrt(a*a+b*b);
        if(sqrt_>max_)
            max_=sqrt_;
    }
    printf("%.2f\n",max_);
    return 0;
}

