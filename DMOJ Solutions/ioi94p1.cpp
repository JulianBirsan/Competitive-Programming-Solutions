#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int grid[n+1][n+1];
	memset(grid,0,sizeof(grid[0][0])*(n+1)*(n+1));
	int mid;
	if(n%2==0) mid = n/2;
	else{
		mid = n/2+1;
	}
	int out = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin >> grid[i][j];
			grid[i][j] += max(grid[i-1][j],grid[i-1][j-1]);
			out = max(out,grid[i][j]);

		}
	}
	cout << out << "\n";
}