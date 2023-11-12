#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, char at, char to, char aux){
	if(n==1) cout << at << to << "\n";
	else{
		hanoi(n-1,at,aux,to);
		cout << at << to << "\n";
		hanoi(n-1,aux,to,at);
	}
}

int main(){
	int n; cin >> n;
	hanoi(n,'A','C','B');
}