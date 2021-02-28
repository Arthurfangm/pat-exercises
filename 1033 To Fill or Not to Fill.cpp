#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Station {
    double p;
    double d;
}sta[510];
struct Rule {
    bool operator()(const Station & a,const Station & b){
        return a.d<b.d;
    }
};
int N;
double Cmax,D,Davg;
double cover_d,maxd=0.0,cost=0.0,Cnow=0.0;
int now;
int main()
{
    scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&N);
    cover_d=Cmax*Davg;
    for(int i=0;i<N;i++){
        scanf("%lf %lf",&sta[i].p,&sta[i].d);
    }
    sort(sta,sta+N,Rule());
    if(sta[0].d!=0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }else {
        while(maxd<D){
            double next_price=100000000;
            int next_sta=-1;
            for(int no=now+1;no<N&&sta[no].d-sta[now].d<=cover_d&&sta[no].d<D;no++){
                if(sta[no].p<next_price){
                    next_sta=no;
                    next_price=sta[no].p;
                    if(sta[no].p<sta[now].p){
                        break;
                    }
                }
            }
            if(next_sta==-1||(sta[now].d+cover_d>=D&&sta[now].p<next_price)){
                if(sta[now].d+cover_d>=D){
                    if((D-sta[now].d)/Davg-Cnow>0)
                    cost+=((D-sta[now].d)/Davg-Cnow)*sta[now].p;
                    printf("%.2f",cost);
                }else{
                    printf("The maximum travel distance = %.2f",sta[now].d+=cover_d);
                }
                break;
            }else{
                if(next_price<sta[now].p){
                    if((sta[next_sta].d-sta[now].d)/Davg-Cnow>0){
                        cost+=((sta[next_sta].d-sta[now].d)/Davg-Cnow)*sta[now].p;
                        Cnow+=((sta[next_sta].d-sta[now].d)/Davg-Cnow);
                    }
                }else{
                    cost+=(Cmax-Cnow)*sta[now].p;
                    Cnow=Cmax;
                }
                Cnow-=((sta[next_sta].d-sta[now].d)/Davg);
                now=next_sta;
                maxd=sta[next_sta].d;
            }
        }
    }
    return 0;
}

