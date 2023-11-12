#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	int q;
	cin >> n;
	cin >> q;

	int k[n];
	int r;
	cin >> r;
	k[0] = r;
	for(int i = 1; i < n; i++){
		int r;
		cin >> r;
		k[i] = r + k[i-1];
	}

	for(int i = 0; i < q; i++){
		int a;
		int b;
		cin >> a;
		cin >> b;
		if(a>1){
			cout << k[n-1] - (k[b-1] - k[a-2]) << "\n";
		}
		else{
			cout << k[n-1] - k[b-1] << "\n";
		}
	}
    return 0;
}