#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char str[100000];
	cin.getline(str,100000);
	if(str[0]=='-') printf("-");
	int index=0;
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='E'){
			index=i;
		}
	}
	int len_a=index-3;
	int z=0;
	for(int i=index+2;i<len;i++){
		z=10*z+str[i]-'0';
	}
	int flag=0;
	if(str[index+1]=='+'){
		if(str[1]!='0') printf("%c",str[1]);
		for(int i=3;i<3+z;i++){
			if(str[i]!='0') flag=1;
			if(flag==0) continue;
			if(flag==0&&i>len_a) {
				printf("0.");
				flag=1;
			}
			else{
				if(i>=index) printf("0");
				else{
					printf("%c",str[i]);
				}
			}
		}
		if(len_a==1&&str[index-1]=='0') printf("0");
		if(z<len_a){
			if(flag==0) printf("0");
			printf(".");
			for(int i=3+z;i<3+len_a;i++) printf("%c",str[i]);
		}
	}
	if(str[index+1]=='-'){
		if(z==0){
			for(int i=0;i<index;i++) printf("%c",str[i]);
		}
		else {
			printf("0.");
			for(int i=0;i<z-1;i++) printf("0");
			printf("%c",str[1]);
			for(int i=3;i<3+len_a;i++) printf("%c",str[i]);
		}
	}
	return 0;
} 
