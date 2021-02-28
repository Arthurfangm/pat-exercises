#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s1[1010];
	char s2[1010];
	scanf("%s%s",s1,s2);
	int l1=strlen(s1);
	int l2=strlen(s2);
	int mode=1;
	int left=0;
	for(int i=0;i<l2;i++){
		int j=0;
		for(j=0;j<l1;j++){
			if(s2[i]==s1[j]){
				s1[j]=char('0'-1);
				break;
			}
		} 
		if(j==l1) {
			mode=0;
			left++;
		}
	}
	if(mode==1) printf("Yes %d\n",l1-l2);
	else printf("No %d\n",left);
	return 0;
}
