#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n,w,wi,vi;
	long long int top = 0;
	cin >> n >> w;
	vector<long long int> dp;
	cin >> wi >> vi;
	for(int j = 0; j <= w; j++){
		if(wi<=j){
			dp.push_back(vi);
			top = vi;
		}
		else{
			dp.push_back(0);
		}
	}
	for(int i = 1; i < n; i++){
		cin >> wi >> vi;
		vector<long long int> temp;
		for(int j = 0; j <= w; j++){
			if(wi<=j){
				temp.push_back(max(dp[j],vi+dp[j-wi]));
				top = max(top,temp[j]);
			}
			else{
				temp.push_back(dp[j]);
			}
		}
		dp = temp;
	}
	cout << top;
}