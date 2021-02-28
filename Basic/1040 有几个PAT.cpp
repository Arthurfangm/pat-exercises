#include<iostream>
#include<cstdio>
#include<cstring> 
struct a{
	long long int p,t;
}aa[500100];
using namespace std;
int main()
{
	char s[500100];
	cin>>s;
	int c_p,c_a,c_t;
	int l=strlen(s);
	int len=0;
	len=0;
	for(int i=0;i<l;i++){
		if(s[i]=='P') c_p++;
		if(s[i]=='A'){
			c_a++;
			aa[len].p=0;
			aa[len++].p=c_p;
		}
	}
	int lenl=len;
	len--;
	for(int i=l-1;i>-1;i--){
		if(s[i]=='T') c_t++;
		if(s[i]=='A'){
			aa[len].t=0;
			aa[len--].t=c_t;
		}
	}
	int sum=0;
	for(int i=0;i<lenl;i++){
		sum=(sum+(aa[i].p*aa[i].t)%1000000007)%1000000007;
	}
	
	printf("%d\n",sum);
	return 0;
}
