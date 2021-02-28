#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node {
	int address;
	int data;
	int next;
} nodes[100010];
int main()
{
	int start;
	Node link[100010];
	int n,k;
	Node temp;
	scanf("%d%d%d",&start,&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&temp.address,&temp.data,&temp.next);
		if(temp.address==start) start=temp.address;
		nodes[temp.address]=temp;
	}
	for(int i=0;i<n;i++){
		link[i]=nodes[start];
		start=link[i].next;
		if(start==-1){
			n=i+1;
			break;
		}
	}
	int a=n/k;
	int b=k/2;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			temp=link[j+i*k];
			link[j+i*k]=link[i*k+k-1-j];
			link[i*k+k-1-j]=temp;
		}
	}
	for(int i=0;i<n-1;i++) printf("%05d %d %05d\n",link[i].address,link[i].data,link[i+1].address);
	printf("%05d %d %d\n",link[n-1].address,link[n-1].data,-1);
	return 0;
}
