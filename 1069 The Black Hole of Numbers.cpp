#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr2greater(int a[]){
    sort(a,a+4,greater<int>());
    return 1000*a[0]+100*a[1]+10*a[2]+a[3];
}
int arr2smaller(int a[]){
    sort(a,a+4);
    return 1000*a[0]+100*a[1]+10*a[2]+a[3];
}
int b[4];
void num2arr(int num){
    b[0]=num/1000;
    b[1]=(num-1000*b[0])/100;
    b[3]=num%10;
    b[2]=(num/10)%10;
}
int main()
{
    int n;
    scanf("%d",&n);
    num2arr(n);
    if(b[0]==b[1]&&b[0]==b[2]&&b[0]==b[3]){
        printf("%d - %d = 0000",n,n);
    }else{
        int s=arr2smaller(b);
        int g=arr2greater(b);
        int gap=g-s;
        printf("%04d - %04d = %04d\n",g,s,gap);
        while(gap!=6174){
            num2arr(gap);
            s=arr2smaller(b);
            g=arr2greater(b);
            gap=g-s;
            printf("%04d - %04d = %04d\n",g,s,gap);
        }
    }
    return 0;
}

