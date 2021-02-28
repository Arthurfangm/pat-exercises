#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100010;
int main()
{
    int nc,np;
    long long c[maxn],p[maxn];
    scanf("%d",&nc);
    for(int i=0;i<nc;i++){
        scanf("%lld",&c[i]);
    }
    scanf("%d",&np);
    for(int i=0;i<np;i++){
        scanf("%lld",&p[i]);
    }
    sort(c,c+nc);
    sort(p,p+np);
    long long total=0;
    long long i=0;
    while(i<nc&&i<np&&c[i]<0&&p[i]<0){
        total+=c[i]*p[i];
        i++;
    }
    long long ic=nc-1,ip=np-1;
    while(ic>=0&&ip>=0&&c[ic]>0&&p[ip]>=0){
        total+=c[ic]*p[ip];
        ic--;
        ip--;
    }
    printf("%lld",total);
    return 0;
}

