#include<cstdio>
#include<cstring>
using namespace std;
void f(char n){
	if(n=='0') printf("ling");
	else if(n=='1') printf("yi");
	else if(n=='2') printf("er");
	else if(n=='3') printf("san");
	else if(n=='4') printf("si");
	else if(n=='5') printf("wu");
	else if(n=='6') printf("liu");
	else if(n=='7') printf("qi");
	else if(n=='8') printf("ba");
	else printf("jiu");
}
int main()
{
	char str[110];
	memset(str,0,sizeof(str));
	scanf("%s",str);
	int l=strlen(str);
	int sum=0; 
	for(int i=0;i<l;i++){
		sum+=str[i]-'0';
	} 
	memset(str,0,sizeof(str));
	sprintf(str,"%d",sum);
	l=strlen(str);
	f(str[0]);
	for(int i=1;i<l;i++){
		printf(" ");
		f(str[i]);
	}
		
	return 0;
}
