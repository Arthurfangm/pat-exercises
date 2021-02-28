#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    char max_id[5],min_id[5],tmp[5];
    int n;
    float max_=-1.0,min_=101.0,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %f %f",tmp,&x,&y);
        float a=sqrt(x*x+y*y);
        if(a>max_){
            max_=a;
            strcpy(max_id,tmp);
        }
        if(a<min_){
            min_=a;
            strcpy(min_id,tmp);
        }
    }
    printf("%s %s\n",min_id,max_id);
    return 0;
}

