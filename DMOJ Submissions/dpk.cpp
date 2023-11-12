#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int stones[n]; bool dp[k+1]; memset(dp,false,sizeof(dp));
	for(int i = 0; i < n; i++) cin >> stones[i];
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < n; j++){
			if(i==stones[j]) {
				dp[i] = true; break;
			}
			if(i-stones[j]>=0){
				if(!dp[i-stones[j]]){
					dp[i] = true;
					break;
				}
			}
		}
	}
	if(dp[k]) cout << "First\n";
	else cout << "Second\n";
}