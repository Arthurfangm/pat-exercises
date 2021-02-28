#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits.h>
using namespace std;
int p[200000];
int isPrime(int a){
	if(a==2||a==3) return 1;
	for(int i=2;i<sqrt(a)+1;i++){
		if(a%i==0) return 0;
	}
	return 1;
}
int main()
{
	int m,n;
	//printf("%d",isPrime(3));
	p[0]=INT_MAX;
	p[1]=-INT_MAX;
	for(int i=2;i<=200000;i++){
		if(p[i]!=INT_MAX){
			if(isPrime(i)){
				p[i]=i;
				int j=2;
				while(i*j<=200000){
					p[i*j]=INT_MAX;
					j++;
				}
		    }
		}
	}
	sort(p,p+200000);
	scanf("%d %d",&m,&n);
	int counter=0;
	for(int i=m;i<=n;i++){
		counter++;
		if (i==n) printf("%d",p[i]);
		else if (counter%10==0) printf("%d\n",p[i]);
		else printf("%d ",p[i]);
	}
	return 0;
} 
