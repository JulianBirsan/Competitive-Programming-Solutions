#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<long long int>::max()

vector<long long int> cost;
vector<vector<int> > people;
vector<vector<int> > graph;
vector<int> v;
vector<bool> processed;

int main(){
	int n,c,k,vi; scanf("%d %d %d",&n,&c,&k);
	vector<int> temp;
	for(int i = 0; i <= c; i++) people.push_back(temp);
	for(int i = 0 ; i < n; i++){
		cost.push_back(MAXN);
		processed.push_back(false);
		graph.push_back(temp);
		scanf("%d",&vi); v.push_back(vi);
	}
	int ci,cl;
	for(int i = 0; i < n; i++){
		scanf("%d",&ci);
		for(int j = 0; j < ci; j++){
			scanf("%d",&cl);
			people[cl].push_back(i);
			graph[i].push_back(cl);
		}
	}

	priority_queue<pair<long long int, long long int> > q;
	cost[0] = 0;
	q.push(make_pair(0,0));
	while(!q.empty()){
		int at = q.top().second; q.pop();
		if(processed[at]) continue;
		processed[at] = true;
		for(auto u: graph[at]){
			for(auto to: people[u]){
				if(!processed[to]){
					if(cost[at] + abs(v[at]-v[to])+k<cost[to]){
						cost[to] = cost[at] + abs(v[at]-v[to])+k;
						q.push(make_pair(-cost[to],to));
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(cost[i]==MAXN) cout << -1 << "\n";
		else cout << cost[i] << "\n";
	}
}