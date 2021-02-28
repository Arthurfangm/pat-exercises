#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int p1=0,p2=0,len=0;
    int n1,n2,a[200010]={0},b[200010]={0};
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    int n=(n1+n2-1)/2;
    while(p1<n1||p2<n2){
        if(p1<n1&&p2<n2){
            if(len==n){
                printf("%d",(a[p1]<b[p2])?a[p1]:b[p2]);
                break;
            }else {
                if(a[p1]<b[p2])
                    p1++;
                else
                    p2++;
                len++;
            }
        }
        else if(p1<n1&&p2>=n2){
            if(len==n){
                printf("%d",a[p1]);
                break;
            }else{
                p1++;
                len++;
            }
        }else{
            if(len==n){
                printf("%d",b[p2]);
                break;
            }else{
                p2++;
                len++;
            }
        }
    }
    return 0;
}

