#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Stu
{
    char name[20];
    int height;
};
struct Rule
{
    bool operator()(const Stu & s1,const Stu &s2)
    {
        if(s1.height<s2.height)
            return false;
        else if(s1.height==s2.height){
            if(strcmp(s1.name,s2.name)>0)
                return false;
        }
        return true;
    }
};
int main()
{
    Stu stu[10100];
    int N,K;
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++)
    {
        scanf("%s%d",&stu[i].name,&stu[i].height);
    }
    sort(stu,stu+N,Rule());
    int m=N/K;
    int last_row=m+N%K;
    int flag=0;
    int printed=0;
    if(last_row%2==1)
    {
        for(int i=flag+last_row-2; i>=flag+1; i-=2)
        {
            if(printed==0){
                printf("%s",stu[i].name);
                printed=1;
            }
            else{
                printf(" %s",stu[i].name);
            }
        }
        if(printed==0){
            printf("%s",stu[flag].name);
            printed=1;
        }
        else
            printf(" %s",stu[flag].name);
        for(int i=flag+2; i<flag+last_row; i+=2)
        {
            if(printed==0){
                printf("%s",stu[i].name);
                printed=1;
            }
            else{
                printf(" %s",stu[i].name);
            }
        }
        flag+=last_row;
        printf("\n");
    }
    else
    {
        for(int i=flag+last_row-1; i>=flag+1; i-=2)
        {
            if(printed==0){
                printf("%s",stu[i].name);
                printed=1;
            }
            else{
                printf(" %s",stu[i].name);
            }
        }
        if(printed==0){
            printf("%s",stu[flag].name);
            printed=1;
        }
        else
            printf(" %s",stu[flag].name);
        for(int i=flag+2; i<flag+last_row; i+=2)
        {
            if(printed==0){
                printf("%s",stu[i].name);
                printed=1;
            }
            else{
                printf(" %s",stu[i].name);
            }
        }
        flag+=last_row;
        printf("\n");
    }
    for(int g=1; g<=K-1; g++)
    {
        printed=0;
        if(m%2==1)
        {
            for(int i=flag+m-2; i>=flag+1; i-=2)
            {
                if(printed==0){
                    printf("%s",stu[i].name);
                    printed=1;
                }
                else{
                    printf(" %s",stu[i].name);
                }
            }
            if(printed==0){
                printf("%s",stu[flag].name);
                printed=1;
            }
            else
                printf(" %s",stu[flag].name);
            for(int i=flag+2; i<flag+m; i+=2)
            {
                if(printed==0){
                    printf("%s",stu[i].name);
                    printed=1;
                }
                else{
                    printf(" %s",stu[i].name);
                }
            }
            flag+=m;
            printf("\n");
        }
        else
        {
            for(int i=flag+m-1; i>=flag+1; i-=2)
            {
                if(printed==0){
                    printf("%s",stu[i].name);
                    printed=1;
                }
                else{
                    printf(" %s",stu[i].name);
                }
            }
            if(printed==0){
                printf("%s",stu[flag].name);
                printed=1;
            }
            else
                printf(" %s",stu[flag].name);
            for(int i=flag+2; i<flag+m; i+=2)
            {
                if(printed==0){
                    printf("%s",stu[i].name);
                    printed=1;
                }
                else{
                    printf(" %s",stu[i].name);
                }
            }
            flag+=m;
            printf("\n");
        }
    }
    return 0;
}

