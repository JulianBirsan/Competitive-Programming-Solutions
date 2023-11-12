#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k,u;
	cin >> k;
	int arr[k];

	for(int i = 0; i < k; i++){
		cin >> u;
		arr[i] = u;
	}

	int n,f;
	cin >> n;

	int at = 0;
	unordered_map<int,int> thing;

	sort(arr,arr+k);

	for(int i = 1; i <= arr[k-1]; i++){
		if(i<arr[at]){
			thing[i] = at;
		}
		else{
			at ++;
			thing[i] = at;
		}
	}

	for(int i = 0; i < n; i++){
		cin >> f;
		int key = min(arr[k-1],f);
		cout << f - thing[key] << "\n";
	}
}