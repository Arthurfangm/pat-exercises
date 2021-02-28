#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char str1[61],str2[61],str3[61],str4[61];
	cin.getline(str1,61);
	cin.getline(str2,61);
	cin.getline(str3,61);
	cin.getline(str4,61);
	int l1=strlen(str1);
	int l2=strlen(str2);
	int l3=strlen(str3);
	int l4=strlen(str4);
	int counter=0;
	if(l1<l2){
		for(int i=0;i<l1;i++){
			if(counter==0){
				if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G'){
					counter++;
					if(str1[i]=='A') printf("MON ");
					else if(str1[i]=='B') printf("TUE ");
					else if(str1[i]=='C') printf("WED ");
					else if(str1[i]=='D') printf("THU ");
					else if(str1[i]=='E') printf("FRI ");
					else if(str1[i]=='F') printf("SAT ");
					else printf("SUN ");
		 		}
			}
			else{
				if(str1[i]==str2[i]){
					//&&(('0'<=str3[i]&&str3[i]<='9')||('A'<=str3[i]&&str3[i])))
					if('0'<=str1[i]&&str1[i]<='9'){
						printf("0%d:",str1[i]-'0');
						break;
					}
					if('A'<=str1[i]&&str1[i]<='N'){
						printf("%d:",str1[i]-'A'+10);
						break;
					}
				}
			}
		}
	}
	else{
		for(int i=0;i<l2;i++){
			if(counter==0){
				if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G'){
					counter++;
					if(str1[i]=='A') printf("MON ");
					else if(str1[i]=='B') printf("TUE ");
					else if(str1[i]=='C') printf("WED ");
					else if(str1[i]=='D') printf("THU ");
					else if(str1[i]=='E') printf("FRI ");
					else if(str1[i]=='F') printf("SAT ");
					else printf("SUN ");
				}
			}
		 	else{
				if(str1[i]==str2[i]){
				//&&(('0'<=str3[i]&&str3[i]<='9')||('A'<=str3[i]&&str3[i])))
					if('0'<=str1[i]&&str1[i]<='9'){
						printf("0%d:",str1[i]-'0');
						break; 
					}
					if('A'<=str1[i]&&str1[i]<='N'){
						printf("%d:",str1[i]-'A'+10);
						break;
					}
				}
			}
		}
	}
	if(l3<l4){
		for(int i=0;i<l3;i++){
			if(str3[i]==str4[i]){
				if((str3[i]>='a'&&str3[i]<='z')||(str3[i]>='A'&&str3[i]<='Z')){
					if(i>=0&&i<=9) printf("0%d",i);
				else printf("%d",i);
				break;
				}
			}
		}
	}
	else{
		for(int i=0;i<l4;i++){
			if(str3[i]==str4[i]){
				if((str3[i]>='a'&&str3[i]<='z')||(str3[i]>='A'&&str3[i]<='Z')){
					if(i>=0&&i<=9) printf("0%d",i);
				else printf("%d",i);
				break;
				}
			}
		}
	}
	return 0;
} 
