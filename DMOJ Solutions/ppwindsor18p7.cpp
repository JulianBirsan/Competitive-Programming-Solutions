#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int c[n+1]; c[0] = 0;
	for(int i = 1; i <= n; i++) scanf("%d",&c[i]);
	int dp[n+1]; dp[0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = c[i];
		for(int k = 1; k <= i/2; k++){
			dp[i] = max(dp[i],dp[k]+dp[i-k]);
		}
	}
	cout << dp[n] << "\n";
}