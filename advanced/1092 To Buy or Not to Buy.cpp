#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char s1[1010],s2[1010];
    int a[150];
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(a,0,sizeof(a));
    scanf("%s %s",s1,s2);
    int l1=strlen(s1),l2=strlen(s2);
    for(int i=0;i<l1;i++)
        a[s1[i]]++;
    for(int i=0;i<l2;i++)
        a[s2[i]]--;
    int left=0,need=0;
    for(int i=0;i<150;i++){
        if(a[i]>0) left+=a[i];
        if(a[i]<0) need+=a[i];
    }
    if(need<0) printf("No %d\n",-need);
    else printf("Yes %d\n",left);
    return 0;
}

