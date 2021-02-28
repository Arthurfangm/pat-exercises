#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int now=0,next,sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&next);
        if(next>now)
            sum+=(next-now)*6+5;
        else if(next<now)
            sum+=(now-next)*4+5;
        else
            sum+=5;
        now=next;
    }
    printf("%d",sum);
    return 0;
}

