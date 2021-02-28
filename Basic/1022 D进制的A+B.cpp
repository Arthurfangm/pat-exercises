#include<cstdio>
#include<iostream>
using namespace std;
//注意题中D的范围为1<D<=10,所以不用考虑D==1的情况。
//而数A和B为“非负整数”，所以要考虑A和B为0的情况。 
int main()
{
	int left[35];
	int a,b,d,devide;
	scanf("%d%d%d",&a,&b,&d);
	devide=a+b;
	int len=0;
	do{
		left[len++]=devide%d;
		devide/=d;
	}while(devide!=0);
	for(int i=len-1;i>-1;i--) printf("%d",left[i]);
	printf("\n");
	return 0;
}
