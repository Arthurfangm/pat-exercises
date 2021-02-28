#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int M,N;//0<M,N<500
    int A,B;//0<A,B<255
    int x;
    scanf("%d %d %d %d %d",&M,&N,&A,&B,&x);
    int im[510][510];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&im[i][j]);
            if(im[i][j]>=A&&im[i][j]<=B){
                im[i][j]=x;
            }
        }
    }
    for(int i=0;i<M;i++){
        printf("%03d",im[i][0]);
        for(int j=1;j<N;j++){
            printf(" %03d",im[i][j]);
        }
        printf("\n");
    }
    return 0;
}

