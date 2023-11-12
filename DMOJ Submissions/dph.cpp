#include <bits/stdc++.h>

using namespace std;

vector<vector<long long int> > dp;

int main(){
	int h,w; cin >> h >> w;
	vector<long long int> temp;
	char x;
	for(int i = 0; i <= w; i++) {
		temp.push_back(0);
	}
	for(int i = 0; i <= h; i++) {
		dp.push_back(temp);
	}
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> x;
			if(x=='.'){
				dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
			}
			else{
				dp[i][j] = 0;
			}
			dp[1][1] = 1;
		}
	}
	cout << dp[h][w] << "\n";
}