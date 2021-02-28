#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    string tem,str1,str2;
    int t[25],s1[25],s2[25],r[25];
    memset(t,0,sizeof(t));
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(r,0,sizeof(r));
    cin>>tem>>str1>>str2;
    reverse(tem.begin(),tem.end());
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int l_tem=tem.length(),l_str1=str1.length(),l_str2=str2.length();
    int l_str=(l_str1>=l_str2)?l_str1:l_str2;
    for(int i=0;i<l_tem;i++){
        t[i]=tem[i]-'0';
        if(t[i]==0)
            t[i]=10;
    }
    for(int i=0;i<l_str1;i++)
        s1[i]=str1[i]-'0';
    for(int i=0;i<l_str2;i++)
        s2[i]=str2[i]-'0';
    for(int i=0;i<l_str;i++){
        r[i+1]=(s1[i]+s2[i]+r[i])/t[i];
        r[i]=(s1[i]+s2[i]+r[i])%t[i];
    }
    int flag=0;
    for(int i=24;i>-1;i--){
        if(r[i]!=0){
            flag=1;
        }
        if(flag==0){
            continue;
        }
        if(flag==1){
            printf("%d",r[i]);
        }
    }
    if(flag==0)
        printf("0");
    printf("\n");
    return 0;
}

