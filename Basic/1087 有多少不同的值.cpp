#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f(int a){
	return a/2+a/3+a/5;
}
int main()
{
	int n, len=0, tem[20001];
	memset(tem,0,sizeof(tem));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x=f(i);
		if(tem[x]==0){
			tem[x]=1;
			len++;
		}
	}
	printf("%d",len);
	return 0;
}
