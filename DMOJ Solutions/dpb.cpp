#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()

int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	int arr[n+1];
	int dp[n+1];
	for(int i = 1; i <= n; i++){
		scanf("%i",&arr[i]);
		dp[i] = MAXN;
	}
	dp[1] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= i+k && j <= n; j++){
			dp[j] = min(abs(arr[i]-arr[j])+dp[i],dp[j]);
		}
	}
	if(dp[n]==1000000000){
		printf("-1\n");
	}
	else{
		printf("%i\n",dp[n]);
	}
}