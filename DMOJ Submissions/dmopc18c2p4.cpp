#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n,m,x,l,r;
	long long int out = numeric_limits<long long int>::max();
	cin >> n >> m;
	long long int psa[n+1];
	psa[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		psa[i+1] = x + psa[i];
	}
	l = 1;
	r = 1;
	while(l<=r){
		if(psa[r]-psa[l-1]>=m){
			out = min(out,r-l+1);
			if(l==n){
				break;
			}
			l++;
		}
		else{
			if(r==n){
				break;
			}
			r++;
		}
	}
	if(out == numeric_limits<long long int>::max()){
		cout << -1;
		exit(0);
	}
	cout << out;
}