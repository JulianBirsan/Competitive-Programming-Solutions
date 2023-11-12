#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<int> cherries;
vector<int> weights;
int out = 0;
int c,k;

void dfs(int at){
	for(int i = 0; i < graph[at].size(); i+=2){
		cherries[at] += cherries[graph[at][i]];
		weights[at] += weights[graph[at][i]];
		if(cherries[graph[at][i]]>=c && weights[graph[at][i]]+graph[at][i+1]<=k){
			//cout << graph[at][i] << " " << weights[graph[at][i]] +graph[at][i+1]<< " " << cherries[graph[at][i]] << "\n";
			out++;
		}
	}
}

int main(){
	int n,ci,a,b,ki;
	scanf("%i %i %i",&n,&c,&k);
	cherries.push_back(0);
	vector<int> temp;
	for(int i = 0; i <= n; i++){
		graph.push_back(temp);
		weights.push_back(0);
	}
	for(int i = 0; i < n; i++){
		scanf("%i",&ci); cherries.push_back(ci);
	}
	for(int i = 1; i < n; i++){
		scanf("%i %i %i",&a,&b,&ki);
		graph[a].push_back(b); weights[a] += ki; graph[a].push_back(ki);
	}
	for(int i = n; i > 0; i--){
		dfs(i);
	}
	cout << out << "\n";
}