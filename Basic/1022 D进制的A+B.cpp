#include<cstdio>
#include<iostream>
using namespace std;
//ע������D�ķ�ΧΪ1<D<=10,���Բ��ÿ���D==1�������
//����A��BΪ���Ǹ�������������Ҫ����A��BΪ0������� 
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
