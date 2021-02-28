#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int n,m,temp,a[100010]={0};
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        a[i]=a[i-1]+temp;
    }
    int ma=99999999;
    for(int i=1;i<=n;i++){
        temp=m+a[i-1];
        int* pos=upper_bound(a,a+n+1,temp);
        if(*(pos-1)-a[i-1]==m){
            ma=*(pos-1)-a[i-1];
            break;
        }else if(pos-a<n+1&&*pos-a[i-1]<ma){
            ma=*pos-a[i-1];
        }
    }
    for(int i=1;i<=n;i++){
        temp=a[i-1]+ma;
        int* pos=upper_bound(a,a+n+1,temp);
        if(*(pos-1)==temp){
            printf("%d-%d\n",i,pos-a-1);
        }
    }
    return 0;
}

