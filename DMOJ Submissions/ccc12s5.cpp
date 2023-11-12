#include <bits/stdc++.h>

using namespace std;

int main(){
	int r,c,k,x,y;
	cin >> r >> c;
	cin >> k;
	int dp[r][c];
	memset(dp,0,sizeof(dp[0][0])*r*c);
	for(int i = 0; i < k; i++){
		cin >> x >> y;
		dp[x-1][y-1] = -1;
	}
	dp[0][0] = 1;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(dp[i][j]!=-1){
				if(j-1>=0){
					if(dp[i][j-1]!=-1){
						dp[i][j] += dp[i][j-1];
					}
				}
				if(i-1>=0){
					if(dp[i-1][j]!=-1){
						dp[i][j] += dp[i-1][j];
					}
				}
			}
		}
	}

	cout << dp[r-1][c-1];
}