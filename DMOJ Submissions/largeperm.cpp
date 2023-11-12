#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,x;
	cin >> n >> k;
	int arr[n];
	unordered_map<int,int> at;
	for(int i = 0; i < n; i++){
		cin >> x;
		arr[i] = x;
		at[x] = i;
	}
	int l = 0;
	while(l < min(n,k)){
		if(arr[l]!=n-l){
			swap(arr[l],arr[at[n-l]]);
			swap(at[arr[l]],at[arr[at[n-l]]]);
		}
		else{
			k++;
		}
		l++;
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}