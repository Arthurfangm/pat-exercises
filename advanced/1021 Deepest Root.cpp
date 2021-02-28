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
vector<int> path;
set<int> maxPath;

void DFS(int nowVisit) {
	visited[nowVisit] = true;
	path.push_back(nowVisit);
	if(path.size() == maxWeight) {
		for(int j=0; j<path.size(); j++) {
			maxPath.insert(path[j]);
		}
	}
	for(int i=0; i<G[nowVisit].size(); i++) {
		if(!visited[G[nowVisit][i]]) {
			DFS(G[nowVisit][i]);
		}
	}
	path.pop_back();
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
		for(int j=1;j<=n;j++)
			visited[j] = false;
		DFS(i);
	}
}

int main()
{
	scanf("%d", &n);
	if(n==1) {
		cout << 1 <<endl;
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
		set<int>::iterator it;
		for(it=maxPath.begin(); it!=maxPath.end(); it++) 
			onMaxPath[*it] = 1;
		for(int i=1; i<=n; i++) {
			if(weight[i] == 1 && onMaxPath[i] == 1)
				printf("%d\n", i);
		}
	}
	return 0;
} 
