#include<cstdio>
using namespace std;
int main()
{
	int a[101];
	int N=1,M=0;
	scanf("%d %d",&N,&M);
	M=M%N;
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(int i=N-M;i<N;i++) printf("%d ",a[i]);
	for(int i=0;i<N-M-1;i++) printf("%d ",a[i]);
	if(N-M-1>=0) printf("%d",a[N-M-1]);
	return 0;
} 
