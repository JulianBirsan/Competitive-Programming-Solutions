#include <bits/stdc++.h>

using namespace std;

int bs(int goal, vector<int> arr){
	int l = 0;
	int r = arr.size()-1;
	int ans = 0;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(arr[mid]<goal){
			ans = max(ans,mid);
			l = mid + 1;
		}
		else if(arr[mid]>goal){
			r = mid - 1;
		}
		else{
			return mid;
		}
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	vector<int> gate;

	int g;
	int p;
	cin >> g;
	cin >> p;

	for(int i = 0; i < g; i++){
		gate.push_back(i+1);
	}

	for(int i = 0; i < p; i++){
		int pref;
		cin >> pref;
		int re = bs(pref,gate);
		if(gate[re]>pref){
			cout << i;
			exit(0);
		}
		gate.erase(gate.begin()+re);
	}
	cout << p;
}