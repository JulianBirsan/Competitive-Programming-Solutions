#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<bool> valid;
unordered_set<int> pho;
vector<int> dist;
int ind = 0;
int len = 0;
pair<int,int> far(0,-1);

void prune(int at, int prev){
	if(pho.count(at)==1){
		valid[at] = true;
	}
	for(auto u: graph[at]){
		if(u!=prev){
			prune(u,at);
			if(valid[u]){
				valid[at] = true;
			}
		}
	}
}

void dfs(int at, int prev, int d){
	bool leaf = true;
	int top = 0;
	for(auto u: graph[at]){
		if(u!=prev && valid[u]){
			len++;
			leaf = false;
			dfs(u,at,d+1);
			dist[at] = max(dist[u] + 1,dist[at]);
			top = max(top,dist[u]+1);
		}
	}
	if(pho.count(at)==1 && d>far.first){
		far.first = d; far.second = at;
	}
}

int main(){
	int n,m,x,y,p; cin >> n >> m;
	vector<int> temp;
	vector<int> distLocal;
	for(int i = 0; i < n; i++){
		graph.push_back(temp);
		valid.push_back(false);
		distLocal.push_back(0);
	}
	for(int i = 0; i < m; i++){
		cin >> p; pho.insert(p);
	}
	for(int i = 1; i < n; i++){
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	valid[p] = true;
	prune(p,-1);
	dist = distLocal;
	dfs(p,-1,0);
	int comp = dist[p];
	dist = distLocal;
	int a = far.second;
	dfs(a,-1,0);
	cout << len - max(comp,dist[a]) << "\n";
}