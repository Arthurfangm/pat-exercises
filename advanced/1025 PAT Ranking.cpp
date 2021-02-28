#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int lll=13;
struct Stu {
    long long id;
    int grade;
    int group;
    int group_rank;
}stu_total[30010];
struct Stu_g {
    long long id;
    int grade;
};
struct Rule_local {
    bool operator()(const Stu_g & sg1,Stu_g &sg2){
        if(sg1.grade!=sg2.grade){
            return sg1.grade>sg2.grade;
        }else{
            return sg1.id<sg2.id;
        }
    }
};
struct Rule_total {
    bool operator()(const Stu & s1,const Stu & s2) {
        if(s1.grade!=s2.grade){
            return s1.grade>s2.grade;
        }else{
            return s1.id<s2.id;
        }
    }
};
int main()
{
    int n,k,len_total=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        Stu_g stu_local[310];
        for(int j=0;j<k;j++){
            scanf("%lld %d",&stu_local[j].id,&stu_local[j].grade);
        }
        sort(stu_local,stu_local+k,Rule_local());
        stu_total[len_total].id=stu_local[0].id;
        stu_total[len_total].group=i+1;
        stu_total[len_total].grade=stu_local[0].grade;
        stu_total[len_total].group_rank=1;
        len_total++;
        for(int j=1;j<k;j++){
            stu_total[len_total].grade=stu_local[j].grade;
            stu_total[len_total].group=i+1;
            stu_total[len_total].id=stu_local[j].id;
            if(stu_local[j].grade==stu_local[j-1].grade){
                stu_total[len_total].group_rank=stu_total[len_total-1].group_rank;
            }else{
                stu_total[len_total].group_rank=j+1;
            }
            len_total++;
        }
    }
    sort(stu_total,stu_total+len_total,Rule_total());
    printf("%d\n",len_total);
    int realrank=1;
    printf("%013lld %d %d %d\n",stu_total[0].id,realrank,stu_total[0].group,stu_total[0].group_rank);
    for(int i=1;i<len_total;i++){
        if(stu_total[i].grade==stu_total[i-1].grade){
            printf("%013lld %d %d %d\n",stu_total[i].id,realrank,stu_total[i].group,stu_total[i].group_rank);
        }else {
            realrank=i+1;
            printf("%013lld %d %d %d\n",stu_total[i].id,realrank,stu_total[i].group,stu_total[i].group_rank);
        }
    }
    return 0;
}

