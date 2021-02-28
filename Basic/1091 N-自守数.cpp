#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int m,n;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		int nn=n*n;
		for(int i=1;i<10;i++){
			int judge=0;
			if(0<=n&&n<=9){
				for(int j=1;j<10;j++){
					if(nn*j%10==n){
						printf("%d %d\n",j,nn*j);
						judge=1;
						break;
					}
				}
				if(judge==0) printf("No\n");
				break;
			}else if(10<=n&&n<=99){
				for(int j=1;j<10;j++){
					if(nn*j%100==n){
						printf("%d %d\n",j,nn*j);
						judge=1;
						break;
					}
			    }
				if(judge==0) printf("No\n");
				break;
			}else {
				for(int j=1;j<10;j++){
					if(nn*j%1000==n){
						
						printf("%d %d\n",j,nn*j);
						judge=1;
						break;
					}
			    }
				if(judge==0) printf("No\n");
				break;
			}
		}
	} 
	return 0;
}
