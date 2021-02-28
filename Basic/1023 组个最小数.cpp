#include<cstdio>
int main()
{
	int a[10],flag=0;
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
		if(i!=0&&a[i]!=0&&flag==0){
			printf("%d",i);
			a[i]--;
			flag=1;
		}
	}
	for(int i=0;i<10;i++){
		while(a[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
