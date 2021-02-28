#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char str[20];
	int n;
	scanf("%d",&n);
	int flag=1;
	int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int b[11]={1,0,10,9,8,7,6,5,4,3,2};
	for(int i=0;i<n;i++){
		int flag1=1;
		scanf("%s",str);
		int sum=0;
		for(int j=0;j<17;j++){
			if(str[j]=='X') {
				flag=0;
				flag1=0;
				break;
			}
			else sum+=(str[j]-'0')*a[j];
		}
		if(flag1==0){
			printf("%s\n",str);
		}
		else{
			int left=sum%11;
			if(left==2) {
				if(str[17]!='X'){
					flag=0;
					printf("%s\n",str);
				}
			}
			else {
				if(b[left]!=str[17]-'0'){
					flag=0;
					printf("%s\n",str);
				}
			}
		}
	} 
	if(flag==1) printf("All passed\n");
	return 0;
}
