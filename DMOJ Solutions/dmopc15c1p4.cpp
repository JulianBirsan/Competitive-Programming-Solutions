#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
	if(x==1){
		return false;
	}
	for(int i = 2; i <= sqrt(x); i++){
		if(x%i==0){
			return false;
		}
	}
	return true;

}

int main(){
	int n,x;
	cin >> n >> x;
	int out = 0;
	for(int i = 1; i <= n; i++){
		if(isPrime(i)){
			if(n-i>0){
				out += (n-i)/x + 1;
			}
			else{
				out++;
			}
			if(n-1-i>0){
				out += (n-1-i)/x + 1;
			}
			else if(n-1-i==0){
				out++;
			}
		}
	}
	cout << out;
}