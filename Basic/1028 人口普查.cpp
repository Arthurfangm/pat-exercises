#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a,b,c;
	char name[10];
	int max=0,min=0;
	min = 2015*365;
	char maxName[10],minName[10];
	int counter=0;
	int now=2014*365+9*30+6;
	for(int i=0;i<n;i++){
		scanf("%s%d/%d/%d",name,&a,&b,&c);
		int day=365*a+30*b+c;
		if(now-day>365*200||day>now) continue;
		else {
			counter++;
			if(day<=min) {
				min=day;
				strcpy(minName,name);
			}
			if(day>=max) {
				max=day;
				strcpy(maxName,name);
			}
		}
	}
	printf("%d",counter);
	if(counter>0){
		printf(" %s %s\n",minName,maxName);
	}
	return 0;
}
