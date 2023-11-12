#include <bits/stdc++.h>

using namespace std;

int main() {
    	cin.sync_with_stdio(0);
	cin.tie(0);
	int r;
	int c;
	cin >> r;
	cin >> c;
	bool x[c];
	bool y[r];
	for(int i = 0; i < c; i++){
		x[i] = true;
	}
	for(int i = 0; i < r; i++){
			y[i] = true;
		}
	for(int i = 0; i < r; i ++){
		for(int j = 0; j < c; j++){
			char p;
			cin >> p;
			if(p == 'X'){

				x[j] = false;
				y[i] = false;
			}
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int xcor;
		int ycor;
		cin >> xcor;
		cin >> ycor;
		if(x[xcor-1] == false || y[ycor-1] == false){
			cout << "Y\n";
		}
		else{
			cout << "N\n";
		}
	}
    return 0;
}