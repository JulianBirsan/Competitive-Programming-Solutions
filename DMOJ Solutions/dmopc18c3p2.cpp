#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()

int main(){
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	for(int i = 0; i < n; i++) scanf("%d",&b[i]);
	int dp[n+1][3]; memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++){
		int ai = a[i-1]; int bi = b[i-1];
		dp[i][0] = max(dp[i-1][0] + bi,dp[i-1][1]+bi); dp[i][0] = max(dp[i][0],dp[i-1][2]+bi);
		dp[i][1] = max(dp[i-1][1]+bi,dp[i-1][0]+ai);
		dp[i][2] = max(dp[i-1][2]+bi,dp[i-1][1]+ai);
	}
	int out = -MAXN;
	for(int i = 0; i < 3; i++) out = max(out,dp[n][i]);
	cout << out << "\n";
}