#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[11],b[11];
	int da,db;
	scanf("%s%d%s%d",a,&da,b,&db);
	int lena=strlen(a);
	int lenb=strlen(b);
	int suma=0,sumb=0,sum=0;
	for(int i=0;i<lena;i++) if(a[i]-'0'==da) suma=suma*10+da;
	for(int i=0;i<lenb;i++) if(b[i]-'0'==db) sumb=sumb*10+db;
	printf("%d",suma+sumb);
	return 0;
}
