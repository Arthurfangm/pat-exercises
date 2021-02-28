#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
struct Grades{
    char id[25];
    int code=-1;
    int mid_term=-1;
    int final_=-1;
    int g;
}grades[30030];
char tmp[25],mark;
int exist(int len)
{
    for(int i=1;i<=len;i++){
        if(strcmp(grades[i].id,tmp)==0)
            return i;
    }
    return 0;
}
struct Rule{
    bool operator()(const Grades & g1,const Grades & g2){
        if(g1.g>g2.g) return 1;
        else if(g1.g==g2.g){
            if(strcmp(g1.id,g2.id)<0)
                return 1;
            else return 0;
        }
        else
            return 0;
    }
};
int main()
{
    map<string,int> mp;
    int p,m,n;
    scanf("%d %d %d",&p,&m,&n);
    getchar();
    int counter=p;
    for(int i=1;i<=p;i++){
        scanf("%s %d",&grades[i].id,&grades[i].code);
        mp[grades[i].id]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%s %d",tmp,&mark);
        if(!mp[tmp]){
            mp[tmp]=++counter;
            strcpy(grades[counter].id,tmp);
            grades[counter].mid_term=mark;
        }
        else{
            grades[mp[tmp]].mid_term=mark;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%s %d",tmp,&mark);
        if(!mp[tmp]){
            mp[tmp]=++counter;
            strcpy(grades[counter].id,tmp);
            grades[counter].final_=mark;
        }
        else{
            grades[mp[tmp]].final_=mark;
        }
    }

    for(int i=1;i<=counter;i++){
        if(grades[i].code<200){
            grades[i].g=-1;
        }
        else{
            if(grades[i].mid_term>grades[i].final_){
                float a=0.5+1.0*grades[i].mid_term*0.4+1.0*grades[i].final_*0.6;
                grades[i].g=(int)a;
            }
            else{
                grades[i].g=grades[i].final_;
            }
        }
    }
    sort(grades+1,grades+counter+1,Rule());
    for(int i=1;i<=counter;i++){
        if(grades[i].g>=60)
            printf("%s %d %d %d %d\n",grades[i].id,grades[i].code,grades[i].mid_term,grades[i].final_,grades[i].g);
    }
    return 0;
}

