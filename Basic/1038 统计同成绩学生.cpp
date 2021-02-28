#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int tmp;
	int nodes[110];
	for(int i=0;i<110;i++) nodes[i]=0;
	while(n--){
		scanf("%d",&tmp);
		nodes[tmp]++;
	}
	int m;
	cin>>m;
	while(m--){
		scanf("%d",&tmp);
		printf("%d",nodes[tmp]);
		if(m==0) printf("\n");
		else printf(" ");
	}
	return 0;
} 
