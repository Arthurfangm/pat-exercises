#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char str[100010];
    cin.getline(str,100010);
    int len=strlen(str);
    int sum=0;
    for(int i=0;i<len;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            sum+=str[i]-'A'+1;
        }
        else if(str[i]>='a'&&str[i]<='z'){
            sum+=str[i]-'a'+1;
        }
        else
            continue;
    }
    int counter0=0,counter1=0;
    while(sum>0){
        if(sum%2==1)
            counter1++;
        else
            counter0++;
        sum/=2;
    }
    printf("%d %d\n",counter0,counter1);
    return 0;
}

