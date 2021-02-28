#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	int a[1001];
	int c1=0,c2=0,c3=0,c4=0,c5=0;
	int a1=0,a2=0,a3=0,a5=0;
	float a4;
	int l=0;
	int tmp;
	while(scanf("%d",&tmp)!=EOF){
		if(l==0) {
			n=tmp;
			l++;
		}
		else{
			a[l-1]=tmp;
			if(a[l-1]%5==0){
			if(a[l-1]%2==0){
				c1++;
			    a1+=a[l-1];
			}
			}
			else if(a[l-1]%5==1){
				c2++;
				if(c2%2==0) a2-=a[l-1];
				else a2+=a[l-1];
			}
			else if(a[l-1]%5==2){
				c3++;
				a3++;
			}
			else if(a[l-1]%5==3){
				c4++;
				a4+=a[l-1];
			}
			else {
				c5++;
				if(a[l-1]>a5) a5=a[l-1];
			}
		}
	}
	if(c1==0) printf("N ");
	else printf("%d ",a1);
	if(c2==0) printf("N ");
	else printf("%d ",a2);
	if(c3==0) printf("N ");
	else printf("%d ",a3);
	if(c4==0) printf("N ");
	else printf("%.1f ",a4/c4);
	if(c5==0) printf("N");
	else printf("%d", a5);
	return 0;
}
