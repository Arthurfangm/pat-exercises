#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n;
vector<int> G[10010];
int weight[10010] = {0};
int maxWeight;
int onMaxPath[10010] = {0};
bool visited[10010] = {false};
int region = 0;
set<int> maxPath;
int depth;
bool judge;

void DFS(int nowVisit) {
	visited[nowVisit] = true;
	depth ++;
	if(depth == maxWeight) {
		judge = true;
		return;
	}
	for(int i=0; i<G[nowVisit].size(); i++) {
		if(!visited[G[nowVisit][i]]) {
			DFS(G[nowVisit][i]);
		}
	}
	depth --;
}

void DFSTravel_1() {
	for(int i=1; i<=n; i++) {
		if(!visited[i])
			region++;
			DFS(i);
	}
}

void DFSTravel_2() {
	for(int i=1; i<=n; i++){
		depth = 0;
		judge = false;
		for(int j=1;j<=n;j++)
			visited[j] = false;
		DFS(i);
		if(judge = true) {
			cout << i <<endl;
		}
	}
}

int main()
{
	scanf("%d", &n);
	if(n==1) {
		cout << 1 <<endl;
		return 0;
	}
	for(int i=1; i<n; i++) {
		int x;
		int y;
		scanf("%d %d",&x,&y);
		weight[x] ++;
		weight[y] ++;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	maxWeight = n;
	for(int i=1; i<=n; i++) {
		if(weight[i] > 2) {
			maxWeight -= (weight[i]-2);
		}
	}
	
	DFSTravel_1();
	if(region != 1) {
		printf("Error: %d components", region);
	} else {
		DFSTravel_2();
	}
	return 0;
} 
