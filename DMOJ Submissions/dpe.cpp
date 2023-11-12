#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,w;
	cin >> n >> w;
	int maxVal = 0;
	long long int wt[n],vl[n];
	for(int i = 0; i < n; i++){
		cin >> wt[i] >> vl[i];
		maxVal += vl[i];
	}
	long long int dp[n+1][maxVal+1];
	long long int out = 0;
	memset(dp,0,sizeof(dp));
	for(long long int i = 1; i <= n; i++){
		for(long long int j = 0; j <= maxVal; j++){
			if(dp[i-1][j]>0 && dp[i-1][j]+wt[i-1]<=w){
				if(dp[i][j+vl[i-1]]==0){
					dp[i][j+vl[i-1]] = wt[i-1] + dp[i-1][j];
				}
				else{
					dp[i][j+vl[i-1]] = min(wt[i-1] + dp[i-1][j],dp[i][j+vl[i-1]]);
				}
			}
			if(j==vl[i-1]){
				if(dp[i][j]==0){
					dp[i][j] = wt[i-1];
				}
				else{
					dp[i][j] = min(dp[i][j],wt[i-1]);
				}
			}
			if(dp[i][j]==0){
				dp[i][j] = dp[i-1][j];
			}
			else if(dp[i-1][j]!=0){
				dp[i][j] = min(dp[i][j],dp[i-1][j]);
			}
			if(dp[i][j]>0){
				out = max(out,j);
			}
		}
	}
	cout << out << "\n";
}