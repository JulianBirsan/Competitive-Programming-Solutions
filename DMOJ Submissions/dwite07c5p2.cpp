#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main(){

	int prime[11] = {2,3,5,7,11,13,17,19,23,29,31};

	for(int i = 0; i < 5; i++){
		int n;
		cin >> n;
		int c = 0;
		if(find(begin(prime),end(prime),n) != end(prime)){
			cout << 0 << "\n";
		}
		else{
		while(n>1){
			for(int j = 0; j < 11; j++){
				if(n%prime[j] == 0){
					n = n/prime[j];
					c++;
					break;
				}
			}
		}
		cout << c << "\n";
		}
	}

	return 0;
}