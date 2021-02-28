#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Stu {
    char name[11];
    char gender;
    char id[11];
    int grade;
    Stu(){
        memset(name,0,sizeof(name));
        gender=0;
        memset(name,0,sizeof(name));
        grade=-1;
    }
}min_m,max_f,temp;
int main()
{
    min_m.grade=101;
    int exist_m=0,exist_f=0,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %c %s %d",temp.name,&temp.gender,temp.id,
              &temp.grade);
        if(temp.gender=='M'){
            exist_m++;
            if(temp.grade<min_m.grade){
                strcpy(min_m.name,temp.name);
                strcpy(min_m.id,temp.id);
                min_m.grade=temp.grade;
            }
        }else{
            exist_f++;
            if(temp.grade>max_f.grade){
                strcpy(max_f.name,temp.name);
                strcpy(max_f.id,temp.id);
                max_f.grade=temp.grade;
            }
        }
    }
    if(exist_f==0){
        printf("Absent\n");
    }else{
        printf("%s %s\n",max_f.name,max_f.id);
    }
    if(exist_m==0){
        printf("Absent\n");
    }else{
        printf("%s %s\n",min_m.name,min_m.id);
    }
    if(!exist_f||!exist_m){
        printf("NA");
    }else{
        printf("%d",max_f.grade-min_m.grade);
    }
    return 0;
}

