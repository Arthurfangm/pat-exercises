#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int existsNum(char str[])
{
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            return 1;
        }
    }
    return 0;
}
int existsLetter(char str[])
{
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]>='a'&&str[i]<='z'){
            return 1;
        }
    }
    return 0;
}
int main()
{
    int N;
    scanf("%d",&N);
    getchar();
    char str[100];
    for(int j=0;j<N;j++)
    {
        cin.getline(str,100);
        int l=strlen(str);
        if(l<6){
            printf("Your password is tai duan le.\n");
        }
        else{
            int sign_num=0,sign_letter=0,sign_illegal=0;
            for(int i=0;i<l;i++){
                if(str[i]>='0'&&str[i]<='9'){
                    sign_num=1;
                }
                else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
                    sign_letter=1;
                }
                else{
                    if(str[i]!='.'){
                        sign_illegal=1;
                    }
                }
            }
            if(sign_illegal==1){
                printf("Your password is tai luan le.\n");
            }
            if(sign_letter==0){
                printf("Your password needs zi mu.\n");
            }
            if(sign_num==0){
                printf("Your password needs shu zi.\n");
            }
            if(sign_illegal==0&&sign_letter==1&&sign_num==1){
                printf("Your password is wan mei.\n");
            }
        }
    }
    return 0;
}

