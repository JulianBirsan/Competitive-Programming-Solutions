#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	int out = 0;
	int x[n]; int y[n];
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		cin >> y[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(x[i]<=y[j]) out = max(out,j-i);
		}
	}
	cout << "The maximum distance is " << out << "\n";
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}