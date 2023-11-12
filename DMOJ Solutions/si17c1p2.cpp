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

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	LL arr[n];
	for(int i = 0; i < n; i++){
		scanf("%lld",&arr[i]);
	}
	LL dp[n+1]; dp[0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = max(arr[i-1]+dp[max(i-k-1,0)],dp[i-1]);
	}
	cout << dp[n] << "\n";
}