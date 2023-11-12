#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i;
	cin >> i;
	double out = 0;
	for(int k = 0; k < i; k++){
		double m;
		cin >> m;
		out += m;
	}
	int s;
	cin >> s;
	for(int k = 1; k <= s; k++){
		double m;
		cin >> m;
		out += m;
		cout << out/(i+k) << "\n";
	}
    return 0;
}