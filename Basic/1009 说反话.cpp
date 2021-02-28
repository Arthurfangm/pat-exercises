#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char ans[90][90];
	int num=0;
	while(scanf("%s",ans[num])!=EOF){
		num++;
	}
	for(int i=num-1;i>-1;i--){
		printf("%s",ans[i]);
		if(i==0)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}
