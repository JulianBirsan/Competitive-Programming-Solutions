#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i;
	cin >> i;
	if(i>5){
		i = 10 - i;
	}
	if(i<=1){
		cout << 1;
	}
	else{
		cout << i/2 + 1;
	}
}