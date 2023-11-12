#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
	cin >> n;
	char ans[n];
	char x;
	int out = 0;

	for(int i = 0; i < n; i++){
		cin >> x;
		ans[i] = x;
	}

	for(int i = 0; i < n; i++){
		cin >> x;
		if(x==ans[i]){
			out += 1;
		}
	}
	cout << out;
    return 0;
}