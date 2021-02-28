#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    string str[10010];
    int a[10010];
    int b[1010];
    memset(b,0,sizeof(b));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str[i]>>a[i];
        int f=0;
        f=str[i].find('-');
        string sub=str[i].substr(0,f);
        b[stoi(sub)]+=a[i];
    }
    int max=0;
    int id=0;
    for(int i=0;i<1000;i++){
        if(b[i]>max){
            max=b[i];
            id=i;
        }
    }
    printf("%d %d",id,max);
    return 0;
}

