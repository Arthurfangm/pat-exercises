#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;
struct Customer {
	int arriveTime;
	int operateTime;
};
struct Window {
	int finishTime;
};
struct RuleC {
	bool operator()(const Customer & c1, const Customer & c2) const {
		return c1.arriveTime < c2.arriveTime;
	}
};
struct RuleW {
	bool operator()(const Window & w1, const Window & w2) const {
		return w1.finishTime < w2.finishTime;
	}
};
int main()
{
	int n;
	int k;
	int count = 0;
	int ans = 0;
	multiset<Customer,RuleC> cuSet;
	multiset<Window,RuleW> wiSet;
	Customer tmpC;
	Window tmpW;
	scanf("%d %d",&n, &k);
	for(int i=0; i<k; i++){
		tmpW.finishTime = 8*3600;
		wiSet.insert(tmpW);
	}
	int t1,t2,t3,t4;
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&t1,&t2,&t3,&t4);
		if(t4>60) t4 = 60;
		if(t1*3600+t2*60+t3>17*3600)
			continue;
		else {
			count++;
			tmpC.arriveTime = t1*3600+t2*60+t3;
			tmpC.operateTime = t4*60;
			cuSet.insert(tmpC);
		}
	}
	multiset<Customer,RuleC>::iterator cuIt;
	for(cuIt = cuSet.begin();cuIt != cuSet.end(); cuIt++){
		multiset<Window,RuleW>::iterator wiIt;
		wiIt = wiSet.begin();
		int t = wiIt->finishTime;
		if(cuIt->arriveTime<=t){
			ans += t - cuIt->arriveTime;
			t = t + cuIt->operateTime;
		}
		else {
			t = cuIt->arriveTime + cuIt->operateTime;
		}
		wiSet.erase(wiIt);
		tmpW.finishTime = t;
		wiSet.insert(tmpW);
	}
	printf("%.1f",(float)ans/(float)count/60.0);
	return 0;
 } 
