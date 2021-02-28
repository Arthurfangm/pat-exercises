#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    char s1[100],s2[100];
    scanf("%s %s",s1,s2);
    int l1=strlen(s1),l2=strlen(s2);
    int t[100];
    memset(t,0,sizeof(t));
    for(int i=0;i<l1;i++) {
        if('a'<=s1[i]&&s1[i]<='z') s1[i]=toupper(s1[i]);
        t[s1[i]]=1;
    }
    for(int i=0;i<l2;i++) {
        if('a'<=s2[i]&&s2[i]<='z') s2[i]=toupper(s2[i]);
        t[s2[i]]=0;
    }
    for(int i=0;i<l1;i++) {
        if(t[s1[i]]==1) {
            if(s1[i]=='_') printf("_");
            else if('0'<=s1[i]&&s1[i]<='9') printf("%c",s1[i]);
            else printf("%c",s1[i]);
            t[s1[i]]=0;
        }
    }
    return 0;
}

