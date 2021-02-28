#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int cmp(int a[],int b[],int n)
{
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]) return 0;
    return 1;
}
int insertion_judge(int a[],int b[],int n)
{
    for(int i=2;i<n;i++) {
        sort(a,a+i);
        if(cmp(a,b,n)){
            return i;
        }
    }
    return 0;
}
int merge_judge(int a[],int b[],int n)
{
    int seg=1;
    while(seg<n){
        for(int start=0;start<n;start+=2*seg){
            int start1=start,end1=min(start+2*seg,n);
            sort(a+start1,a+end1);
        }
        seg=seg*2;
        if(cmp(a,b,n))
            return seg;
    }
    return 0;
}
int main()
{
    int n,a[100],b[100],c[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) c[i]=a[i];
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    int judge=insertion_judge(a,b,n);
    if(judge!=0){
        printf("Insertion Sort\n");
        sort(a,a+judge+1);
        for(int i=0;i<n;i++){
            if(i!=0) printf(" ");
            printf("%d",a[i]);
        }
    } else {
        printf("Merge Sort\n");
        int seg=merge_judge(c,b,n);
        for(int start=0;start<n;start+=2*seg){
            int start1=start,end1=min(start+2*seg,n);
            sort(b+start1,b+end1);
        }
        for(int i=0;i<n;i++){
            if(i!=0) printf(" ");
            printf("%d",b[i]);
        }
    }
    return 0;
}

