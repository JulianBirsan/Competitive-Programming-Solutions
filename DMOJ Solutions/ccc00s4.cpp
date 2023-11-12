#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m,n,c;
	cin >> m >> n;

	int clubs[n];
	for(int i = 0; i < n; i++){
		cin >> c;
		clubs[i] = c;
	}

	int dp[m];
	for(int i = 0; i < m; i++){
		dp[i] = 5281;
	}
	for(int i = 0; i < n; i++){
		dp[clubs[i]-1] = 1;
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j<=(i+1)/2; j++){
			if(dp[j-1] != 5281 && dp[i-j] != 5281){
				dp[i] = min(dp[i],dp[j-1]+dp[i-j]);
			}
		}
	}
	if(dp[m-1]==5281){
		cout << "Roberta acknowledges defeat.";
	}
	else{
		cout << "Roberta wins in " << dp[m-1] << " strokes.";
	}
}