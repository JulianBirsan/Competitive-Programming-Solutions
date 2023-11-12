#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int dp[n+1][3]; int out = 0;
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for(int i = 1; i <= n; i++){
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		dp[i][0] += max(dp[i-1][1],dp[i-1][2]);
		out = max(out,dp[i][0]);
		dp[i][1] += max(dp[i-1][0],dp[i-1][2]);
		out = max(out,dp[i][1]);
		dp[i][2] += max(dp[i-1][0],dp[i-1][1]);
		out = max(out,dp[i][2]);
	}
	cout << out << "\n";
}