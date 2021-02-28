#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a=0,b=0;
	long long int r=0;
	scanf("%d %d",&a,&b);
	r = a*b;
	int flag=0;
	while(r%10==0){
		r/=10;
	}
	while(r>0){
		printf("%d",r%10);
		r/=10;
	}
	printf("\n");
	return 0;
} 
