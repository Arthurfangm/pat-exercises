#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1010;
int main()
{
    int n,flag_total=0;
    char id[maxn][15];
    char pw[maxn][15];
    int note[maxn];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %s",id[i],pw[i]);
        int flag_single=0;
        int len=strlen(pw[i]);
        for(int j=0;j<len;j++){
            if(pw[i][j]=='1'){
                pw[i][j]='@';
                flag_single=1;
            }
            if(pw[i][j]=='l'){
                pw[i][j]='L';
                flag_single=1;
            }
            if(pw[i][j]=='0'){
                pw[i][j]='%';
                flag_single=1;
            }
            if(pw[i][j]=='O'){
                pw[i][j]='o';
                flag_single=1;
            }
        }
        if(flag_single==1){
            note[flag_total++]=i;
        }
    }
    if(flag_total==0){
        if(n==1)
            printf("There is %d account and no account is modified\n",n);
        else
            printf("There are %d accounts and no account is modified\n",n);
    }else{
        printf("%d\n",flag_total);
        for(int i=0;i<flag_total;i++){
            printf("%s %s\n",id[note[i]],pw[note[i]]);
        }
    }
    return 0;
}

