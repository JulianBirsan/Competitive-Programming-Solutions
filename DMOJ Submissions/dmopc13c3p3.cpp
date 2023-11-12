#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,h,x,r,c,xx,yy;
	cin >> n >> h;
	int arr[n][n];
	bool visit[n][n];
	int xcombo[4] = {0,0,-1,1};
	int ycombo[4] = {1,-1,0,0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> x;
			arr[i][j] = x;
			visit[i][j] = false;
		}
	}
	vector<vector<int> > q;
	vector<int> start;
	start.push_back(0);
	start.push_back(0);
	q.push_back(start);

	while(!q.empty()){
		r = q[0][0];
		c = q[0][1];
		q.erase(q.begin());
		for(int i = 0; i < 4; i++){
			xx = r + xcombo[i];
			yy = c + ycombo[i];
			if(xx>=0 && xx<n && yy>=0 && yy<n){
				if(!visit[xx][yy] && abs(arr[r][c]-arr[xx][yy])<=h){
					visit[xx][yy] = true;
					vector<int> temp;
					temp.push_back(xx);
					temp.push_back(yy);
					q.push_back(temp);
				}
			}
		}
	}
	if(visit[n-1][n-1]){
		cout << "yes";
	}
	else{
		cout << "no";
	}
}