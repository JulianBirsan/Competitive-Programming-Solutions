#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,h;
	int out = 0;
	cin >> n;
	int arr[n],dp[n];
	for(int i = 0; i < n; i++){
		cin >> h;
		arr[i] = h;
	}
	for(int k = 0; k < n; k++){
		dp[k] = arr[k];
		for(int i = 0; i < k; i++){
			if(arr[i]<arr[k]){
				if(dp[k]<dp[i]+arr[k]){
					dp[k] = dp[i] + arr[k];
				}
			}
		}
		out = max(dp[k],out);
	}
	cout << out;
}