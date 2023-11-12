#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<double> arr,temp;
	vector<vector<double> > dp;
	cin >> n;
	double x;
	for(int i = 0; i < n; i++){
		cin >> x; arr.push_back(x); dp.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		if(i==0){
			for(int j = 0; j < 4; j++) dp[i].push_back(arr[i]);
		}
		else if(i==1){
			dp[i].push_back(arr[i]+arr[0]);
			if(arr[1]>arr[0]) dp[i].push_back(arr[0]/2+arr[1]);
			else dp[i].push_back(arr[1]/2+arr[0]);
			dp[i].push_back(arr[i]+arr[0]);
			dp[i].push_back(min(dp[i][0],dp[i][1]));
			dp[i][3] = min(dp[i][3],dp[i][2]);
		}
		else if(i==2){
			dp[i].push_back(min(dp[1][0],dp[1][1])+arr[2]);
			if(arr[2]>arr[1]) dp[i].push_back(arr[1]/2+arr[2]);
			else dp[i].push_back(arr[2]/2+arr[1]);
			dp[i][1] += arr[0];
			double low = min(arr[0],arr[1]); low = min(low,arr[2]);
			dp[i].push_back(arr[0]+arr[1]+arr[2]-low);
			dp[i].push_back(min(dp[i][0],dp[i][1]));
			dp[i][3] = min(dp[i][3],dp[i][2]);
		}
		else{
			dp[i].push_back(dp[i-1][3]+arr[i]);
			if(arr[i]>arr[i-1]) dp[i].push_back(arr[i-1]/2+arr[i]);
			else dp[i].push_back(arr[i]/2+arr[i-1]);
			dp[i][1] += dp[i-2][3];
			double low = min(arr[i],arr[i-1]); low = min(low,arr[i-2]);
			dp[i].push_back(arr[i]+arr[i-1]+arr[i-2]-low+dp[i-3][3]);
			dp[i].push_back(min(dp[i][0],dp[i][1]));
			dp[i][3] = min(dp[i][3],dp[i][2]);
		}
	}
	printf("%.1f",dp[n-1][3]);
}