#include <bits/stdc++.h>

using namespace std;

int out = 0;
vector<vector<int> > graph;
vector<vector<int> > from;
vector<int> dp;

int dfs(int at){
	int dist = 0;
	for(auto u: from[at]){
		if(dp[u]!=-1){
			dist = max(dist,dp[u]+1);
		}
		else{
			dist = max(dist,dfs(u)+1);
		}
	}
	dp[at] = dist;
	return dist;
}

int main(){
	int n,m,x,y;
	cin >> n >> m;
	vector<int> temp;
	vector<bool> visited;
	for(int i = 0; i <= n; i++){
		graph.push_back(temp);
		from.push_back(temp);
		dp.push_back(-1);
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		graph[x].push_back(y);
		from[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if(graph[i].size()==0){
			out = max(dfs(i),out);
		}
	}
	cout << out;
}