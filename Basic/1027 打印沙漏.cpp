#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	int nn=(n+1)/2;
	nn=sqrt(nn);
	int left=n+1-2*nn*nn;
	for(int i=nn;i>0;i--){
		int l1=nn-i;
		int l2=2*i-1;
		for(int j=0;j<l1;j++) printf(" ");
		for(int j=0;j<l2;j++) printf("%c",c);
		printf("\n");
	}
	for(int i=2;i<=nn;i++){
		int l1=nn-i;
		int l2=2*i-1;
		for(int j=0;j<l1;j++) printf(" ");
		for(int j=0;j<l2;j++) printf("%c",c);
		printf("\n");
	}
	printf("%d",left);
	return 0;
}

