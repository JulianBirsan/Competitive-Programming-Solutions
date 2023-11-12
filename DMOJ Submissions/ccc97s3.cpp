#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t,n;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		int out[3] = {n,0,0};
		int r = 0;
		while(out[2]<n-1){
			cout << "Round " << r << ": " << out[0] << " undefeated, " << out[1] << " one-loss, " << out[2] << " eliminated\n";
			if(out[0]==1 && out[1]==1){
				out[0] = 0;
				out[1] = 2;
			}
			else{
				if(out[1]>1){
					out[2] += out[1]/2;
					out[1] -= out[1]/2;
				}
				if(out[0]>1){
					out[1] += out[0]/2;
					out[0] -= out[0]/2;
				}
			}
			r++;
		}
		cout << "Round " << r << ": " << 0 << " undefeated, " << 1 << " one-loss, " << n-1 << " eliminated\n";
		cout << "There are " << r << " rounds.\n\n";
	}
}