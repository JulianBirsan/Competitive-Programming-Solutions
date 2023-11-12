#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<long long int> arr;
	long long int s;
	long long int sum = 0;

	for(int i = 0; i < n; i++){
		cin >> s;
		arr.push_back(s);
		sum += s;
	}
	long long int out = 0;
	if(sum%n!=0){
		cout << "Impossible";
	}
	else{
		long long int mid = sum/n;
		for(int i = 0; i < n; i++){
			out += abs(arr[i]-mid);
		}
		cout << out/2;
	}
}