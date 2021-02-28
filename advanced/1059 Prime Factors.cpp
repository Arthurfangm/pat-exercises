#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int isPrime(int a){
	if(a==1) return 0;
	int s=(int)sqrt(1.0*a);
	for(int i=2;i<=s;i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}
const int maxn=100000;
int table[maxn]={0};
void createTable(){
	for(int i=2;i<maxn;i++){
		if(table[i]==-1) continue;
		if(isPrime(i)){
			int times=2;
			while(i*times<maxn){
				table[i*times]=-1;
				times++;
			}
		}
	}
}
int main()
{
	int n;
	map<int,int> mp;
	scanf("%d",&n);
	int orign=n;
	createTable();
	for(int i=2;i<maxn&&n>1;i++){
		if(table[i]==0){
			while(n%i==0){
				if(!mp[i]){
					mp[i]=1;
					n/=i;
				}else{
					mp[i]++;
					n/=i;
				}
			}
		}
	}
	if(mp.size()==0){
		printf("%d=%d",orign,orign);
		return 0;
	}
	printf("%d=",orign);
	map<int,int>::iterator it=mp.begin();
	if(it->second==1){
		printf("%d",it->first);
	}else{
		printf("%d^%d",it->first,it->second);
	}
	it++;
	for(;it!=mp.end();it++){
		if(it->second==1){
			printf("*%d",it->first);
		}else{
			printf("*%d^%d",it->first,it->second);
		}
	}
	return 0;
}
