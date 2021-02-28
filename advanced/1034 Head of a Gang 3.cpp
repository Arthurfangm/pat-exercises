#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
int k;
int numPerson = 0;
int numMember;
int head;
int totalValue;
map<string, int> id;
map<int, string> name;
map<string, int> gang;
string str1;
string str2;
int t;
int weight[2010] = {0};
int g[2010][2010] = {0};
bool visited[2010] = {false};
void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
	numMember ++;
	visited[nowVisit] = true;
	if(weight[nowVisit]>weight[head]) {
		head = nowVisit;
	}
	for(int i=1; i<=n; i++) {
		if(g[nowVisit][i]!=0) {
			totalValue += g[nowVisit][i];
			g[nowVisit][i] = g[i][nowVisit] = 0;
			if(visited[i]!=true) {
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}
void DFSTravel() {
	for (int i=1; i<=numPerson; i++) {
		if(!visited[i]) {
			numMember = 0;
			head = i;
			totalValue = 0;
			DFS(i, head, numMember, totalValue);
		}
		if(numMember>2 && totalValue>k) {
			gang[name[head]] = numMember;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) {
		cin >> str1 >> str2 >> t;
		if(id.count(str1)==0) {
			numPerson ++;
			id[str1] = numPerson;
			name[numPerson] = str1;
		}
		if(id.count(str2)==0) {
			numPerson ++;
			id[str2] = numPerson;
			name[numPerson] = str2; 
		}
		weight[id[str1]] += t;
		weight[id[str2]] += t;
		g[id[str1]][id[str2]] += t;
		g[id[str2]][id[str1]] += t;
	}
	DFSTravel();
	cout << gang.size() << endl;
	map<string, int>::iterator it;
	for(it = gang.begin(); it != gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
