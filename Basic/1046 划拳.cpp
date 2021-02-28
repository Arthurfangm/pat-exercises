#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a[4];
    int n;
    int j=0,y=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int i=0;i<4;i++){
            scanf("%d",&a[i]);
        }
        if(a[0]+a[2]==a[1]&&a[0]+a[2]==a[3])
            continue;
        if(a[0]+a[2]==a[1]&&a[0]+a[2]!=a[3])
            y++;
        if(a[0]+a[2]!=a[1]&&a[0]+a[2]==a[3])
            j++;
    }
    printf("%d %d\n",j,y);
    return 0;
}

