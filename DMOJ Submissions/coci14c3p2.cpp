#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,p,f,h;
	vector<int> change;
	cin >> n >> m >> p;
	for(int i = 0; i <= m; i++) change.push_back(-1);
	for(int i = 0; i < n; i++){
		cin >> f >> h;
		if(change[h]==-1) change[h] = f;
	}
	int out = 0;
	while(true){
		int a = change[p];
		if(a==-2){
			cout << -1 << "\n";
			break;
		}
		else if(a==-1){
			cout << out << "\n";
			break;
		}
		else{
			change[p] = -2; p = a; out++;
		}
	}
}