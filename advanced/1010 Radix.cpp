#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    char a[11],b[11];
    long long tag,redix;
    scanf("%s %s %d %d",a,b,&tag,&redix);
    int table[128];
    for(char c='0';c<='9';c++){
        table[c]=c-'0';
    }
    for(char c='a';c<='z';c++){
        table[c]=c-'a'+10;
    }
    if(tag==2){
        char c[11];
        strcpy(c,a);
        strcpy(a,b);
        strcpy(b,c);
    }
    long long n1=0;
    long long lena=strlen(a);
    for(int i=0;i<lena;i++){
        n1=n1*redix+table[a[i]];
    }
    long long lenb=strlen(b);
    long long mi=-1;
    for(int i=0;i<lenb;i++){
        if(table[b[i]]>mi){
            mi=table[b[i]];
        }
    }
    mi++;
    long long ma=max(n1,mi)+1;
    long long mid;
    int flag=0;
    while(mi<=ma){
        mid=mi+(ma-mi)/2;
        long long n2=0;
        for(int i=0;i<lenb;i++){
            n2=n2*mid+table[b[i]];
            if(n2<0||n2>n1){
                break;
            }
        }
        if(n2<0||n2>n1){
            ma=mid-1;
        }else if(n2<n1){
            mi=mid+1;
        }else{
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("%lld",mid);
    }else{
        printf("Impossible");
    }
    return 0;
}

