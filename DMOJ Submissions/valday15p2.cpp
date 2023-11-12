#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
	int c,m,k,n;
	scanf("%i %i",&c,&m);
	int dp[c+1][m+1]; memset(dp,0,sizeof(dp));
	vector<pii> cage;
	for(int i = 0; i < c; i++){
		scanf("%i %i",&n,&k);
		cage.push_back(make_pair(n,k));
	}
	for(int i = 1; i <= c; i++){
		int ni = cage[i-1].first; int ki = cage[i-1].second;
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i-1][j];
			if(j-ki>=0){
				dp[i][j] = max(dp[i][j],ni+dp[i-1][j-ki]);
			}
		}
	}
	cout << dp[c][m] << "\n";
}