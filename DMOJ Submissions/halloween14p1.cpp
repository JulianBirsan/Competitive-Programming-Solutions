#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n,k;
	cin >> n >> k;
	if(n>=k){
		long long int down = n%k;
		long long int up = (n/k+1)*k-n;
		cout << min(up,down);
	}
	else{
		cout << k-n;
	}

}