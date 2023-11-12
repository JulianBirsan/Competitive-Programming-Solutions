#include <bits/stdc++.h>

using namespace std;

int graph[1001][1001];
bool processed[1001][1001];
vector<vector<pair<int,int> > > adj;
int m,n;

bool dfs(pair<int,int> at){
	int x = at.first; int y = at.second;
	if(!processed[x][y]){
		processed[x][y] = true;
		if(x==1 && y==1){
			return true;
		}
		int a = x*y;
		for(auto u: adj[a]){
			bool c = dfs(u);
			if(c){
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin >> m >> n;
	vector<pair<int,int> > t;
	for(int i = 0; i <= 1000000; i++) adj.push_back(t);
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
			processed[i][j] = false;
			pair<int,int> temp (i,j);
			adj[graph[i][j]].push_back(temp);
		}
	}
	pair<int,int> start (m,n);
	bool out = dfs(start);
	if(out){
		cout << "yes";
	}
	else{
		cout << "no";
	}
}