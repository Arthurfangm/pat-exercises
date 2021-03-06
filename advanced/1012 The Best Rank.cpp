#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Stu {
    int id;
    int grade[4];
}stu[2010];
char course[4]={'A','C','M','E'};
int rank_[10000000][4]={0};
int now;
struct Rule {
    bool operator()(const Stu & s1,const Stu & s2){
        return s1.grade[now]>s2.grade[now];
    }
};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
        stu[i].grade[0]=(1.0*(stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3])/3.0+0.5);
    }
    for(now=0;now<4;now++){
        sort(stu,stu+n,Rule());
        rank_[stu[0].id][now]=1;
        for(int i=1;i<n;i++){
            if(stu[i].grade[now]==stu[i-1].grade[now]){
                rank_[stu[i].id][now]=rank_[stu[i-1].id][now];
            }else{
                rank_[stu[i].id][now]=i+1;
            }
        }
    }
    int query;
    for(int i=0;i<m;i++){
        scanf("%d",&query);
        if(rank_[query][0]==0){
            printf("N/A\n");
        }else {
            int k=0;
            for(int j=1;j<4;j++){
                if(rank_[query][j]<rank_[query][k]){
                    k=j;
                }
            }
            printf("%d %c\n",rank_[query][k],course[k]);
        }
    }
    return 0;
}

