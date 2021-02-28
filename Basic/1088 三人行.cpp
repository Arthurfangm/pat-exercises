#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;
void f(double x, int m){
	if(x>m)
		printf(" Cong");
	else if(x==m)
		printf(" Ping");
	else
		printf(" Gai");
}
int main()
{
	int m, x, y;
	scanf("%d %d %d", &m, &x,&y);
	int i;
	double j,k;
	for(i=99;i>0;i--) {
		j=i%10*10+i/10;
		k=j/y;
		if(k==abs(i-j)/x){
			printf("%d",i);
			f(1.0*i,m);
			f(j,m);
			f(k,m);
			return 0;
		}
	} 
	printf("No Solution");
	return 0;
}
