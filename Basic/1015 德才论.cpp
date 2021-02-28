#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
struct Stu {
	char id[9];
	int de;
	int cai;
	int flag;
};
struct Rule1 {
	bool operator()(const Stu & a, const Stu & b){
		if(a.flag!=b.flag) return a.flag<b.flag;
		else if(a.de+a.cai!=b.de+b.cai) return a.de+a.cai>b.de+b.cai;
		else if(a.de!=b.de) return a.de>b.de;
		else return strcmp(a.id,b.id)<0;
	}
};
int main()
{
	int N,L,H;
	multiset<Stu,Rule1> st;
	Stu tmp;
	int counter=0;
	scanf("%d %d %d",&N,&L,&H);
	for(int i=0;i<N;i++){
		scanf("%s %d %d",tmp.id,&tmp.de,&tmp.cai);
		if(tmp.de>=L&&tmp.cai>=L){
			counter++;
			if(tmp.de>=H&&tmp.cai>=H) {
				tmp.flag=1;
			}
			else if(tmp.de>=H&&tmp.cai<H) {
				tmp.flag=2;
			}
			else if(tmp.de>=tmp.cai) {
				tmp.flag=3;
			}
			else tmp.flag=4;
			st.insert(tmp);
		}
	}
	printf("%d\n",counter);
	multiset<Stu,Rule1>::iterator p;
	for(p=st.begin();p!=st.end();p++){
		printf("%s %d %d\n",p->id,p->de,p->cai);
	}
	return 0;
} 
