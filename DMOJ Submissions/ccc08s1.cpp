#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;

	unordered_map<int,string> cit;
	int top = 201;

	while(true){
		cin >> s;
		cin >> n;
		cit[n] = s;
		top = min(n,top);
		if(s=="Waterloo"){
			break;
		}
	}
	cout << cit[top];
}