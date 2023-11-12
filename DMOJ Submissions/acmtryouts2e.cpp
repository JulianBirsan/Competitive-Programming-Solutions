#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<bool> vb;

int xcombo[4] = {0,0,1,-1};
int ycombo[4] = {-1,1,0,0};

void solve(){
	int out = MAXN;
	int h,w;
	scanf("%d %d",&h,&w);
	string row;
	char grid[h][w];
	bool processed[h][w];
	int dist[h][w], m1[h][w],m2[h][w];
	pii min1 = make_pair(-1,-1);
	pii min2 = make_pair(-1,-1);
	pii start,end;
	for(int i = 0; i < h; i++){
		cin >> row;
		for(int j = 0; j < w; j++){
			grid[i][j] = row[j];
			processed[i][j] = grid[i][j] == 'W' || grid[i][j] == 'M';
			dist[i][j] = m1[i][j] = m2[i][j] = MAXN;
			if(grid[i][j] == 'M'){
				if(min1.first==-1){
					min1.first = i; min1.second = j;
				}
				else{
					min2.first = i; min2.second = j;
				}
			}
			else if(grid[i][j] == 'P'){
				start = make_pair(i,j);
			}
			else if(grid[i][j] == 'C'){
				end = make_pair(i,j);
			}
		}
	}
	queue<pii> q;
	dist[start.first][start.second] = m1[min1.first][min1.second] = m2[min2.first][min2.second] = 0;
	q.push(min1);
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x+xcombo[i];
			int yy = y+ycombo[i];
			if(xx>=0 && xx<h && yy>=0 &&yy<w){
				if(m1[x][y]+1<m1[xx][yy] && !processed[xx][yy]){
					m1[xx][yy] = m1[x][y] + 1;
					q.push(make_pair(xx,yy));
				}
			}
		}
	}
	q.push(min2);
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x+xcombo[i];
			int yy = y+ycombo[i];
			if(xx>=0 && xx<h && yy>=0 &&yy<w){
				if(m2[x][y]+1<m2[xx][yy] && !processed[xx][yy]){
					m2[xx][yy] = m2[x][y] + 1;
					q.push(make_pair(xx,yy));
				}
			}
		}
	}
	q.push(start);
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		processed[x][y] = true;
		if(make_pair(x,y)==end) out = min(out,dist[x][y]);
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x+xcombo[i];
			int yy = y+ycombo[i];
			if(xx>=0 && xx<h && yy>=0 &&yy<w){
				if(!processed[xx][yy] && dist[x][y]+1 < dist[xx][yy]){
					if(grid[xx][yy]=='U' || grid[x][y]=='U'){
						if(m1[x][y] > m1[xx][yy] || m2[x][y] > m2[xx][yy]){
							dist[xx][yy] = dist[x][y] + 1;
							q.push(make_pair(xx,yy));
						}
					}
					else{
						dist[xx][yy] = dist[x][y] + 1;
						q.push(make_pair(xx,yy));
					}
				}
				else if(dist[x][y] + 1 < dist[xx][yy] && grid[xx][yy]!='W' && grid[xx][yy]!='M'){
					if(grid[xx][yy]=='U' || grid[x][y]=='U'){
						if(m1[x][y] > m1[xx][yy] || m2[x][y] > m2[xx][yy]){
							dist[xx][yy] = dist[x][y] + 1;
							q.push(make_pair(xx,yy));
						}
					}
					else{
						dist[xx][yy] = dist[x][y] + 1;
						q.push(make_pair(xx,yy));
					}
				}
			}
		}
	}
	if(dist[end.first][end.second]==MAXN) cout << "terran so broken, apologize for playing this race\n";
	else cout <<  "pwned you in " << out << " seconds eZ, learn to play n00b\n";
}

int main(){
	int t; scanf("%d",&t);
	for(int i = 0; i < t; i++){
		solve();
	}
}