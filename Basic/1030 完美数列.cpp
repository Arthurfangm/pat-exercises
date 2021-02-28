#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100200];
int main()
{
	int N,p;
	scanf("%d %d",&N,&p);
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N);
	int max=0;
	int i,j,k,g;
	for(i=0;i<N;i++){
		for(j=i;j<N;j=j+100){
			if((double)a[j]/a[i]<=(double)p){
				continue;
			}
			else{
				break;
			}
		}
		if(j>=N) j=N-1;
		for(k=j;k>j-100&&k>-1;k--){
			if((double)a[k]/a[i]<=(double)p){
				break;
			}
			else{
				continue;
			}
		}
		if(k-i+1>max) max=k-i+1;
	}
	cout<<max;
	return 0;
}
