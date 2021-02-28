#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int c=0,n,m,tem;
    int a[100010],t[1010];
    memset(a,0,sizeof(a));
    memset(t,0,sizeof(t));
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&tem);
        if(tem>m) continue;
        else {
            a[c++]=tem;
            t[tem]++;
        }
    }
    sort(a,a+c);
    for(int i=0;i<c;i++){
        if(a[i]>m/2) {
            printf("No Solution");
        }else if(a[i]+a[i]==m&&t[a[i]]>1){
            printf("%d %d",a[i],a[i]);
            break;
        }else if(a[i]+a[i]==m&&t[a[i]]<2){
            printf("No Solution");
            break;
        }else if(t[m-a[i]]>0){
            printf("%d %d",a[i],m-a[i]);
            break;
        }
    }
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int n,m,temp,flag=0;
    map<int,int> mp;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(!mp[temp]){
            mp[temp]=1;
        }else{
            mp[temp]++;
        }

    }
    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end()&&it->first<=m/2;it++){
        int t=m-it->first;
        if(mp[t]>=1){
            if(t==it->first&&mp[t]==1){
                continue;
            }
            printf("%d %d\n",it->first,t);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("No Solution");
    }
    return 0;
}
*/

