#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int cmp(int a[],int b[],int l){
	for(int i=0;i<l;i++){
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}
void insertionSort(int a[],int l,int sorted){
	int k=sorted+1;
	int tmp=a[k];
	for(int i=k-1;i>-1;i--){
		if(tmp<a[i]){
			a[i+1]=a[i];
			a[i]=tmp;
		}
		else{
			break;
		}
	}
	for(int i=0;i<l;i++){
		printf("%d",a[i]);
		if(i==l-1) printf("\n");
		else printf(" ");
	}
}
int judge_insertionSort(int a[],int c[],int l){
	int sorted;
	for(int k=1;k<l;k++){
		sorted=k;
		int tmp=a[k];
		for(int i=k-1;i>-1;i--){
			if(tmp<a[i]){
				a[i+1]=a[i];
				a[i]=tmp;
			}
		}
		if(cmp(a,c,l)==1){
			return sorted;
		}
	}
}
int judge_mergeSort(int a[],int b[],int l)
{
	int c[l];
	memset(c,-1,sizeof(c));
	int seg;
	for(seg=1;seg<l;seg*=2){
		for(int start=0;start<l;start+=seg*2){
			int k=start;
			int low =start,mid=min(start+seg,l),high=min(start+seg+seg,l);
			int start1=start,end1=mid;
			int start2=mid,end2=high;
			while(start1<end1&&start2<end2){
				c[k++]=a[start1]<a[start2]?a[start1++]:a[start2++];
			}
			while(start1<end1){
				c[k++]=a[start1++];
			}
			while(start2<end2){
				c[k++]=a[start2++];
			}
		}
		for(int i=0;i<l;i++) a[i]=c[i];
		if(cmp(a,b,l)){
			return seg;
		}
		memset(c,-1,sizeof(c));
	}
	return 0;
}
void mergeSort(int a[],int l,int sorted){
	int c[l];
	int seg=2*sorted;
	for(int start=0;start<l;start+=seg*2){
		int k=start;
		int low =start,mid=min(start+seg,l),high=min(start+seg+seg,l);
		int start1=start,end1=mid;
		int start2=mid,end2=high;
		while(start1<end1&&start2<end2){
			c[k++]=a[start1]<a[start2]?a[start1++]:a[start2++];
		}
		while(start1<end1){
			c[k++]=a[start1++];
		}
		while(start2<end2){
			c[k++]=a[start2++];
		}
	}
	for(int i=0;i<l;i++){
		printf("%d",c[i]);
		if(i==l-1) printf("\n");
		else printf(" ");
	}
}
int main()
{
	int a[110],b[110],bb[110];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
		bb[i]=b[i];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int tmp;
	tmp=judge_mergeSort(b,a,n);
	if(tmp){
		printf("Merge Sort\n");
		mergeSort(a,n,tmp);
	}
	else{
		tmp=judge_insertionSort(bb,a,n);
		printf("Insertion Sort\n");
		insertionSort(a,n,tmp);
	}
	return 0;
} 
