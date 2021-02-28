#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a[2][110];
    int grades[110];
    memset(grades,0,sizeof(grades));
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d",&a[0][i]);
    }
    for(int i=0;i<M;i++){
        scanf("%d",&a[1][i]);
    }
    int x;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++){
            scanf("%d",&x);
            if(x==a[1][j]){
                grades[i]+=a[0][j];
            }
        }
    }
    for(int i=0;i<N;i++){
        printf("%d\n",grades[i]);
    }
    return 0;
}

