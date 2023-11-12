#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);

	int c;
	int r;
	cin >> c;
	cin >> r;

	int x;
	int y;
	cin >> x;
	cin >> y;
	int atx = 0;
	int aty = 0;

	while(x!=0 or y!=0){
		atx += x;
		aty += y;
		atx = min(atx,c);
		atx = max(atx,0);
		aty = min(aty,r);
		aty = max(aty,0);
		cout << atx << " " << aty << "\n";
		cin >> x;
		cin >> y;
	}
    return 0;
}