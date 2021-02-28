#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100010;
int d[maxn]={0},sum=0;
int dis(int a,int b){
    if(a==b) return 0;
    int ma=a>b?a:b;
    int mi=a<b?a:b;
    int dd=d[ma]-d[mi];
    return (dd<(sum-dd))?dd:(sum-dd);
}
int main()
{
    int n,m,temp;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&temp);
        d[i]=d[i-1]+temp;
    }
    scanf("%d",&temp);
    sum=temp+d[n];
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",dis(a,b));
    }
    return 0;
}

