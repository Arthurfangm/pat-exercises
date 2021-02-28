#include <map>
#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-7
using namespace std;
int Equ_zero(double a){
    if(fabs(a-0.0)<=eps)
        return 1;
    else
        return 0;
}
int main()
{
    int n1,n2;
    double a[20],b[20];
    scanf("%d",&n1);
    int k1=2*n1;
    for(int i=0;i<k1;i++){
        scanf("%lf",&a[i]);
    }
    scanf("%d",&n2);
    int k2=2*n2;
    for(int i=0;i<k2;i++){
        scanf("%lf",&b[i]);
    }
    map<int,double> mp;
    for(int i=0;i<k1;i+=2){
        for(int j=0;j<k2;j+=2){
            double temp=a[i]+b[j];
            if(mp[(int)temp]){
                double k=a[i+1]*b[j+1];
                mp[(int)temp]+=k;
            }else{
                double k=a[i+1]*b[j+1];
                mp[(int)temp]=k;
            }
        }
    }

    for(map<int,double>::iterator it=mp.begin();it!=mp.end();it++){
        //if(Equ_zero(it->second))
        if(it->second==0.0)
            mp.erase(it);
    }
    printf("%d",mp.size());
    for(map<int,double>::reverse_iterator it=mp.rbegin();it!=mp.rend();it++){
        if(it->second==0.0) continue;
        printf(" %d %.1f",it->first,it->second);
    }
    return 0;
}

