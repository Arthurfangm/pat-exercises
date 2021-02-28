#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int isPrime(int a)
{
	if(a==2) return 1;
	int i=0;
	int qa=sqrt(a)+1;
	for( i=2;i<qa;i++){
		if(a%i==0) break;
	}
	if(i==qa) return 1;
	else return 0;
}
int main()
{
	int tmplete[100001];
	int n;
	int counter=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		if(tmplete[i]==-1) continue;
		else{
			if(isPrime(i)){
			tmplete[i]=i;
			counter++;
			for(int j=2;i*j<n;j++) tmplete[i*j]=-1;
		}
		}
	}
//	for(int i=2;i<n;i++){
//		if(tmplete[i]!=-1) printf("%d %d",i,tmplete[i]);
//	}
	sort(tmplete,tmplete+n);
	int counter2=0;
	for(int i=n;i>n+1-counter;i--)
		if(tmplete[i]-tmplete[i-1]==2)
			counter2++;
	printf("%d",counter2);
	return 0;
}
