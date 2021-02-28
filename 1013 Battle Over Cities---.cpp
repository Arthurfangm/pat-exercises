#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1111;
vector<int> G[N];
bool vis[N];
int currentPoint;

void DFS(int v) {
	if(v == currentPoint) return;
	vis[v] = true;
	for(int i=0; i<G[N].size(); i++) {
		if(vis[G[v][i]] == false) {
			DFS(G[v][i]);
		}
	}
}

int n;
int m;
int k;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0; i<m; i++) {
		int a;
		int b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int query=0; query<k; query++) {
		scanf("%d", &currentPoint);
		memset(vis, false, sizeof(vis));
		int block = 0;
		for(int i=1; i<=n; i++) {
			if(i!=currentPoint && vis[i]==false) {
				DFS(i);
				block ++;
			}
		}
		printf("%d\n", block-1);
	}
	return 0;
}
