#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

int main()
{
    int N,M;
    int x;
    int count_stu=0,count_goods=0,count_x=0;
    map<int,bool> forbid;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d",&x);
        forbid.insert(make_pair(x,1));
    }
    for(int i=0;i<N;i++){
        count_x=0;
        char id[5];
        int K;
        int goods[11];
        memset(id,0,sizeof(id));
        memset(goods,0,sizeof(goods));
        scanf("%s %d",&id,&K);
        for(int j=0;j<K;j++){
            scanf("%d",&x);
            if(forbid[x]==1){
                goods[count_x++]=x;
                count_goods++;
            }
        }
        if(count_x!=0){
            count_stu++;
            printf("%s:",id);
            for(int i=0;i<count_x;i++){
                printf(" %04d",goods[i]);
            }
            printf("\n");
        }
    }
    printf("%d %d\n",count_stu,count_goods);
    return 0;
}

