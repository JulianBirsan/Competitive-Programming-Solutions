#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int arr[n];
	int total = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i]; total += arr[i];
	}
	int out = total;
	vector<bool> dp;
	for(int i = 0; i <= total; i++){
		dp.push_back(false);
	}
	vector<bool> a = dp;
	for(int i = 0; i < n; i++){
		vector<bool> temp = a;
		for(int j = 0; j <= total; j++){
			if(j==arr[i]){
				temp[j] = true;
				out = min(abs(j-(total-j)),out);
			}
			else if(dp[j]){
				temp[j] = true;
				temp[j+arr[i]] = true;
				out = min(abs(j-(total-j)),out);
			}
		}
		dp = temp;
	}
	cout << out << "\n";
}