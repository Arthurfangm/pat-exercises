#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Stu {
    int id;
    int ge,gi;
    float g;
    int opt[110];
}stu[40010];
struct Sch {
    int num;
    int admittded[40010];
    int admit;
}sch[110];
struct Rule {
    bool operator()(const Stu & s1,const Stu & s2){
        if(s1.g!=s2.g) return s1.g>s2.g;
        else return s1.ge>s2.ge;
    }
};
int f(int a[],int b[],int k)
{
    for(int i=0;i<k;i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++) scanf("%d",&sch[i].admit);
    for(int i=0;i<n;i++){
        stu[i].id=i;
        scanf("%d %d",&stu[i].ge,&stu[i].gi);
        stu[i].g=(stu[i].ge+stu[i].gi)/2.0;
        for(int j=0;j<k;j++) scanf("%d",&stu[i].opt[j]);
    }
    sort(stu,stu+n,Rule());
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++){
            if(sch[stu[i].opt[j]].admit>0){
                sch[stu[i].opt[j]].admit--;
                sch[stu[i].opt[j]].admittded[sch[stu[i].opt[j]].num++]=stu[i].id;
                while(stu[i+1].g==stu[i].g&&stu[i+1].ge==stu[i+1].ge&&i+1<n&&f(stu[i].opt,stu[i+1].opt,k)){
                    i++;
                    sch[stu[i].opt[j]].admit--;
                    sch[stu[i].opt[j]].admittded[sch[stu[i].opt[j]].num++]=stu[i].id;
                }
                break;
            }
        }
    }
    for(int i=0;i<m;i++) sort(sch[i].admittded,sch[i].admittded+sch[i].num);
    for(int i=0;i<m;i++){
        if(sch[i].num==0) printf("\n");
        else if(sch[i].num==1) printf("%d\n",sch[i].admittded[0]);
        else{
            printf("%d",sch[i].admittded[0]);
            for(int j=1;j<sch[i].num;j++){
                printf(" %d",sch[i].admittded[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
