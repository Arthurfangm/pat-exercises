#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n;
int k;
int count = 0;
const int maxnk = 2010;
int numPerson = 0;
int g[maxnk][maxnk]={0};
int weight[maxnk]={0};
map<string,int> id;
map<int,string> name;
map<string,int> gang;

int head;
int numMember;
int totalValue;
bool visited[maxnk]={false};

void DFS(int nowVisit, int& head, int& numMember, int &totalValue){
	numMember++;
	visited[nowVisit]=true;
	if(weight[nowVisit]>weight[head])
		head = nowVisit;
	for(int i=1;i<=numPerson;i++){
		if(g[nowVisit][i]>0){
			totalValue += g[nowVisit][i];
			g[nowVisit][i]=g[i][nowVisit]=0;
			if(visited[i]==false)
				DFS(i,head,numMember,totalValue);
		}
	}
}
void DFSTravel(){
	for(int i=1;i<=numPerson;i++){
		head = i;
		numMember = 0;
		totalValue = 0;
		if(visited[i]==false){
			DFS(i,head,numMember,totalValue);
			if(numMember>2&&totalValue>k)
				gang[name[head]]=numMember;
		}
	}
}

int main()
{
	scanf("%d %d",&n,&k);
	string start;
	string end;
	int time;
	for(int i=0;i<n;i++){
		cin>>start>>end>>time;
		if(id.count(start)==0){
			numPerson++;
			id[start]=numPerson;
			name[numPerson]=start;
		}
		if(id.count(end)==0){
			numPerson++;
			id[end]=numPerson;
			name[numPerson]=end;
		}
		weight[id[start]]+=time;
		weight[id[end]]+=time;
		g[id[start]][id[end]]+=time;
		g[id[end]][id[start]]+=time;
	}
	DFSTravel();
	cout<<gang.size()<<endl;
	map<string,int>::iterator it;
	for(it = gang.begin();it!=gang.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
}
