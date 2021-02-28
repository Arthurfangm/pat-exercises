#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    char A[110],B[110];
    scanf("%s%s",A,B);
    int l1=strlen(A),l2=strlen(B);
    int a[110],b[110];
    for(int i=0; i<l1; i++)
        a[i]=A[i]-'0';
    for(int i=0; i<l2; i++)
        b[i]=B[i]-'0';
    int d=0;
    int flag=0;
    d=l2-l1;
    if(d>0)
    {
        for(int i=0; i<d; i++)
        {
            printf("%d",b[i]);
            flag=1;
        }
    }
    int num=0;
    if(d<0)
    {
        int dd=-d;
        for(int i=0; i<dd; i++)
        {
            if((l1-i)%2==0)
            {
                num=((0-a[i])>=0)?0-a[i]:10-a[i];
            }
            else
            {
                num=a[i];
            }
            if((num==0&&flag==1)||(flag==0&&l2-1==i&&num==0))
                printf("%d",num);
            if(0<num&&num<=9)
            {
                printf("%d",num);
                flag=1;
            }
            if(num==10)
            {
                printf("J");
                flag=1;
            }
            if(num==11)
            {
                printf("Q");
                flag=1;
            }
            if(num==12)
            {
                printf("K");
                flag=1;
            }
        }
    }
    for(int i=(d>0)?d:0; i<l2; i++)
    {
        if((l2-i)%2==1)
        {
            num=(b[i]+a[i-d])%13;
        }
        else
        {
            num=b[i]-a[i-d];
            if(num<0)
                num+=10;
        }
        if((num==0&&flag==1)||(flag==0&&l2-1==i&&num==0))
            printf("%d",num);
        if(0<num&&num<=9)
        {
            printf("%d",num);
            flag=1;
        }
        if(num==10)
        {
            printf("J");
            flag=1;
        }
        if(num==11)
        {
            printf("Q");
            flag=1;
        }
        if(num==12)
        {
            printf("K");
            flag=1;
        }
    }
    printf("\n");
    return 0;
}

