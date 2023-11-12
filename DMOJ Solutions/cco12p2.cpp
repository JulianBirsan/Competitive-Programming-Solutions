#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
typedef pair<int,int> pii;

vector<vector<pii> > graph;
vector<int> dist,dist2;
vector<int> processed;

int main(){
	int n,m,a,b,l;
	scanf("%i %i",&n,&m);
	vector<pii> temp;
	for(int i = 0; i <= n; i++) {
		graph.push_back(temp);
		dist.push_back(MAXN); dist2.push_back(MAXN);
		processed.push_back(0);
	}
	for(int i = 0; i < m; i++){
		scanf("%i %i %i",&a,&b,&l);
		graph[a].push_back(make_pair(b,l));
	}
	priority_queue<pii> q; q.push(make_pair(0,1));

	while(!q.empty()){
		int at = q.top().second; int d = abs(q.top().first); q.pop();
		if(processed[at]==2) continue;
		processed[at]++;
		for(auto u: graph[at]){
			int to = u.first; int distance = u.second;
			if(d+distance < dist[to]){
				dist2[to] = dist[to]; dist[to] = d+distance;
				q.push(make_pair(-dist[to],to));
			}
			else if(d+distance < dist2[to] && d+distance > dist[to]){
				dist2[to] = d+distance;
				q.push(make_pair(-dist2[to],to));
			}
		}
	}
	if(dist2[n]==MAXN) cout << -1 << "\n";
	else cout << dist2[n] << "\n";
}