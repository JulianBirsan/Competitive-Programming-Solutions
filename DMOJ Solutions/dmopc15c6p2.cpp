#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	double tot = 0;
	for(int i = 0; i < n; i ++){
		double tilt;
		cin >> tilt;
		tot += fmod(tilt,360);
	}
	cout << fmod(tot,360);
    return 0;
}