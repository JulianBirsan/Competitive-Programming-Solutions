#include <bits/stdc++.h>

using namespace std;

int n,m;

bool isPrime(int x){
	if(x==1){
		return false;
	}
	if(x<=3){
		return true;
	}
	for(int i = 2; i <= sqrt(x); i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		if(isPrime(m)){
			cout << m << "\n";
		}
		else{
			for(int j = 2; j <=m/2; j++){
				if(m%j==0){
					if(isPrime(j)){
						cout << j << " ";
						m /= j;
						j--;
					}
					if(m<1000000){
						if(isPrime(m)){
							cout << m << " ";
							m = 1;
							break;
						}
					}
				}
			}
			if(isPrime(m)){
				cout << m << " ";
			}

			cout << "\n";
		}
	}
}