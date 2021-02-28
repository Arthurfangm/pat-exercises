#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int m[10000][10000];
int main()
{
    int n;
    int a[100100];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());
    int min=0x3f3f3f3f;
    int p=0,q=0;
    for(int i=1; i<=n; i++)
    {
        if(n%i==0&&n/i>=i)
        {
            if(n/i-i<min)
            {
                min=n/i-i;
                p=i;
                q=n/i;
            }
        }
    }
    int c=0;
    int m[100][100];
    if(q==n)
    {
        for(int i=0;i<n;i++)
            printf("%d\n",a[i]);
    }
    else
    {
        int left=0,right=p,top=0,bottom=q;
        while(c<n)
        {
            for(int i=left; i<right; i++)
            {
                m[top][i]=a[c++];
                if(c==n)
                    break;
            }
            if(c==n)
                break;
            top++;
            for(int i=top; i<bottom; i++)
            {
                m[i][right-1]=a[c++];
                if(c==n)
                    break;
            }
            if(c==n)
                break;
            right--;
            for(int i=right-1; i>left-1; i--)
            {
                m[bottom-1][i]=a[c++];
                if(c==n)
                    break;
            }
            if(c==n)
                break;
            bottom--;
            for(int i=bottom-1; i>top-1; i--)
            {
                m[i][left]=a[c++];
                if(c==n)
                    break;
            }
            if(c==n)
                break;
            left++;
        }
        for(int i=0; i<q; i++)
        {
            for(int j=0; j<p; j++)
            {
                if(j!=0)
                    printf(" ");
                printf("%d",m[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

