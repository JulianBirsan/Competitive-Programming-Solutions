#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()

vector<vector<int> > graph;
vector<bool> processed;
vector<vector<int> > dist;

int main(){
	int s,n,e;
	scanf("%i %i %i",&s,&n,&e);
	vector<int> temp;
	vector<int> disttemp;
	for(int i = 0; i <= s; i++) disttemp.push_back(MAXN);
	for(int i = 0; i < n; i++) {
		dist.push_back(disttemp);
		if(i==0){
			for(int j = 0; j <= s; j++) dist[i][j] = 0;
		}
		processed.push_back(false);
		graph.push_back(temp);
	}
	int a,b,d,t;
	for(int i = 0; i < e; i++){
		scanf("%i %i %i %i",&a,&b,&d,&t);
		graph[a].push_back(b); graph[a].push_back(d); graph[a].push_back(t);
		graph[b].push_back(a); graph[b].push_back(d); graph[b].push_back(t);
	}
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,0));
	while(!q.empty()){
		int at = q.top().second; q.pop();
		processed[at] = false;
		for(int i = 0; i < graph[at].size(); i+=3){
			int to = graph[at][i];
			int distance = graph[at][i+1];
			int tunnel = graph[at][i+2];
			for(int j = 0; j <= s; j++){
				if(dist[at][j]!=MAXN){
					if(j+distance*tunnel<=s){
						if(distance+dist[at][j] < dist[to][j+distance*tunnel]){
							dist[to][j+distance*tunnel] = distance+dist[at][j];
							if(!processed[to]){
								processed[to] = true;
								q.push(make_pair(-dist[to][j+distance*tunnel],to));
							}
						}
					}

				}
			}
		}
	}
	int out = MAXN;
	for(int i = 0; i <= s; i++){
		out = min(out,dist[n-1][i]);
	}
	if(out==MAXN) cout << -1 << "\n";
	else cout << out << "\n";
}