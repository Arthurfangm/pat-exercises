#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int a[100010];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N,greater<int>());
    int flag=0;
    for(int i=0;i<N;i++){
        if(a[i+1]<=i+1||i==N-1){
            flag=a[i]-1;
            break;
        }
    }
    printf("%d\n",flag);
    return 0;
}

