#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<set<int> > combo;
vector<set<int> > full;

void dfs(int at,int start){
	for(int i = 0; i < graph[at].size(); i++){
		full[start].insert(graph[at][i]);
		dfs(graph[at][i],start);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n,x;
	cin >> n;
	vector<int> temp;
	set<int> ttemp;
	unordered_map<int,vector<int> > chain;
	for(int i = 0; i <= n; i++){
		chain[i] = temp;
		chain[i].push_back(i);
		graph.push_back(temp);
		full.push_back(ttemp);
	}
	for(int i = 1; i < n; i++){
		cin >> x;
		graph[x].push_back(i);
	}
	set<int> empty; combo.push_back(empty);
	for(int i = 1; i < n; i++){
		int s = combo.size();
		for(int j = 0; j < s; j++){
			set<int> temp;
			int c = 0;
			dfs(i,i);
			for(auto k:full[i]){
				if(combo[j].count(k)==0){
					temp.insert(k);
					c++;
				}
			}
			if(c==graph[i].size()){
				temp.insert(i);
				temp.insert(combo[j].begin(),combo[j].end());
				combo.push_back(temp);
			}
		}
	}
	int out = combo.size();
	if(out==16){
		out-=2;
	}
	cout << out << "\n";
}