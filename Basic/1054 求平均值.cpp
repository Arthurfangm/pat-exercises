#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int isLegal(char s[])
{
    int len=strlen(s);
    int c=0;
    for(int i=0;i<len;i++){
        if(('9'<s[i]||s[i]<'0')&&s[i]!='.'&&s[i]!='-'){
            return 0;
        }
        else if(s[i]=='-'&&i!=0){
            return 0;
        }
        else if(s[i]=='-'&&len==1){
            return 0;
        }

        else if(s[i]=='.'){
            c++;
            if(c>1)
                return 0;
            else{
                if(len-i>3)
                    return 0;
            }
        }
    }
    return 1;
}
void illegalToPrint(char s[]){
    printf("ERROR: %s is not a legal number\n",s);
}
int main()
{
    int N;
    int x=0;
    char X[100];
    float sum,y;
    int counter=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",X);
        if(isLegal(X)==0){
            illegalToPrint(X);
        }
        else{
            float f=atof(X);
            if(f>1000||f<-1000){
                illegalToPrint(X);
            }
            else{
                sum+=f;
                x++;
            }
        }
    }
    if(x==0){
        printf("The average of 0 numbers is Undefined\n");
    }
    else if(x==1){
        printf("The average of %d number is %.2f\n",x,sum/(1.0*x));
    }
    else{
        printf("The average of %d numbers is %.2f\n",x,sum/(1.0*x));
    }
    return 0;
}

