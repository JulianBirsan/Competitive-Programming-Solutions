#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,r,c,row,col,xx,yy;
	int xcombo[4] = {0,0,1,-1};
	int ycombo[4] = {-1,1,0,0};
	char x;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> r >> c;
		int grid[r][c];
		int dist[r][c];
		bool visit[r][c];
		vector<vector<int> > q;
		vector<int> first;
		q.clear();
		first.clear();
		first.push_back(0);
		first.push_back(0);
		q.push_back(first);
		for(int j = 0; j < r; j++){
			for(int k = 0; k < c; k++){
				cin >> x;
				grid[j][k] = x;
				dist[j][k] = -1;
				if(x=='*'){
					visit[j][k] = true;
				}
				else{
					visit[j][k] = false;
				}
			}
		}
		dist[0][0] = 1;

		while(!q.empty()){
			row = q[0][0];
			col = q[0][1];
			q.erase(q.begin());
			if(grid[row][col]=='+'){
				for(int j = 0; j < 4; j++){
					xx = row + xcombo[j];
					yy = col + ycombo[j];
					if(xx>=0 && xx<r && yy>=0 && yy<c){
						if(!visit[xx][yy]){
							visit[xx][yy] = true;
							dist[xx][yy] = dist[row][col] + 1;
							vector<int> temp;
							temp.push_back(xx);
							temp.push_back(yy);
							q.push_back(temp);
						}
					}
				}
			}
			else if(grid[row][col]=='-'){
				for(int j = 0; j < 2; j++){
					xx = row + xcombo[j];
					yy = col + ycombo[j];
					if(xx>=0 && xx<r && yy>=0 && yy<c){
						if(!visit[xx][yy]){
							visit[xx][yy] = true;
							dist[xx][yy] = dist[row][col] + 1;
							vector<int> temp;
							temp.push_back(xx);
							temp.push_back(yy);
							q.push_back(temp);
						}
					}
				}
			}
			else{
				for(int j = 2; j < 4; j++){
					xx = row + xcombo[j];
					yy = col + ycombo[j];
					if(xx>=0 && xx<r && yy>=0 && yy<c){
						if(!visit[xx][yy]){
							visit[xx][yy] = true;
							dist[xx][yy] = dist[row][col] + 1;
							vector<int> temp;
							temp.push_back(xx);
							temp.push_back(yy);
							q.push_back(temp);
						}
					}
				}
			}
		}
		cout << dist[r-1][c-1] << "\n";
	}
}