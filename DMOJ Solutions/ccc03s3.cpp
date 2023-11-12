#include <bits/stdc++.h>

using namespace std;

vector<vector<char> > grid;

int bfs(vector<int> at,int r, int c){
	vector<vector<int> > q;
	q.push_back(at);
	int tot = 0;
	int xcombo[4] = {0,0,1,-1};
	int ycombo[4] = {-1,1,0,0};
	while(q.size()>0){
		for(int i = 0; i < 4; i++){
			int xx = q[0][0] + xcombo[i];
			int yy = q[0][1] + ycombo[i];
			if(xx>=0 && xx <r && yy>=0 && yy < c){
				if(grid[xx][yy]=='.'){
					grid[xx][yy] = 'I';
					vector<int> temp;
					temp.push_back(xx);
					temp.push_back(yy);
					q.push_back(temp);
					tot++;
				}
			}
		}
		q.erase(q.begin());
	}
	return tot;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int s;
	int r;
	int c;
	cin >> s;
	cin >> r;
	cin >> c;
	vector<vector<int> > space;

	for(int i = 0; i < r; i++){
		vector<char> temp;
		for(int j = 0; j < c; j++){
			char cell;
			cin >> cell;
			temp.push_back(cell);
			if(cell=='.'){
				vector<int> ttemp;
				ttemp.push_back(i);
				ttemp.push_back(j);
				space.push_back(ttemp);
			}
		}
		grid.push_back(temp);
	}

	vector<int> order;

	for(unsigned int i = 0; i < space.size(); i++){
		if(grid[space[i][0]][space[i][1]]=='.'){
			int num = bfs(space[i],r,c);
			order.push_back(num);
		}
	}
	sort(order.rbegin(),order.rend());
	int sc = s;
	for(unsigned int i = 0; i < order.size(); i++){
		if(order[i]<=sc){
			sc -= order[i];
			if(i==order.size()-1){
				if(i==1){
					cout << i + 1<< " room, " << s - space.size() << " square metre(s) left over";
					break;
				}
				else{
					cout << i + 1 << " rooms, " << s - space.size() << " square metre(s) left over";
					break;
				}
			}
		}
		else{
			if(i==1){
				cout << i << " room, " << sc << " square metre(s) left over";
				break;
			}
			else{
				cout << i << " rooms, " << sc << " square metre(s) left over";
				break;
			}
		}
	}
}