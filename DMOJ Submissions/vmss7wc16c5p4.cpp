#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n,x,y,z,minn;
	long long int arr[3];
	long long int check = 0;
	cin >> n >> x >> y >> z;
	arr[0] = x; arr[1] = y; arr[2] = z;
	long long int dp[n+1];
	memset(dp,-1,sizeof(dp[0])*(n+1));
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		minn = -1;
		for(int j = 0; j < 3; j++){
			if(i-arr[j]>=0){
				if(dp[i-arr[j]]!=-1){
					minn = max(minn,dp[i-arr[j]]+1);
				}
			}
		}
		dp[i] = minn;
	}
//	for(int i = 0; i <= n; i++){
//		cout << dp[i] << " ";
//	}
//	cout << "\n";
	cout << max(dp[n],check);
}