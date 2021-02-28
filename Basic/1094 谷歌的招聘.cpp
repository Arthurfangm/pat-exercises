#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
int isPrime(int n){
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	int s=sqrt(n);
	for(int i=2;i<=s;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int l,k;
	char orig[1001],opt[11];
	scanf("%d %d",&l,&k);
	scanf("%s",orig);
	int judge=0;
	for(int i=0;i<l-k+1;i++){
		memset(opt,0,sizeof(opt));
		int t;
		strncpy(opt,orig+i,k);
		sscanf(opt,"%d",&t);
		if(isPrime(t)) {
			printf("%s",opt);
			judge=1;
			break;
		}
	}
	if(judge==0)
		printf("404");
	return 0;
}
