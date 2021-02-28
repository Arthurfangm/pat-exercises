#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
struct Car {
    char id[20];
    int in,out,stay;
    Car(){
        in=-1,out=-1,stay=0;
    }
}car[10110];
struct Record {
    char id[20],state[10];
    int hh,mm,ss;
    Record(){
        memset(id,0,sizeof(id));
        memset(state,0,sizeof(state));
        hh=-1,mm=-1,ss=-1;
    }
}records[10110];
struct Rule {
    bool operator()(const Record & r1,const Record & r2){
        if(strcmp(r1.id,r2.id)!=0) return strcmp(r1.id,r2.id)<0;
        else if(r1.hh!=r2.hh) return r1.hh<r2.hh;
        else if(r1.mm!=r2.mm) return r1.mm<r2.mm;
        else return r1.ss<r2.ss;
    }
};
struct Rule2 {
    bool operator()(const Car & c1,const Car & c2){
        return c1.in<c2.in;
    }
};
struct Rule3 {
    bool operator()(const string & s1,const string &s2){
        return s1<s2;
    }
};
int main()
{
    int n,k,maxx=0,hh,mm,ss,t;
    vector<char*> vi;
    map<string,int> mp;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%s %d:%d:%d %s",records[i].id,&records[i].hh,
                               &records[i].mm,&records[i].ss,records[i].state);
    int c=0;
    sort(records,records+n,Rule());
    for(int i=1;i<n;i++) {
        if(strcmp(records[i].state,"out")==0&&strcmp(records[i-1].state,"in")==0&&
        strcmp(records[i].id,records[i-1].id)==0){
            strcpy(car[c].id,records[i].id);
            car[c].in=3600*records[i-1].hh+60*records[i-1].mm+records[i-1].ss;
            car[c].out=3600*records[i].hh+60*records[i].mm+records[i].ss;
            car[c].stay=car[c].out-car[c].in;
            mp[car[c].id]+=car[c].stay;
            if(mp[car[c].id]>maxx){
                maxx=mp[car[c].id];
                vi.clear();
                vi.push_back(car[c].id);
            }else if(mp[car[c].id]==maxx){
                vi.push_back(car[c].id);
            }
            c++;
        }
        //for(vector<char*>::iterator it=vi.begin();it!=vi.end();it++) printf("%s ",*it);
        //printf("\n");
    }
    sort(vi.begin(),vi.end(),Rule3());
    string s[10010];
    int ccc=0;
    for(vector<char*>::iterator it=vi.begin();it!=vi.end();it++){
        s[ccc++]=*it;
    }
    sort(car,car+c,Rule2());
    for(int i=0;i<k;i++){
        int co=0;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        t=3600*hh+60*mm+ss;
        for(int j=0;j<k;j++){
            if(t>=car[j].in&&t<car[j].out) {
                co++;
            }
        }
        printf("%d\n",co);
    }
    for(int i=0;i<ccc;i++) printf("%s ",s[i].c_str());
    printf("%02d:%02d:%02d",maxx/3600,maxx%3600/60,maxx%60);
    return 0;
}

