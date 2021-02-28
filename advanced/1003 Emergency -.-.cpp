#include <iostream>
#include <algorithm>
using namespace std;
int n;
int m;
int c1;
int c2;
const int maxN = 510;
int INF = 0x3fffffff;
int numOfTeam[maxN] = {0};
bool visited[maxN] = {false};
int numOfPath[maxN] = {0};
int g[maxN][maxN] = {0};
int d[maxN] = {0};
int w[maxN] = {0};

void Dijkstra(int s) {
	fill(d, d+maxN, INF);
	d[s] = 0;
	numOfPath[s] = 1;
	w[s] = numOfTeam[s];
	for(int i=0; i<n; i++) {
		int MIN = INF;
		int nowVisit = -1;
		for (int j=0; j<n; j++) {
			if(!visited[j] && d[j] < MIN) {
				MIN = d[j];
				nowVisit = j;
			}
		}
		if(nowVisit == -1) {
			return;
		}
		visited[nowVisit] = true;
		for(int j=0; j<n; j++) {
			if(!visited[j] && g[nowVisit][j]!=INF) {
				if(d[nowVisit] + g[nowVisit][j] < d[j]) {
					d[j] = d[nowVisit] + g[nowVisit][j];
					numOfPath[j] = numOfPath[nowVisit];
					w[j] = w[nowVisit] + numOfTeam[j];
				} else if (d[nowVisit] + g[nowVisit][j] == d[j]) {
					numOfPath[j] += numOfPath[nowVisit]; 
					if(w[nowVisit] + numOfTeam[j] > w[j]) {
						w[j] = w[nowVisit] + numOfTeam[j];
					}
				}
			}
		}
	}
}
int main()
{
	fill(g[0], g[0]+maxN*maxN, INF);
	scanf("%d %d %d %d", &n,&m,&c1,&c2);
	for(int i=0; i<n; i++) scanf("%d", &numOfTeam[i]);
	int x;
	int y;
	int cost;
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &x,&y,&cost);
		g[x][y] = g[y][x] = cost;
	}
	Dijkstra(c1);
	cout << numOfPath[c2] << " " << w[c2] << endl;
	return 0;
 } 
