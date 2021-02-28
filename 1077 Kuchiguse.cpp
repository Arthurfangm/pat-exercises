#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100;
int main()
{
    char str[maxn][265];
    memset(str,0,sizeof(str));
    int n;
    scanf("%d",&n);
    getchar();
    int minlen=265;
    for(int i=0;i<n;i++){
        cin.getline(str[i],265);
        if(strlen(str[i])<minlen){
            minlen=strlen(str[i]);
        }
    }
    int flag=1;
    int len=0;
    do{
        char c=str[0][strlen(str[0])-1-len];
        for(int i=1;i<n;i++){
            if(str[i][strlen(str[i])-1-len]!=c){
                flag=0;
            }
        }
        if(flag==1) len++;
    }while(flag==1&&len<minlen);
    if(len==0){
        printf("nai");
    }else{
        int l=strlen(str[0]);
        for(int i=l-len;i<l;i++){
            printf("%c",str[0][i]);
        }
    }
    return 0;
}

