#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int k;
	int n[101];
	int tmplete[1001]={0};
	scanf("%d",&k);
	for(int i=0;i<k;i++)
		scanf("%d",&n[i]);
	for(int i=0;i<k;i++){
		int a=n[i];
		while(a!=1){
			if(a%2==0) a/=2;
			else a=(3*a+1)/2;
			if(a<=1000){
				tmplete[a]=-1;
			}
			else break;
		}
	}
	for(int i=0;i<k;i++){
		if(tmplete[n[i]]==-1) n[i]=-1;
	}
	sort(n,n+k);
	for(int i=k-1;n[i]>0;i--){
		if(n[i-1]>0) printf("%d ",n[i]);
		else printf("%d\n",n[i]);
	}
	return 0;
}
