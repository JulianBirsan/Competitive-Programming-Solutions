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

int dp[501][30001];

void solve(){
	int out = 0;
	memset(dp,0,sizeof(dp));
	int n,k,w;
	scanf("%d %d %d",&n,&k,&w);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	int sum[n+2]; memset(sum,0,sizeof(sum));
	for(int i = 1; i <= w; i++){
		sum[i] = sum[i-1] + arr[i-1];
	}
	for(int i = w+1; i <= n; i++){
		sum[i] = arr[i-1] + sum[i-1] - arr[i-w-1];
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = max(dp[i][j-1],sum[j]+dp[i-1][max(j-w,0)]);
			out = max(out,dp[i][j]);
		}
	}
	cout << out << "\n";
}

int main(){
	int t; scanf("%d",&t);
	for(int i = 0; i < t; i++){
		solve();
	}
}