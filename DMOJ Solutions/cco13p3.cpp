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

vector<vector<int> > graph;
vector<int> dist; vector<long long int> dp;
long long int out = 0; long long int freq = 0;
long long int one = 1;

void dfs(int at, int prev){
	vector<pii> brnch;
	for(auto u: graph[at]){
		if(u!=prev){
			dfs(u,at);
			brnch.push_back(make_pair(dist[u],u));
		}
	}
	sort(brnch.rbegin(),brnch.rend());
	if(brnch.size()==0){
		dist[at] = 0;
		dp[at] = 1;
		if(out==0){
			out = 1; freq = 1;
		}
	}
	else if(brnch.size()==1){
		dist[at] = brnch[0].first+1;
		dp[at] = dp[brnch[0].second];
		if(dist[at]==out){
			freq += dp[at];
		}
		else if(dist[at]>out){
			freq = dp[at];
		}
	}
	else{
		LL f = 0;
		LL topway = dp[brnch[0].second];
		if(brnch[1].first<brnch[0].first){
			int sec = brnch[1].first;
			for(int i = 1; i < brnch.size(); i++){
				if(brnch[i].first!=sec) break;
				f += topway*dp[brnch[i].second];
			}
		}
		else{
			int sec = brnch[0].first;
			for(int i = 1; i < brnch.size(); i++){
				if(brnch[i].first!=sec) break;
				f += topway*dp[brnch[i].second];
				topway += dp[brnch[i].second];
			}
		}
		dist[at] = brnch[0].first+1;
		dp[at] = topway;
		if(brnch[0].first + brnch[1].first + 2 > out){
			out = brnch[0].first + brnch[1].first + 2;
			freq = f;
		}
		else if(brnch[0].first + brnch[1].first + 2 == out){
			freq += f;
		}
	}
}

int main(){
	int n; cin >> n;
	int x,y;
	vector<int> temp;
	for(int i = 0; i <= n; i++) {
		graph.push_back(temp); dist.push_back(0); dp.push_back(0);
	}
	for(int i = 1; i < n; i++){
		scanf("%i %i",&x,&y);
		graph[x].push_back(y); graph[y].push_back(x);
	}
	dfs(1,-1);
//	for(int i = 1; i <= n; i++){
//		cout << dp[i] << " ";
//	}
//	cout << "\n";
//	for(int i = 1; i <= n; i++){
//		cout << dist[i] << " ";
//	}
//	cout << "\n";
	cout << out+1 << " " << freq << "\n";
}