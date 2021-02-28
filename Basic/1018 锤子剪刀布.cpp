#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	char a,b,c,d;
	scanf("%d",&n);
	int awin=0,even=0,aloss=0;
	int aC=0,aB=0,aJ=0;
	int bC=0,bB=0,bJ=0;
	while(n--){
		scanf("%c%c%c%c",&c,&a,&d,&b);
		if(a==b) even++;
		else{
			if(a=='C'&&b=='J'){
				awin++;
				aC++;
			}
			else if(a=='C'&&b=='B'){
				aloss++;
				bB++;
			}
			else if(a=='J'&&b=='C'){
				aloss++;
				bC++;
			}
			else if(a=='J'&&b=='B'){
				awin++;
				aJ++;
			}
			else if(a=='B'&&b=='J'){
				aloss++;
				bJ++;
			}
			else {
				awin++;
				aB++;
			}
		}
	}
	printf("%d %d %d\n%d %d %d\n",awin,even,aloss,aloss,even,awin);
	if(aC>aB&&aC>aJ) printf("C");
	else if(aB>aC&&aB>aJ) printf("B");
	else if(aJ>aC&&aJ>aB) printf("J");
	else if(aJ==aB&&aJ>aC) printf("B");
	else if(aJ==aC&&aJ>aB) printf("C");
	else if(aB==aC&&aB>aJ) printf("B");
	else printf("B");
	
	if(bC>bB&&bC>bJ) printf(" C");
	else if(bB>bC&&bB>bJ) printf(" B");
	else if(bJ>bC&&bJ>bB) printf(" J");
	else if(bJ==bB&&bJ>bC) printf(" B");
	else if(bJ==bC&&bJ>bB) printf(" C");
	else if(bB==bC&&bB>bJ) printf(" B");
	else printf(" B");
	return 0;
}
