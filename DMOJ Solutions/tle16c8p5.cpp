#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;

vector<vi> graph;
bool seen[101];
int oc[101];
unordered_set<int> nerd;

bool match(int at){
	for(auto u: graph[at]){
		if(!seen[u]){
			seen[u] = true;
			if(oc[u]==0 || match(oc[u])){
				oc[u] = at;
				return true;
			}
		}
	}
	return false;
}

int main(){
	memset(oc,0,sizeof(oc));
	int n,m; scanf("%d %d",&n,&m);
	vi temp;
	for(int i = 0; i <= n; i++){
		graph.push_back(temp);
	}
	int t,id;
	int nerdt = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d",&t);
		for(int j = 0; j < t; j++){
			scanf("%d",&id);
			if(i==1) nerd.insert(id);
			if(nerd.count(id)==1){
				graph[i].push_back(id);
			}
		}
		if(i==1) nerdt = t;
	}
	int out = nerdt;
	for(int i =  2; i <= n; i++){
		memset(seen,0,sizeof(seen));
		out -= match(i);
	}
	cout << out << "\n";
}