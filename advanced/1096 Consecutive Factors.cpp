#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n,start=-1,mlen=0;
	scanf("%d",&n);
	int s=(int)sqrt(1.0*n);
	for(int i=2;i<=s;i++){
		int len=0;
		int m=i;
		while((n%m)==0){
			len++;
			if(len>mlen){
				start=i;
				mlen=len;
			}
			m*=(i+len);
		}
	}
	if(mlen==0){
		printf("1\n%d",n);
	}else{
		printf("%d\n%d",mlen,start);
		int i=1;
		while(i<mlen){
			printf("*%d",start+i);
			i++;
		}
	}
	return 0;
 } 
