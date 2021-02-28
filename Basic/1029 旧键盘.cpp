#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str1[85];
	char str2[85];
	char str3[85];
	int l=0;
	scanf("%s%s",str1,str2);
	int len=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len2;i++){
		if('a'<=str2[i]&&str2[i]<='z') str2[i]=str2[i]-32;
	}
	for(int i=0;i<len;i++){
		if('a'<=str1[i]&&str1[i]<='z') str1[i]=str1[i]-32;
		if(!strchr(str2,str1[i])){
			if(!strchr(str3,str1[i])){
				str3[l++]=str1[i];
			}
		}
	}
	for(int i=0;i<l;i++){
		printf("%c",str3[i]);
	}
	return 0;
}
