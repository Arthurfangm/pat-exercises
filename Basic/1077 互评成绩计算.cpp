#include <iostream>
#include <cstdio>
using namespace std;

float Score(int a[],int l,int m)
{
    int valid=0;
    int sum=0;
    int max_=-1;
    int min_=110;
    for(int i=1;i<l;i++){
        if(a[i]>=0&&a[i]<=m){
            if(a[i]>max_)
                max_=a[i];
            if(a[i]<min_)
                min_=a[i];
            valid++;
            sum+=a[i];
        }
    }
    sum=sum-max_-min_;
    float grade=(1.0*sum)/(1.0*valid-2.0);
    grade=(grade+1.0*a[0])/2+0.5;
    grade=(int)grade;
    return grade;
}

int main()
{
    int N,M;
    int rank_[110];
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&rank_[j]);
        }
        int n=Score(rank_,N,M);
        printf("%d\n",n);
    }
    return 0;
}

