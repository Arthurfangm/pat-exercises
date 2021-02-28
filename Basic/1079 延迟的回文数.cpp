#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[1100];
int isPalindromic(char s[])
{
    int l=strlen(str);
    int ll=l/2;
    for(int i=0;i<ll;i++){
        if(s[i]!=s[l-1-i])
            return 0;
    }
    return 1;
}
char add()
{
    printf("%s + ",str);
    char str_re[1100];
    strcpy(str_re,str);
    int len=strlen(str);
    reverse(str_re,str_re+len);
    printf("%s = ",str_re);
    int carry=0;
    for(int i=0;i<len;i++){
        char stri=str[i];
    	str[i]=(str[i]-'0'+str_re[i]-'0'+carry)%10+'0';
        carry=(stri-'0'+str_re[i]-'0'+carry)/10;
    }
    if(carry!=0){
        str[len]=carry+'0';
        len++;
    }
    reverse(str,str+len);
    printf("%s\n",str);
}
int main()
{
    cin.getline(str,1100);
    int i=0;
    for(i=0;i<10;i++){
        if(isPalindromic(str)){
            printf("%s is a palindromic number.\n",str);
            break;
        }
        else{
            add();
        }
    }
    if(i==10){
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}

