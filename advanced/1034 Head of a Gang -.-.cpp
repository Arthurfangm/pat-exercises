#include <iostream>
#include <map>
using namespace std;

int n;
int k;
int numPerson = 0;
map<string, int> id;
map<int, string> name;
map<string, int> gang;
int weight[2010] = {0};
int g[2010][2010] = {0};
bool visited[2010] = {false};

int head;
int numMember;
int totalValue;
void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
	numMember ++;
	visited[nowVisit] = true;
	if(weight[nowVisit] > weight[head])
		head = nowVisit;
	for(int i=1; i<=n; i++) {
		if(g[nowVisit][i] > 0) {
			totalValue += g[nowVisit][i];
			g[nowVisit][i] = g[i][nowVisit] = 0;
			if(visited[i] == false)
				DFS(i, head, numMember, totalValue);
		}
	}
}

void DFSTravel(){
	for(int i=1; i<=numPerson; i++){
		if(!visited[i]) {
			head = i;
			numMember = 0;
			totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if(numMember > 2 && totalValue > k) {
				gang[name[head]] = numMember;
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&k);
	string str1;
	string str2;
	int time;
	for(int i=0;i<n;i++){
		cin >> str1 >> str2 >> time;
		if(id.count(str1)==0) {
			numPerson++;
			id[str1] = numPerson;
			name[numPerson] = str1;
		}
		if(id.count(str2)==0) {
			numPerson++;
			id[str2] = numPerson;
			name[numPerson] = str2;
		}
		weight[id[str1]] += time;
		weight[id[str2]] += time;
		g[id[str1]][id[str2]] += time;
		g[id[str2]][id[str1]] += time;
	}
	DFSTravel();
	map<string, int>::iterator it;
	cout << gang.size() << endl;
	for(it = gang.begin(); it != gang.end(); it++) {
		cout << it->first << " " << it->second <<endl;
	}
	return 0;
 } 
