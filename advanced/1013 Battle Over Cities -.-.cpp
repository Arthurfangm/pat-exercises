#include <iostream>
using namespace std;
int n;
int m;
int k;
int g[1010][1010] = {0};
int query[1010] = {0};

bool visited[1010] = {false};
int count;
int broken;
void DFS(int nowVisit) {
	visited[nowVisit] = true;
	for(int i=1; i<=n; i++) {
		if(visited[i]==false && i!=broken && g[nowVisit][i]==1) {
			DFS(i);
		}
	}
}
void DFSTravel() {
	for(int i=1; i<=n; i++) {
		if(visited[i]==false && i!=broken) {
			count ++;
			DFS(i);
		}
	} 
}
int main()
{
	int x;
	int y;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		g[x][y] = g[y][x] = 1;
	}
	for(int i=0; i<k; i++)
		scanf("%d", &query[i]);
	for(int i=0; i<k; i++) {
		for(int i=1; i<=n; i++) 
			visited[i] = false;
		count = 0;
		broken = query[i];
		DFSTravel();
		cout << count-1 << endl;
	}
	return 0;
}
