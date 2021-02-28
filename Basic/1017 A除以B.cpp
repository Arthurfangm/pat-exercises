#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[1010];
	int result[1010];
	int n;
	scanf("%s%d",str,&n);
	int len=strlen(str);
	int len_r=0;
	int rest=0;
	if(len==1&&str[0]-'0'<n) printf("0 %d",str[0]-'0');
	else{
		for(int i=0;i<len;i++){
			if(10*rest+str[i]-'0'>=n){
				result[len_r++]=(10*rest+str[i]-'0')/n;
				rest=(10*rest+str[i]-'0')%n;
			}
			else{
				rest=rest*10+str[i]-'0';
				if(len_r!=0) result[len_r++]=0;
			}
  		}
		for(int i=0;i<len_r;i++){
			printf("%d",result[i]);
		}
		printf(" %d",rest);
		}
	return 0;
} 
