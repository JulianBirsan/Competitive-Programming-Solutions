#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,t,x,y,c,k,z,p,d,a,b,w,out;
	vector<vector<int> > graph;
	vector<int> temp;
	unordered_map<int,vector<int> > pencil;
	cin >> n >> t;
	int distance[n+1];
	bool processed[n+1];
	for(int i = 0; i <= n; i++){
		graph.push_back(temp);
		distance[i] = MAXN;
		processed[i] = false;
	}
	for(int i = 0; i < t; i++){
		cin >> x >> y >> c;
		graph[x].push_back(y);
		graph[y].push_back(x);
		graph[x].push_back(c);
		graph[y].push_back(c);
	}
	if(t==0){
		out = MAXN;
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> z >> p;
		vector<int> temp;
		pencil[z] = temp;
		pencil[z].push_back(p);
		pencil[z].push_back(MAXN);
		if(t==0){
			out = min(out,p);
		}
	}
	cin >> d;
	if(t==0){
		cout << out;
		exit(0);
	}
//	cout << graph[n][0];
	distance[d] = 0;
	if(pencil.count(d)==1){
		pencil[d][1] = 0;
	}
	priority_queue<vector<int> > q;
	temp.push_back(0);
	temp.push_back(d);
	q.push(temp);
	while(!q.empty()){
		a = q.top()[1]; q.pop();
		if(a>n){
			continue;
		}
		if(processed[a]){
			continue;
		}
		processed[a] = true;
		for(unsigned int i = 0; i < graph[a].size()-1; i+=2){
			b = graph[a][i]; w = graph[a][i+1];
			if(distance[a]+w < distance[b]){
				distance[b] = distance[a] + w;
				if(pencil.count(b)==1){
					pencil[b][1] = min(distance[a] + w, pencil[b][1]);
				}
				vector<int> temp;
				temp.push_back(-distance[b]);
				temp.push_back(b);
				q.push(temp);
			}
		}
	}
	out = MAXN;

	for(auto it:pencil){
		if(it.second[1] == MAXN){
			out = min(it.second[0],out);
		}
		else{
			out = min(it.second[0]+it.second[1], out);
		}
	}

	cout << out;
}