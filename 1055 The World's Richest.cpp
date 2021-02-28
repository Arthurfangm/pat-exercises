#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Peo {
	char name[10];
	int age,worth;
}peo[100010];
struct Rule {
	bool operator()(const Peo & p1,const Peo & p2){
		if(p1.worth!=p2.worth){
			return p1.worth>p2.worth;
		}else{
			if(p1.age!=p2.age){
				return p1.age<p2.age;
			}else{
				int s=strcmp(p1.name,p2.name);
				return s<0;
			}
		}
	}
};
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d %d",peo[i].name,&peo[i].age,&peo[i].worth);
	}
	sort(peo,peo+n,Rule());
	for(int i=1;i<=k;i++){
		int m,min,max;
		scanf("%d %d %d",&m,&min,&max);
		printf("Case #%d:\n",i);
		int count=0;
		for(int j=0;j<n;j++){
			if(peo[j].age>=min&&peo[j].age<=max){
				count++;
				printf("%s %d %d\n",peo[j].name,peo[j].age,peo[j].worth);
				if(count==m) break;
			}
		}
		if(count==0) printf("None\n");
	}
	return 0;
}
