#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Stu {
    int user_id;
    int p[6];
    int flag;
    int full_marks;
    int grade;
    Stu() {
        user_id=-1;
        fill(p,p+6,-2);
        flag=0;
        full_marks=0;
        grade=0;
    }
}stu[10010];
struct Rule {
    bool operator()(const Stu & stu1,const Stu & stu2){
        if(stu1.flag!=stu2.flag) return stu1.flag>stu2.flag;
        else{
            if(stu1.grade!=stu2.grade) return stu1.grade>stu2.grade;
            else{
                if(stu1.full_marks!=stu2.full_marks) return stu1.full_marks>stu2.full_marks;
                else{
                    return stu1.user_id<stu2.user_id;
                }
            }
        }
    }
};
int main()
{
    int n,m,k,p[6];
    memset(p,0,sizeof(p));
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=k;i++) scanf("%d",&p[i]);
    int user_id,problem_id,score;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&user_id,&problem_id,&score);
        if(score>stu[user_id].p[problem_id]){
            if(score==-1) {
                stu[user_id].p[problem_id]=0;
                continue;
            }
            stu[user_id].flag=1;
            stu[user_id].user_id=user_id;
            if(score==p[problem_id]) stu[user_id].full_marks++;
            if(stu[user_id].p[problem_id]!=-2) stu[user_id].grade+=(score-stu[user_id].p[problem_id]);
            else stu[user_id].grade+=score;
            stu[user_id].p[problem_id]=score;
        }
    }
    sort(stu,stu+n+1,Rule());
    printf("1 %05d %d",stu[0].user_id,stu[0].grade);
    for(int i=1;i<=k;i++)
    {
        if(stu[0].p[i]==-2) printf(" -");
        else printf(" %d",stu[0].p[i]);
    }
    printf("\n");
    int rr=1;
    for(int i=1;i<n;i++) {
        if(!stu[i].flag) break;
        if(stu[i].grade!=stu[i-1].grade) rr=i+1;
        printf("%d %05d %d",rr,stu[i].user_id,stu[i].grade);
        for(int j=1;j<=k;j++)
        {
            if(stu[i].p[j]==-2) printf(" -");
            else printf(" %d",stu[i].p[j]);
        }
        printf("\n");
    }
    return 0;
}
/*
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Stu {
	int id,fullMarks,totals;
	int pers[6]={-1,-1,-1,-1,-1,-1};
	Stu(){
		id=-1;
		fullMarks=0;
		totals=0;
	}
} stu[10010];
struct Rule {
	bool operator()(const Stu & s1,const Stu & s2){
//		if(s1.id==-1&&s2.id!=-1) return false;
//		if(s1.id!=-1&&s2.id==-1) return true;
		if(s1.totals!=s2.totals){
			return s1.totals>s2.totals;
		}else{
			if(s1.fullMarks!=s2.fullMarks){
				return s1.fullMarks>s2.fullMarks;
			}
			else{
//				if(s1.totals==0&&s2.totals==0)
//					return s1.id>s2.id;
				return s1.id<s2.id;
			}
		}
	}
};
int main()
{
	int n,k,m;
	int s[6];
	scanf("%d %d %d",&n,&k,&m);
	for(int i=1;i<=k;i++){
		scanf("%d",&s[i]);
	}
	for(int i=0;i<m;i++){
		int temp_id=-1,temp_p=-1,temp_s=-1;
		scanf("%d %d %d",&temp_id,&temp_p,&temp_s);
		if(temp_s==-1){
			if(stu[temp_id].pers[temp_p]==-1)
				stu[temp_id].pers[temp_p]=0;
			continue;
		}

		stu[temp_id].id=temp_id;
		if(temp_s>stu[temp_id].pers[temp_p]){
			stu[temp_id].pers[temp_p]=temp_s;
		}
		if(temp_s==s[temp_p]){
			stu[temp_id].fullMarks++;
		}
	}
	for(int i=1;i<=n;i++){
		if(stu[i].id==-1){
			continue;
		}
		for(int j=1;j<=k;j++){
			if(stu[i].pers[j]!=-1)
				stu[i].totals+=stu[i].pers[j];
		}
	}
	sort(stu+1,stu+n+1,Rule());
//	int rank=1;
//	int temp=(stu[1].totals>0)?stu[1].totals:0;
//	printf("%d %05d %d",rank,stu[1].id,temp);
//	for(int i=1;i<=k;i++){
//		if(stu[1].pers[i]!=-1){
//			printf(" %d",stu[1].pers[i]);
//		}else{
//			printf(" -");
//		}
//	}
//	printf("\n");
int rank=1;
	for(int j=1;j<=n;j++){
		if(stu[j].id==-1){
			continue;
		}
		if(stu[j].totals!=stu[j-1].totals){
			rank=j;
		}
		int temp=(stu[j].totals>0)?stu[j].totals:0;
		printf("%d %05d %d",rank,stu[j].id,temp);
		for(int i=1;i<=k;i++){
			if(stu[j].pers[i]!=-1){
				printf(" %d",stu[j].pers[i]);
			}else{
				printf(" -");
			}
		}
		printf("\n");
	}
	return 0;
}*/

