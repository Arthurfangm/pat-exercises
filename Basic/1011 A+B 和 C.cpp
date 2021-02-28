#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a-c+b>0) printf("Case #%d: true\n", i);
		else printf("Case #%d: false\n", i);
	}
	return 0;
} 
