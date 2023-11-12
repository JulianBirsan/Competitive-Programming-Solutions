#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;

vi order;
vector<vi> graph;
bool seen[100001];
int out=0;

void topsort(int at){
	seen[at]=true;
	for(int i: graph[at]){
		if(!seen[i]){
			topsort(i);
		}
	}
	order.push_back(at);
}

void dfs(int at){
	seen[at]=true;
	for(int i: graph[at]){
		if(!seen[i]){
			dfs(i);
		}
	}
}

void solve(){
	memset(seen,0,sizeof(seen));
	order.clear();
	out=0;
	graph.clear();
	int n; scanf("%d",&n);
	vi temp;
	for(int i=0;i<=n;i++){
		graph.push_back(temp);
	}
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		graph[x].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!seen[i]) topsort(i);
	}
	reverse(order.begin(),order.end());
	memset(seen,0,sizeof(seen));
	for(int i: order){
		if(!seen[i]){
			out++;
			dfs(i);
		}
	}
	cout<<out<<" ";
}

int main(){
	solve(); solve();
}