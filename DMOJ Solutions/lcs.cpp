#include <bits/stdc++.h>

using namespace std;

int dp(vector<int> x, vector<int> y){
	int lx = x.size(); int ly = y.size();
	int L[lx+1][ly+1];

	for(int i = 0; i <= lx; i++){
		for(int j = 0; j <= ly; j++){
			if(i==0 || j==0){
				L[i][j] = 0;
			}
			else if(x[i-1] == y[j-1]){
				L[i][j] = L[i-1][j-1] + 1;
			}
			else{
				L[i][j] = max(L[i-1][j],L[i][j-1]);
			}
		}
	}
	return L[lx][ly];
}

int main(){
	int n,m,a;
	cin >> n >> m;
	vector<int> x,y;
	for(int i = 0; i < n; i++){
		cin >> a;
		x.push_back(a);
	}
	for(int i = 0; i < m; i++){
		cin >> a;
		y.push_back(a);
	}
	int res = dp(x,y);
	cout << res << "\n";
}