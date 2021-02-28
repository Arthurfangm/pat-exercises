#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char r[3];
int len;
void f(int x){
    len=0;
    memset(r,0,sizeof(r));
    while(x!=0){
        int temp=x%13;
        if(0<=temp&&temp<=9){
            r[len++]='0'+temp;
        }else if(temp==10){
            r[len++]='A';
        }else if(temp==11){
            r[len++]='B';
        }else{
            r[len++]='C';
        }
        x/=13;
    }
    if(strlen(r)==1){
        printf("0%c",r[0]);
    }else if(strlen(r)==0){
        printf("00");
    }else{
        printf("%c%c",r[1],r[0]);
    }
}
int main()
{
    int a,b,c,len=0;

    scanf("%d %d %d",&a,&b,&c);
    printf("#");
    f(a);
    f(b);
    f(c);
    return 0;
}

