#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(){
	int n,x;
	cin >> n;
	vector<int> arr;
	for(int i = 0; i < n; i++){
		cin >> x;
		arr.push_back(x);
	}
	print(arr,n);
	int out = 1;
	while(out>0){
		out = 0;
		for(int i = 0; i < n-1; i++){
			if(arr[i]>arr[i+1]){
				out++;
				swap(arr[i],arr[i+1]);
				print(arr,n);
			}
		}
	}
}