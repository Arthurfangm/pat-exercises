#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char sign;
    char str[1010];
    scanf("%c",&sign);
    getchar();
    cin.getline(str,1010);
    int l=strlen(str);
    int counter;
    int counter2;
    if(sign=='C'){
        for(int i=0;i<l;i++){
            counter=1;
            while(str[i+1]==str[i]){
                i++;
                counter++;
            }
            if(counter!=1){
                printf("%d",counter);
            }
            printf("%c",str[i]);
        }
        printf("\n");
    }
    else{
        for(int i=0;i<l;i++){
            counter=1;
            if(str[i]>='1'&&str[i]<='9'){
                counter=str[i]-'0';
                i++;
                while(str[i]>='0'&&str[i]<='9'){
                    counter=10*counter+str[i]-'0';
                    i++;
                }
                while(counter--){
                    printf("%c",str[i]);
                }
            }
            else{
                printf("%c",str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

