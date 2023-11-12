#include <bits/stdc++.h>

using namespace std;

int greedy(int at){
	if(at==1){
		return 0;
	}
	if(at==2){
		return 1;
	}
	if(at%2==0){
		return greedy(at/2)+1;
	}
	for(int i = at/2+1; i<at; i++){
		if(i%(at-i)==0){
			return greedy(i) + i/(at-i);
		}
	}
}

int main(){
	int n;
	cin >> n;
	cout << greedy(n) << "\n";
}