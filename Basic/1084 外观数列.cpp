#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char d;
    scanf("%c %d",&d,&n);
    char x[100000],nextx[100000];
    memset(x,0,sizeof(x));
    memset(nextx,0,sizeof(x));
    x[0]=d;
    for(int i=1;i<n;i++){
        int len=strlen(x);
        int flag=0;
        for(int j=0;j<len;j++){
            int counter=1;
            nextx[flag++]=x[j];
            while(x[j+1]==x[j]){
                counter++;
                j++;
            }
            nextx[flag++]=counter+'0';
        }
        strcpy(x,nextx);
        memset(nextx,0,sizeof(nextx));
    }
    printf("%s\n",x);
    return 0;
}

