#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,t;
	scanf("%d %d",&n,&m);
	int a[1001];
	memset(a,0,sizeof(a));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&t);
			a[j]+=t;
		}
	}
	int ma=0;
	for(int i=0;i<n;i++)
		if(a[i]>ma)
			ma=a[i];
	printf("%d\n",ma);
	int judge=0;
	for(int i=0;i<n;i++){
		if(a[i]==ma){
			if(judge==0){
				printf("%d",i+1);
				judge=1;
			}else{
				printf(" %d",i+1);
			}
			
		}
	}
	return 0;
 } 
