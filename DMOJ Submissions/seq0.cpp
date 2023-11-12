#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
	long long int dp[n];
	long long int out = 0;
	for(int i = 0; i < n; i++){
		if(i<2) dp[i] = max(arr[i],0);
		else if(i==2) dp[i] = max(dp[i-2]+arr[i],dp[i-2]);
		else{
			dp[i] = max(dp[i-2]+arr[i],dp[i-2]);
			dp[i] = max(dp[i],dp[i-3]+arr[i]);
		}
		out = max(out,dp[i]);
	}
	cout << out << "\n";
}