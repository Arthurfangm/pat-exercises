#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[100100],b[100100];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    int c[100100];
    int k=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(a[i]>max)
            max=a[i];
        if(a[i]==b[i]&&a[i]==max){
            c[k++]=b[i];
        }
    }
    if(n!=0)
        printf("%d\n",k);
    for(int i=0;i<k;i++){
        if(i!=0)
            printf(" ");
        printf("%d",c[i]);
    }
    printf("\n");
    return 0;
}

