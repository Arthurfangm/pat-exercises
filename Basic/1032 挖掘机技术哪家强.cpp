#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
	map<int,int> mp;
	int n,max=-1,max_k=-1,tmp_id,tmp_score;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&tmp_id,&tmp_score);
		if(!mp[tmp_id])
			mp[tmp_id]=tmp_score;
		else
			mp[tmp_id]+=tmp_score;
		if(mp[tmp_id]>max){
			max=mp[tmp_id];
			max_k=tmp_id;
		}
	}
	printf("%d %d\n",max_k,max);
	return 0;
 } 
