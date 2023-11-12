#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> cost;

	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		cost.push_back(c);
	}

	vector<int> dp;
	dp.push_back(0);
	dp.push_back(abs(cost[0]-cost[1]));

	for(int i = 2; i < n; i++){
		int a = min(abs(cost[i]-cost[i-1]) + dp[i-1],abs(cost[i]-cost[i-2]) + dp[i-2]);
		dp.push_back(a);
	}

	cout << dp[n-1];
    return 0;
}