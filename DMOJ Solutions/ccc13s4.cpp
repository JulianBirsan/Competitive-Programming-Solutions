#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<bool> processed;

bool dfs(int at, int prev,int goal){
	for(auto u: graph[at]){
		if(u!=prev && !processed[u]){
			processed[u] = true;
			if(u==goal) return true;
			if(dfs(u,at,goal))return true;
		}
	}
	return false;
}

int main(){
	int x,y,n,m,p,q;
	scanf("%i %i",&n,&m);
	vector<int> temp;
	for(int i = 0; i <= n; i++) graph.push_back(temp);
	for(int i = 0; i < m; i++){
		scanf("%i %i",&x,&y);
		graph[x].push_back(y);
		processed.push_back(false);
	}
	scanf("%i %i",&p,&q);
	if(dfs(p,-1,q)) printf("yes\n");
	else if(dfs(q,-1,p)) printf("no\n");
	else printf("unknown\n");
}