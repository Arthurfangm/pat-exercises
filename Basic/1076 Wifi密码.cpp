#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int N;
    char str[20];
    int a[110];
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        cin.getline(str,20);
        int len=strlen(str);
        for(int j=0;j<len;j++){
            if(str[j]=='T'){
                switch(str[j-2])
                {
                    case 'A':a[i]=1;break;
                    case 'B':a[i]=2;break;
                    case 'C':a[i]=3;break;
                    case 'D':a[i]=4;break;
                }
            }
        }
    }
    for(int i=0;i<N;i++)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}

