#include <bits/stdc++.h>

using namespace std;

void solve(int x,int y1,int y2){
	while(x<=1000){
		cout<<x<<" "<<y1<<" "<<x<<" "<<y2<<"\n";
		x++;
	}
}

int main(){
	cout<<2001<<"\n";
	solve(1,1,2);
	cout<<"1000 1 1000 2\n";
	solve(1,1,2);
}