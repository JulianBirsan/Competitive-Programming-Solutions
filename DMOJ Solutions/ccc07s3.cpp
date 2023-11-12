#include <bits/stdc++.h>

using namespace std;

bool check = false;
bool found = false;
int dist = 0;
vector<vector<int> > graph;

void dfs(vector<bool> visit, int at, int a, int b, int d){
	visit[at] = true;
	for(int i = 0; i < graph[at].size(); i++){
		if(graph[at][i]==a && found){
			check = true;
			break;
		}
		if(!visit[graph[at][i]]){
			if(graph[at][i]==b){
				dist = d;
				found = true;
			}
			dfs(visit,graph[at][i],a,b,d+1);
		}
	}
}

int main(){
	int n,x,y,a,b;
	cin >> n;
	vector<bool> visit;
	vector<int> temp;
	for(int i = 0; i <= 9999; i++){
		graph.push_back(temp);
		visit.push_back(false);
	}
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		graph[x].push_back(y);
	}
	cin >> a >> b;
	while(a!= 0 && b!= 0){
		check = false;
		found = false;
		dist = 0;
		dfs(visit,a,a,b,0);
		if(check){
			cout << "Yes " << dist << "\n";
		}
		else{
			cout << "No\n";
		}
		cin >> a >> b;
	}
}