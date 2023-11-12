#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t,c,n;
	cin >> t >> c;
	int arr[c];

	for(int i = 0; i < c; i++){
		cin >> n;
		arr[i] = n;
	}

	sort(arr,arr+c);
	int psa[c+1];
	psa[0] = 0;

	for(int i = 1; i <= c; i++){
		psa[i] = arr[i-1] + psa[i-1];
		if(psa[i] > t){
			cout << i-1;
			exit(0);
		}
	}
	cout << c;
}