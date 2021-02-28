#include<cstdio>
#include<algorithm>
using namespace std;
struct Mooncake {
	double store;
	double sell;
	double price;
}mooncake[1010];
struct Rule {
	bool operator()(const Mooncake & m1,const Mooncake & m2){
		return m1.price>m2.price;
	}
};

int main()
{
	int n;
	double D;
	scanf("%d %lf",&n,&D);
	for(int i=0;i<n;i++){
		scanf("%lf",&mooncake[i].store);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&mooncake[i].sell);
		mooncake[i].price=mooncake[i].sell/mooncake[i].store;
	}
	sort(mooncake,mooncake+n,Rule());
	double amount=0;
	for(int i=0;i<n;i++){
		if(mooncake[i].store<D){
			amount+=mooncake[i].sell;
			D-=mooncake[i].store;
		}
		else{
			amount+=D*mooncake[i].price;
			break;
		}
	}
	printf("%.2lf",amount);
	return 0;
}

