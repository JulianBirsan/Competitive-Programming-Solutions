#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > dist;
vector<vector<int> > graph;

void dfs(int root, int at, int d){
	for(auto u: graph[at]){
		if(dist[root][u]==0 || d+1 < dist[root][u]){
			dist[root][u] = d+1;
			dfs(root,u,d+1);
		}
	}
}

int main(){
	int n,t,m,a,b;
	scanf("%i %i %i",&n,&m,&t);
	vector<int> te;
	vector<int> temp;
	for(int i = 0; i <= n; i++) {
		graph.push_back(temp); te.push_back(0);
	}
	for(int i = 0; i <= n; i++) {
		dist.push_back(te);
	}
	for(int i = 0; i < m; i++){
		scanf("%i %i",&a,&b);
		graph[a].push_back(b);
	}
	for(int i = 1; i <= n; i++) dfs(i,i,0);
	int q;
	scanf("%i",&q);
	for(int i = 0; i < q; i++){
		scanf("%i %i",&a,&b);
		if(dist[a][b]==0){
			printf("Not enough hallways!\n");
		}
		else{
			printf("%i\n",dist[a][b]*t);
		}
	}
}