#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[130];
	memset(a,0,sizeof(a));
	char s[1010];
	cin.getline(s,1010);
	int l=strlen(s);
	int max=0;
	for(int i=0;i<l;i++){
		if(s[i]>='A'&&s[i]<='Z'){
			a[s[i]+32]++;
			if(a[s[i]+32]>max) max=a[s[i]+32];
		} 
		else if(s[i]>='a'&&s[i]<='z'){
		    a[s[i]]++;
		    if(a[s[i]]>max) max=a[s[i]];
		} 
		else continue;
	}
	for(int i=97;i<=122;i++){
		if(a[i]==max){
			printf("%c %d\n",i,a[i]);
			break;
		}
	}
	return 0;
}
