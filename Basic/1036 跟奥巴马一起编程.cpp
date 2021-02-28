#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,n_half;
	char c;
	cin>>n>>c;
	if(n%2==0)
		n_half=n/2;
	else
		n_half=(n+1)/2;
	for(int i=0;i<n;i++)
		printf("%c",c);
	printf("\n");
	for(int i=1;i<n_half-1;i++){
		for(int j=0;j<n;j++){
			if(j==0||j==n-1) printf("%c",c);
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<n;i++)
		printf("%c",c);
	printf("\n");
	return 0;
}
