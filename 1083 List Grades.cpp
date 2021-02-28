#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Stu {
    char name[20];
    char id[20];
    int grade;
    int flag;
    Stu() {
        memset(name,0,sizeof(name));
        memset(id,0,sizeof(id));
        grade=0;
        flag=0;
    }
}stu[100];
struct Rule {
    bool operator()(const Stu & s1,const Stu & s2){
        if(s1.flag!=s2.flag) return s1.flag>s2.flag;
        else return s1.grade>s2.grade;
    }
};
int main()
{
    int n,low,high;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
    scanf("%d %d",&low,&high);
    int sign=0;
    for(int i=0;i<n;i++)
        if(low<=stu[i].grade&&stu[i].grade<=high) stu[i].flag=1,sign++;
    if(sign==0) printf("NONE\n");
    else {
        sort(stu,stu+n,Rule());
        for(int i=0;i<sign;i++) printf("%s %s\n",stu[i].name,stu[i].id);
    }
    return 0;
}

