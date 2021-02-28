#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long a,b,c;
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int flag=0;
        scanf("%lld %lld %lld",&a,&b,&c);
        long long temp=a+b;
        if(a>0&&b>0&&temp<=-2) flag=1;
        else if(a<0&&b<0&&temp>=0) flag=0;
        else if(temp>c) flag=1;
        else flag=0;
        if(flag==1){
            printf("Case #%d: true\n",i+1);
        }else{
            printf("Case #%d: false\n",i+1);
        }
    }
    return 0;
}

