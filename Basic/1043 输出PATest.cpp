#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[10010];
	cin.getline(s,10010);
	int l=strlen(s);
	int a[6];
	memset(a,0,sizeof(a));
	for(int i=0;i<l;i++){
		switch (s[i]){
			case 'P':a[0]++;break;
			case 'A':a[1]++;break;
			case 'T':a[2]++;break;
			case 'e':a[3]++;break;
			case 's':a[4]++;break;
			case 't':a[5]++;break;
		}
	}
	int max=0;
	for(int i=0;i<6;i++){
		if(a[i]>max) max=a[i];
	}
	while(max--){
		if(a[0]-->0) printf("P");
		if(a[1]-->0) printf("A");
		if(a[2]-->0) printf("T");
		if(a[3]-->0) printf("e");
		if(a[4]-->0) printf("s");
		if(a[5]-->0) printf("t");
	}
	printf("\n");
	return 0;
}
