#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    map<int,int> mp;
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        int id=abs(x-i);
        if(!mp[id])
            mp[id]=1;
        else
            mp[id]++;
    }
    map<int,int>::reverse_iterator it;
    for(it=mp.rbegin();it!=mp.rend();it++){
        if(it->second==1)
            continue;
        printf("%d %d\n",it->first,it->second);
    }
    return 0;
}

