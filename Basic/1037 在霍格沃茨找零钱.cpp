#include<cstdio>
#include<iostream>
using namespace std;
struct m {
	int g,s,k;
}p,a,tmp;
int main()
{
	int P,A,TMP;
	scanf("%d.%d.%d %d.%d.%d",&p.g,&p.s,&p.k,&a.g,&a.s,&a.k);
	P=p.g*17*29+p.s*29+p.k;
	A=a.g*17*29+a.s*29+a.k;
	TMP=A-P;
	if(TMP<0){
		TMP=-TMP;
		printf("-");
	}
	tmp.g=TMP/(17*29);
	TMP=TMP-tmp.g*17*29;
	tmp.k=TMP%29;
	tmp.s=(TMP-tmp.k)/29;
	printf("%d.%d.%d\n",tmp.g,tmp.s,tmp.k);
	return 0;
} 
