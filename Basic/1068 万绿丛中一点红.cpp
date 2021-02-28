#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int a[1010][1010];
typedef map<int,int> MP;
int main()
{
    MP mp;
    int M,N,TOL;
    int x,y,color;
    int max_=-1;
    int counter=0;
    scanf("%d %d %d",&M,&N,&TOL);
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            if(i==0||i==N+1||j==0||j==M+1){
                a[i][j]==-201;
            }
            else{
                scanf("%d",&a[i][j]);
                mp[a[i][j]]++;
                if(a[i][j]>max_){
                    max_=a[i][j];
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(mp[a[i][j]]==1){
                if(abs(a[i][j]-a[i-1][j-1])>TOL&&
                   abs(a[i][j]-a[i-1][j])>TOL&&
                   abs(a[i][j]-a[i-1][j+1])>TOL&&
                   abs(a[i][j]-a[i][j-1])>TOL&&
                   abs(a[i][j]-a[i][j+1])>TOL&&
                   abs(a[i][j]-a[i+1][j-1])>TOL&&
                   abs(a[i][j]-a[i+1][j])>TOL&&
                abs(a[i][j]-a[i+1][j+1])>TOL){
                    counter++;
                    if(counter>1)
                        break;
                    x=i;
                    y=j;
                    color=a[i][j];
                }
            }
        }
        if(counter>1)
            break;
    }
    if(counter==1){
        printf("(%d, %d): %d\n",y,x,color);
    }
    else if(counter==0){
        printf("Not Exist\n");
    }
    else{
        printf("Not Unique\n");
    }
    return 0;
}

