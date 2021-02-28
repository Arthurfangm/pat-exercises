#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int counter=0;
    int a[100010];
    memset(a,-1,sizeof(a));
    scanf("%d",&N);
    int x,y;
    for(int i=1; i<=N; i++)
    {
        scanf("%d %d",&x,&y);
        a[x]=y;
        a[y]=x;
    }
    int M;
    int b[100010];
    memset(b,-1,sizeof(b));
    int m[10010];
    int left_[10010];
    memset(m,-1,sizeof(m));
    memset(left_,-1,sizeof(left_));
    scanf("%d",&M);
    for(int i=0; i<M; i++)
    {
        scanf("%d",&x);
        m[i]=x;
        b[x]=x;
    }
    for(int i=0; i<M; i++)
    {
        x=m[i];
        if(a[x]!=-1)
        {
            y=a[x];
            if(b[y]!=-1)
            {
                continue;
            }
            else
            {
                left_[counter++]=x;
            }
        }
        else
        {
            left_[counter++]=x;
        }
    }
    printf("%d\n",counter);
    if(counter!=0)
    {
        sort(left_,left_+counter);
        for(int i=0; i<counter; i++)
        {
            if(i==0){
                    printf("%05d",left_[i]);
            }
            else
                printf(" %05d",left_[i]);
        }
        printf("\n");
    }
    return 0;
}

