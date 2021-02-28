#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
struct School{
    char sch[7];
    int T;
    int A;
    int B;
    int num;
    int sum;
    School(){
        T=0,A=0,B=0,sum=0,num=0;
    }
}schools[100010];

struct Rule{
    bool operator()(const School & s1,const School & s2){
        if(s1.sum>s2.sum)
            return 1;
        else if(s1.sum==s2.sum){
            if(s1.num<s2.num)
                return 1;
            else if(s1.num==s2.num){
                if(strcmp(s1.sch,s2.sch)<0)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }
};

int main()
{
    map<string,int> mp;
    char tmp_stu[7],tmp_sch[7];
    int tmp_score;
    int n;
    scanf("%d",&n);
    int counter=1;
    for(int i=0;i<n;i++){
        scanf("%s %d %s",tmp_stu,&tmp_score,tmp_sch);
        int len=strlen(tmp_sch);
        for(int k=0;k<len;k++){
            if(tmp_sch[k]>='A'&&tmp_sch[k]<='Z'){
                tmp_sch[k]+='a'-'A';
            }
        }
        if(!mp[tmp_sch]){
            mp[tmp_sch]=counter;
            strcpy(schools[counter++].sch,tmp_sch);
        }
        schools[mp[tmp_sch]].num++;
        if(tmp_stu[0]=='A'){
            schools[mp[tmp_sch]].A+=tmp_score;
        }
        else if(tmp_stu[0]=='B'){
            schools[mp[tmp_sch]].B+=tmp_score;
        }
        else{
            schools[mp[tmp_sch]].T+=tmp_score;
        }
    }
    int rank_=1;
    for(int i=1;i<counter;i++){
        schools[i].sum=(1.0*schools[i].B/1.5+1.0*schools[i].A+1.0*schools[i].T*1.5);
    }
    sort(schools+1,schools+counter,Rule());
    printf("%d\n",counter-1);
    for(int i=1;i<counter;i++){
        printf("%d %s %d %d\n",rank_,schools[i].sch,schools[i].sum,schools[i].num);
        if(schools[i].sum!=schools[i+1].sum)
            rank_=i+1;
    }
    return 0;
}

