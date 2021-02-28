#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str1[100010],str2[100010],str[100010];
	int len1,len2;
	str1[0]=getchar();
	if(str1[0]=='\n') {
		len1=0;
	}
	else{
		scanf("%s",str);
		strcat(str1,str);
	}
	scanf("%s",str2);
	len1=strlen(str1);
	len2=strlen(str2);
	for(int i=0;i<len1;i++){
		if('a'<=str1[i]&&str1[i]<='z'){
			str1[i]-=32;
		}
	}
	if(len1==0) printf("%s",str2);
	else{
		if(!strchr(str1,'+')){
			for(int i=0;i<len2;i++){
				if('a'<=str2[i]&&str2[i]<='z'){
					if(!strchr(str1,str2[i]-32)){
						printf("%c",str2[i]);
					}
				}
				else{
					if(!strchr(str1,str2[i])){
						printf("%c",str2[i]);
					}
				}
			}
		}
		else{
			for(int i=0;i<len2;i++){
				if('A'>str2[i]||str2[i]>'Z'){
					if('a'<=str2[i]&&str2[i]<='z'){
						if(!strchr(str1,str2[i]-32)){
							printf("%c",str2[i]);
						}
					}
					else{
						if(!strchr(str1,str2[i])){
							printf("%c",str2[i]);
						}
					}
				}
			}
		}
	}
	return 0;
}
