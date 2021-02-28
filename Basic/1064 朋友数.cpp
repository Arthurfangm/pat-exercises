#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int seperate(int a)
{
    if(a>=1000){
        int l1=a%10;
        int l2=(a/10)%10;
        int l3=(a/100)%10;
        int l4=a/1000;
        return l1+l2+l3+l4;
    }
    else if(a>=100){
        int l1=a%10;
        int l2=(a/10)%10;
        int l3=a/100;
        return l1+l2+l3;
    }
    else if(a>=10){
        int l1=a%10;
        int l2=a/10;
        return l1+l2;
    }
    else
        return a;
}
int main()
{
    int N;
    scanf("%d",&N);
    int a[10010];
    memset(a,0,sizeof(a));
    int x;
    int counter=0;
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        int num=seperate(x);
        if(a[num]==0){
            counter++;
            a[num]=1;
        }
    }
    printf("%d\n",counter);
    int flag=0;
    for(int i=0;i<10000;i++){
        if(a[i]==1){
            if(flag==0){
                printf("%d",i);
                flag=1;
            }
            else
                printf(" %d",i);
        }
    }
    return 0;
}

