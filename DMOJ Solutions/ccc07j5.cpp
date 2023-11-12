#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,n,x;
	cin >> a >> b >> n;
	long long int temp[14] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
	long long int arr[n+14];
	for(int i = 0; i < 14; i++){
		arr[i] = temp[i];
	}
	long long int dp[n+14];
	memset(dp,-1,sizeof(dp[0])*(n+14));
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		cin >> x;
		arr[i+14] = x;
	}
	sort(arr,arr+n+14);

	for(int i = 0; i < n+13; i++){
		if(dp[i]!=-1){
			for(int j = i+1; j < n+14; j++){
				if(arr[j]<=arr[i]+b && arr[j]>=arr[i]+a){
					if(dp[j]==-1){
						dp[j] = 0;
					}
					dp[j]+=dp[i];
				}
			}
		}

	}
	if(dp[n+13]==-1){
		cout << 0 << "\n";
	}
	else{
		cout << dp[n+13] << "\n";
	}
}