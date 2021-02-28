#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	char str[100];
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		int len=strlen(str);
		//if unexpected character return wrong
		int nP=0;
		int nT=0;
		int pP=0;
		int pT=0;
		int ifcontinue=1;
		for(int i=0;i<len;i++){
			if(str[i]!=' '&&str[i]!='P'&&str[i]!='A'&&str[i]!='T'){
				ifcontinue=0;
				break;
			}
			if(str[i]=='P') {
				if(nP==0) pP=i;
				nP++;
				if(nP>1){
					ifcontinue=0;
					break;
				} 
			}
			if(str[i]=='T') {
				if(pT==0) pT=i;
				nT++;
				if(nT>1){
					ifcontinue=0;
					break;
				}
			}
		}
		if(ifcontinue==0||pT-pP<2){
			printf("NO\n");
			continue;
		}
		else{
			int la=pP;
			int lb=pT-pP-1;
			int lc=len-1-pT;
			if(la*lb==lc){
				printf("YES\n");
				continue;
			}
			else {
				printf("NO\n");
				continue;
			} 
		}
	}
	return 0;
}
