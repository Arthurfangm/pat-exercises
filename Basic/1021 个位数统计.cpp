#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	char str[1010];
	scanf("%s",str);
	int a[10]={0};
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='0') a[0]++;
		else if(str[i]=='1') a[1]++;
		else if(str[i]=='2') a[2]++;
		else if(str[i]=='3') a[3]++;
		else if(str[i]=='4') a[4]++;
		else if(str[i]=='5') a[5]++;
		else if(str[i]=='6') a[6]++;
		else if(str[i]=='7') a[7]++;
		else if(str[i]=='8') a[8]++;
		else a[9]++;
	}
	for(int i=0;i<10;i++){
		if(a[i]!=0){
			printf("%d:%d\n",i,a[i]);
		}
	}
	return 0;
} 
