#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m,k,li[100000],te[1001][2],t;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d %d",&te[i][0],&te[i][1]);
	for(int i=0;i<m;i++){
		int judge=0;
		scanf("%d",&k);
		memset(li,0,sizeof(li));
		for(int j=0;j<k;j++) {
			scanf("%d",&t);
			li[t]=1;
		}
		for(int j=0;j<n;j++){
			if(li[te[j][0]]==1&&li[te[j][1]]==1){
				printf("No\n");
				judge=1;
				break;
			}
		}
		if(judge==0) printf("Yes\n");
		
	}
	return 0;
}
