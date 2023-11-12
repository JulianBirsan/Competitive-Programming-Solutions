#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	long long int out = 0;
	cin >> n;
	int e[n];
	int l[n];
	for(int i = 0; i < n; i++){
		cin >> x;
		e[i] = x;
	}
	for(int i = 0; i < n; i++){
		cin >> x;
		l[i] = x;
	}
	sort(e,e+n,greater<int>());
	sort(l,l+n);
	for(int i = 0; i < n; i++){
		out += l[i]*e[i];
	}
	cout << out;
}