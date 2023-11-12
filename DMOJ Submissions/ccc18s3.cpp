#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
vector<vector<char> > graph;
vector<vector<bool> > processed;
vector<vector<int> > dist;
int n,m;
int xcombo[4] = {0,0,1,-1};
int ycombo[4] = {-1,1,0,0};

void dfs(pair<int,int> at){
	int x = at.first; int y = at.second;
	if(graph[x][y]=='L'){
		if(!processed[x][y-1] || dist[x][y] < dist[x][y-1]){
			processed[x][y-1] = true; dist[x][y-1] = dist[x][y];
			pair<int,int> temp(x,y-1); dfs(temp);
		}
	}
	else if(graph[x][y]=='R'){
		if(!processed[x][y+1] || dist[x][y] < dist[x][y+1]){
			processed[x][y+1] = true; dist[x][y+1] = dist[x][y];
			pair<int,int> temp(x,y+1); dfs(temp);
		}
	}
	else if(graph[x][y]=='U'){
		if(!processed[x-1][y] || dist[x][y] < dist[x-1][y]){
			processed[x-1][y] = true; dist[x-1][y] = dist[x][y];
			pair<int,int> temp(x-1,y); dfs(temp);
		}
	}
	else if(graph[x][y]=='D'){
		if(!processed[x+1][y] || dist[x][y] < dist[x+1][y]){
			processed[x+1][y] = true; dist[x+1][y] = dist[x][y];
			pair<int,int> temp(x+1,y); dfs(temp);
		}
	}
	else{
		for(int i = 0; i < 4; i++){
			int xx = x+xcombo[i]; int yy = y+ycombo[i];
			if(!processed[xx][yy] || dist[x][y]+1 < dist[xx][yy]){
				processed[xx][yy] = true; dist[xx][yy] = dist[x][y] + 1;
				pair<int,int> temp(xx,yy); dfs(temp);
			}
		}
	}
}

int main(){
	vector<pair<int,int> > out;
	scanf("%i %i",&n,&m);
	char c;
	string s;
	pair<int,int> start;
	for(int i = 0; i < n; i++){
		vector<char> temp;
		vector<bool> ttemp;
		vector<int> tttemp;
		cin >> s;
		for(int j = 0; j < m; j++){
			c = s[j];
			if(c=='S') start = make_pair(i,j);
			else if(c=='.') {
				out.push_back(make_pair(i,j));
			}
			temp.push_back(c);
			if(c=='W' || c=='C'){
				ttemp.push_back(true);
			}
			else ttemp.push_back(false);
			tttemp.push_back(-1);
		}
		graph.push_back(temp); processed.push_back(ttemp); dist.push_back(tttemp);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j]=='C'){
				for(int k = i+1; k < n; k++){
					if(graph[k][j]=='.' || graph[i][k]=='S') processed[k][j] = true;
					else if(graph[k][j]=='W') break;
				}
				for(int k = i-1; k >= 0; k--){
					if(graph[k][j]=='.' || graph[i][k]=='S') processed[k][j] = true;
					else if(graph[k][j]=='W') break;
				}
				for(int k = j+1; k < m; k++){
					if(graph[i][k]=='.' || graph[i][k]=='S') processed[i][k] = true;
					else if(graph[i][k]=='W') break;
				}
				for(int k = j-1; k >= 0; k--){
					if(graph[i][k]=='.' || graph[i][k]=='S') processed[i][k] = true;
					else if(graph[i][k]=='W') break;
				}
			}
		}
	}
	dist[start.first][start.second] = 0;
	if(!processed[start.first][start.second]) {
		processed[start.first][start.second] = true;
		dfs(start);
	}
	for(int i = 0; i < out.size(); i++){
		int x = out[i].first; int y = out[i].second;
		if(dist[x][y]==MAXN) cout << -1 << "\n";
		else cout << dist[x][y] << "\n";
	}
}