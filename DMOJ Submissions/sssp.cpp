#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
vector<vector<pair<int,int> > > graph;
vector<int> processed;
vector<int> dist;

int main(){
	int n,m,x,y,w;
	cin >> n >> m;
	vector<pair<int,int> > temp;
	for(int i = 0; i <= n; i++){
		graph.push_back(temp);
		dist.push_back(MAXN);
		processed.push_back(false);
	}
	dist[1] = 0;
	for(int i = 0; i < m; i++){
		scanf("%i %i %i",&x,&y,&w);
		pair<int,int> t (x,w);
		pair<int,int> t2 (y,w);
		graph[x].push_back(t2); graph[y].push_back(t);
	}
	priority_queue<pair<int,int> > q;
	pair<int,int> start(0,1);
	q.push(start);
	while(!q.empty()){
		int a = q.top().second; q.pop();
		if(processed[a]) continue;
		for(auto u: graph[a]){
			int b = u.first; int w = u.second;
			if(w+dist[a]<dist[b]){
				dist[b] = w + dist[a];
				pair<int,int> add (-dist[b],b);
				q.push(add);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(dist[i]==MAXN){
			cout << "-1\n";
		}
		else{
			cout << dist[i] << "\n";
		}
	}
}