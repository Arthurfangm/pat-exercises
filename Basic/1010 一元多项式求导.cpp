#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int a[1001];
	int n;
	int l=0;
	while(scanf("%d",&n)!=EOF){
		a[l]=n;
		l++;
	}
	if(a[0]==0) printf("0 0");
	else{
		for(int j=0;j<l;j++){
		    if(j%2==1){
		    	if(a[j]!=0) printf("%d %d",a[j-1]*a[j],a[j]-1);
		    	else printf("0 0");
			    if(a[j+2]!=0&&j<l-2) printf(" ");
			    else break;
		    }
	    }
	}
	return 0;
} 
