#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a[10010],t[100010],n;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
        a[t[i]]++;
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(a[t[i]]==1) {
            printf("%d",t[i]);
            flag=1;
            break;
        }
    }
    if(flag==0) printf("None");
    return 0;
}

