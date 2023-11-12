#include <bits/stdc++.h>

using namespace std;

int r,l;
set<vector<bool> > taken;
int out = 1;

void recur(vector<vector<bool> > grid, int at){
	if(at==r){
		if(taken.count(grid[at-1])==0){
			out++; taken.insert(grid[at-1]);
		}
	}
	else{
		for(int i = 0; i < l; i++){
			if(grid[at-1][i]==grid[at][i]){
				grid[at][i] = false;
			}
			else{
				grid[at][i] = true;
			}
		}
		recur(grid,at+1);
	}

}

int main(){
	int x;
	cin >> r >> l;
	vector<vector<bool> > grid;
	for(int i = 0; i < r; i++){
		vector<bool> temp;
		for(int j = 0; j < l; j++){
			cin >> x; temp.push_back(x);
		}
		grid.push_back(temp);
	}
	taken.insert(grid[r-1]);
	for(int i = 1; i < r; i++){
		recur(grid,i);
	}
	cout << out << "\n";
}