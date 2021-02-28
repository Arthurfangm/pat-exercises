#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char a[10010],b[10010];
    int t[200];
    memset(t,0,sizeof(t));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin.getline(a,10010);
    cin.getline(b,10010);
    int la=strlen(a),lb=strlen(b);
    for(int i=0;i<lb;i++)
        t[b[i]]=1;
    for(int i=0;i<la;i++)
        if(t[a[i]]==0) printf("%c",a[i]);
    return 0;
}

