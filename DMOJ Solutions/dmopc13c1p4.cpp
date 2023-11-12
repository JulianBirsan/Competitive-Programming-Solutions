#include <bits/stdc++.h>

using namespace std;

int xcombo[4] = {0,0,1,-1};
int ycombo[4] = {-1,1,0,0};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,l,w,xx,yy;
	string row;
	bool check;
	vector<vector<int> > q,q2;
	cin >> t;
	for(int i = 0; i < t; i++){
		q.clear();
		q2.clear();
		cin >> l >> w;
		char arr[w][l];
		int dist[w][l];
		memset(dist,0,sizeof(dist[0][0])*w*l);
		vector<int> temp;
		check = false;

		for(int j = 0; j < w; j++){
			cin >> row;
			for(int k = 0; k < l; k++){
				if(row[k]=='C'){
					temp.push_back(j);
					temp.push_back(k);
					q.push_back(temp);
					row[k] = 'X';
				}
				arr[j][k] = row[k];
			}
		}
		if(temp.size()==0){
			cout << "#notworth\n";
			continue;
		}

		while(!q.empty()){

			for(int j = 0; j < 4; j++){
				xx = xcombo[j] + q[0][0];
				yy = ycombo[j] + q[0][1];

				if(xx>=0 && xx<w && yy>=0 && yy<l){
					if(arr[xx][yy]=='W'){
						check = true;
						dist[xx][yy] = dist[q[0][0]][q[0][1]] + 1;
						if(dist[xx][yy]<60){
							cout << dist[xx][yy] << "\n";
						}
						else{
							cout << "#notworth\n";
						}
						break;
					}
					if(arr[xx][yy]=='O'){
						vector<int> temp;
						temp.push_back(xx);
						temp.push_back(yy);
						q2.push_back(temp);
						arr[xx][yy] = 'X';
						dist[xx][yy] = dist[q[0][0]][q[0][1]] + 1;
						if(dist[xx][yy]==60){
							check = true;
							cout << "#notworth\n";
							break;
						}
					}
				}
			}

			q.erase(q.begin());

			if(q.size()==0){
				q = q2;
				q2.clear();
			}
			if(check){
				break;
			}
		}
		if(!check){
			cout << "#notworth\n";
		}
	}
}