#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Stu {
	int id,grade;
	char name[10];
}stu[100010];
struct Rule1 {
	bool operator()(const Stu & s1,const Stu & s2){
		return s1.id<s2.id;
	}
};
struct Rule2 {
	bool operator()(const Stu & s1,const Stu & s2){
		int s=strcmp(s1.name,s2.name);
		if(s==0){
			return s1.id<s2.id;
		}else {
			return s<0;
		}
	}
};
struct Rule3 {
	bool operator()(const Stu & s1,const Stu & s2){
		if(s1.grade==s2.grade){
			return s1.id<s2.id;
		}else {
			return s1.grade<s2.grade;
		}
	}
};
int main()
{
	int n,c;
	scanf("%d %d",&n,&c);
	for(int i=0;i<n;i++){
		scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	if(c==1) sort(stu,stu+n,Rule1());
	else if(c==2) sort(stu,stu+n,Rule2());
	else sort(stu,stu+n,Rule3());
	for(int i=0;i<n;i++) printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	return 0;
}
