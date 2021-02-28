#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int g=n%10;
	int b=n/100;
	int s=(n-b*100-g)/10;
	while(b--) printf("B");
	while(s--) printf("S");
	for(int i=0;i<g;i++) printf("%d",i+1);
	printf("\n");
	return 0;
}
