#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
vector<vector<int> > graph;
vector<vector<int> > dist;
vector<bool> processed;

void printVec(vector<vector<int> > v){
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			if(v[i][j]==MAXN) cout << "I ";
			else cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


int main(){
	int k,n,m; scanf("%i %i %i",&k,&n,&m);
	vector<int> temp;
	vector<int> tempdist;
	for(int i = 0; i <= k; i++) tempdist.push_back(MAXN);
	for(int i = 0; i <= n; i++) {
		graph.push_back(temp);
		dist.push_back(tempdist);
		processed.push_back(false);
	}
	int a,b,t,h;
	for(int i = 0; i < m; i++){
		scanf("%i %i %i %i",&a,&b,&t,&h);
		graph[a].push_back(b); graph[a].push_back(t); graph[a].push_back(h);
		graph[b].push_back(a); graph[b].push_back(t); graph[b].push_back(h);
	}
	scanf("%i %i",&a,&b);
	for(int i = 0; i <= k; i++) dist[a][i] = 0;
	priority_queue<pair<int,int> > q;
	pair<int,int> start (0,a);
	processed[a] = true;
	q.push(start);
	while(!q.empty()){
		int at = q.top().second; q.pop();
		processed[at] = false;
		for(int i = 0; i < graph[at].size(); i+=3){
			int to = graph[at][i];
			int distance = graph[at][i+1];
			int wear = graph[at][i+2];
			for(int j = k; j > 0; j--){
				if(dist[at][j]!=MAXN){
					if(j-wear>0){
						if(dist[at][j] + distance < dist[to][j-wear]){
							dist[to][j-wear] = dist[at][j] + distance;
							if(!processed[to]){
								processed[to] = true;
								pair<int,int> tt(-dist[to][j-wear],to);
								q.push(tt);
							}
						}
					}
				}
			}
		}
	}
	int out = MAXN;
	for(int i = 1; i <= k; i++){
		out = min(out,dist[b][i]);
	}
	if(out==MAXN) cout << "-1\n";
	else cout << out << "\n";
}