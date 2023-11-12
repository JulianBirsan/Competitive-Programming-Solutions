#include <bits/stdc++.h>

using namespace std;

int main() {
    int h;
	cin >> h;
	for(int i = 0; i < h; i++){
		cout << "*";
	}
	cout << "\n";
	int l = h/2-1;
	int r = h/2+1;
	for(int i = 1; i < h-1; i++){
		for(int j = 0; j <h; j++){
			if(j>l && j<r){
				cout << " ";
			}
			else{
				cout << "*";
			}
		}
		if(i <= h/2 -1){
			l--;
			r++;
		}
		else{
			l++;
			r--;
		}
		cout << "\n";
	}
	for(int i = 0; i < h; i++){
			cout << "*";
		}
    return 0;
}