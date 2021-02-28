#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char a[1000001],b[1000001];
	int c[130];
	cin.getline(a,1000001);
	cin.getline(b,1000001);
	int lena=strlen(a), lenb=strlen(b);
	memset(c,0,sizeof(c));
	for(int i=0;i<lena;i++)
		c[a[i]]=1;
	for(int i=0;i<lenb;i++)
		c[b[i]]=1;
	
	for(int i=0;i<lena;i++){
		if(c[a[i]]==1){
			printf("%c", a[i]);
			c[a[i]]=0;
		}
	}
	for(int i=0;i<lenb;i++){
		if(c[b[i]]==1){
			printf("%c", b[i]);
			c[b[i]]=0;
		}
	}
	return 0;
}
