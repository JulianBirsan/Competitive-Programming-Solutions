#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x,y;
	cin >> n;
	vector<vector<int> > graph;
	vector<int> temp;
	for(int i = 0; i <=n; i++){
		graph.push_back(temp);
	}
	cin >> x >> y;
	while(x!=0 && y!=0){
		graph[y].push_back(x);
		cin >> x >> y;
	}
	int dp[n+1];
	memset(dp,0,sizeof(dp[0])*(n+1));
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < graph[i].size(); j++){
			dp[i] += dp[graph[i][j]];
		}
	}
	cout << dp[n];
}