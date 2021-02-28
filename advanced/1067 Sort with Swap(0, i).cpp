#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100010],c=0;
int main()
{
    scanf("%d",&n);
    int left=0;
    for(int i=0; i<n; i++)
    {
        int temp;
        scanf("%d",&temp);
        a[temp]=i;
        if(temp!=i&&temp!=0)
        {
            left++;
        }
    }
    int c=0,no=1;
    while(left>0)
    {
        if(a[0]==0)
        {
            while(no<n)
            {
                if(a[no]!=no)
                {
                    int t=a[a[no]];
                    a[a[no]]=a[0];
                    a[0]=t;
                    c++;
                    break;
                }
                no++;
            }
        }
        c++;
        left--;
        int t=a[a[0]];
        a[a[0]]=a[0];
        a[0]=t;
    }
    printf("%d",c);
    return 0;
}

