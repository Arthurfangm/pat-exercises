#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double a,b,c,d,p1,p2,q1,q2;
    cin>>a>>b>>c>>d;
    p1=a*cos(b);
    p2=a*sin(b);
    q1=c*cos(d);
    q2=c*sin(d);
    double r1=p1*q1-p2*q2;
    double r2=p1*q2+p2*q1;
    if(fabs(r1)<0.01)
        r1=0;
    if(fabs(r2)<0.01)
        r2=0;
    if(r2<0)
        printf("%.2f%.2fi\n",r1,r2);
    else
        printf("%.2f+%.2fi\n",r1,r2);
    return 0;
}

