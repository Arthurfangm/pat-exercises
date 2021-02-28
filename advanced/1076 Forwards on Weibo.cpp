#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int id;
	int layer;
};
int n;
int l;
int b;
int g[1010][1010] = {0};
int query[1010];
int count = 0;
bool visited[1010] = {false};
queue<Node> qu;
Node tmpNode;
int nowVisit;
int nowLayer;

void BFS() {
	while(!qu.empty()) {
		if(qu.front().layer==l){
			while(!qu.empty()) {
				qu.pop();
				count++;
			}
		} else {
			nowVisit = qu.front().id;
			nowLayer = qu.front().layer;
			for(int i=1; i<=n; i++) {
				if(!visited[i] && g[nowVisit][i]==1) {
					tmpNode.id = i;
					tmpNode.layer = nowLayer + 1;
					qu.push(tmpNode);
					visited[i] = true;
				}
			}
			count++;
			qu.pop();
		}
	}
}

int main()
{
	int tmp;
	scanf("%d %d", &n, &l);
	for(int i=1; i<=n; i++) {
		scanf("%d", &tmp);
		for(int j=1; j<=tmp; j++) {
			scanf("%d", &b);
			g[b][i] = 1;
		}
	}
	scanf("%d", &tmp);
	for(int i=0; i<tmp; i++)
		scanf("%d", &query[i]);
	for(int i=0; i<tmp; i++) {
		count = 0;
		for(int i=1; i<=n; i++)
			visited[i] = false;
		while(!qu.empty())
			qu.pop();
		tmpNode.id = query[i];
		tmpNode.layer = 0;
		visited[query[i]] = true;
		qu.push(tmpNode);
		BFS();
		cout << count-1 <<endl;
	}
	return 0;
}
