#include <algorithm>
#include <cstdio>
#include <cstring>

struct Record {
    char name[25];
    int month,day,hour,minute;
    int flag;
}records[1010];
struct Rule {
    bool operator()(const Record & r1,const Record & r2){
        if(!(strcmp(r1.name,r2.name)==0)) return strcmp(r1.name,r2.name)<0;
        else if(r1.month!=r2.month) return r1.month<r2.month;
        else if(r1.day!=r2.day) return r1.day<r2.day;
        else if(r1.hour!=r2.hour) return r1.hour<r2.hour;
        else return r1.minute<r2.minute;
    }
};
int payment[25];
int co=0;
int f(int day1,int hour1,int minute1,int day2,int hour2,int minute2){
    int cents=0;
    while(day1!=day2||hour1!=hour2||minute1!=minute2){
        co++;
        minute1++;
        cents+=payment[hour1];
        if(minute1==60){
            minute1=0;
            hour1++;
            if(hour1==24){
                hour1=0;
                day1++;
            }
        }
    }
    return cents;
}
int main()
{
    int n;
    for(int i=0;i<24;i++) scanf("%d",&payment[i]);
    scanf("%d",&n);
    char flag[10];
    for(int i=0;i<n;i++){
        scanf("%s %d:%d:%d:%d %s",records[i].name,&records[i].month,
              &records[i].day,&records[i].hour,&records[i].minute,flag);
        if(strlen(flag)==8) records[i].flag=-1;
        else records[i].flag=1;
    }
    std::sort(records,records+n,Rule());
    for(int i=1;i<n;i++){
        int printed=0;
        int sum=0;
        while(strcmp(records[i].name,records[i-1].name)==0){
            if(records[i].flag==-1&&records[i-1].flag==1){
                co=0;
                if(printed==0){
                    printf("%s %02d\n",records[i].name,records[i].month);
                    printed=1;
                }
                int cents=f(records[i-1].day,records[i-1].hour,records[i-1].minute,
                       records[i].day,records[i].hour,records[i].minute);
                sum+=cents;
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",records[i-1].day,
                       records[i-1].hour,records[i-1].minute,records[i].day,
                       records[i].hour,records[i].minute, co, cents/100.0);
            }
            i++;
        }
        if(printed==1) {
            printf("Total amount: $%.2f\n",sum/100.0);
        }
    }
    return 0;
}

