#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x,y;
	cin >> x >> y;
	int out = 0;
	while(x>=y){
		out++;
		int temp = y;
		y = x-y;
		x = temp;
	}
	cout << out + 2;
}