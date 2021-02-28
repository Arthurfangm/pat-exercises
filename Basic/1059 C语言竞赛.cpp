#include <iostream>
#include <cstring>
#include <cstdio>
#define ESP 0.001
using namespace std;
float sqrt(float n)
{
    float x=n;
    float nextx=(x+n/x)/2;
    while(x-nextx>ESP||nextx-x>ESP){
        x=nextx;
        nextx=(x+n/x)/2;
    }
    return nextx;
}
int isPrime(int n)
{
    if(n==2)
        return 1;
    float sqrt_n=sqrt(n)+1;
    for(int i=2;i<=sqrt_n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int N,K;
    int rank[10010],used[10010];
    int prime[10010];
    prime[1]=1;
    memset(rank,0,sizeof(rank));
    memset(used,0,sizeof(used));
    memset(prime,0,sizeof(prime));
    scanf("%d",&N);
    for(int i=2;i<=N;i++){
        if(prime[i]==1)
            continue;
        else{
            if(isPrime(i)){
                for(int j=2;j*i<=N;j++){
                    prime[j*i]=1;
                }
            }
        }
    }
    int x;
    for(int i=1;i<=N;i++){
        scanf("%d",&x);
        rank[x]=i;
        used[x]=1;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&x);
        if(used[x]==0)
            printf("%04d: Are you kidding?\n",x);
        else if(used[x]==2)
            printf("%04d: Checked\n");
        else{
            used[x]=2;
            if(rank[x]==1){
                printf("%04d: Mystery Award\n",x);
            }
            else{
                if(prime[rank[x]]==0){
                    printf("%04d: Minion\n",x);
                }
                else{
                    printf("%04d: Chocolate\n",x);
                }
            }
        }
    }
    return 0;
}

