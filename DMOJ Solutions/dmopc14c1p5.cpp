#include <bits/stdc++.h>

using namespace std;

int main(){
	unordered_map<string,bool> tp;
	int r,c,t,a,b,x,y,xx,yy,u,o;
	int tdist = numeric_limits<int>::max();
	int edist;
	int xcombo[4] = {0,0,1,-1};
	int ycombo[4] = {-1,1,0,0};
	vector<int> start,end;
	vector<vector<int> > q;
	string s,temps;
	cin >> r >> c;
	cin >> a >> b;
	char arr[r][c];
	bool visit[r][c];
	int dist[r][c];
	memset(dist,0,sizeof(dist[0][0])*r*c);
	start.push_back(a);
	start.push_back(b);
	cin >> a >> b;
	end.push_back(a);
	end.push_back(b);
	for(int i = 0; i < r; i++){
		cin >> s;
		for(int j = 0; j < c; j++){
			arr[i][j] = s[j];
			if(s[j]=='O'){
				visit[i][j] = false;
			}
			else{
				visit[i][j] = true;
			}
		}
	}
	cin >> t;
	for(int i = 0; i < t; i++){
		temps = "";
		cin >> u >> o;
		temps += to_string(u) + " " + to_string(o);
		tp[temps] = true;
	}
	q.push_back(start);
	while(!q.empty()){
		x = q[0][0];
		y = q[0][1];
		temps = "";
		temps += to_string(x) + " " + to_string(y);
		if(tp[temps]){
			tdist = min(dist[x][y],tdist);
		}
		q.erase(q.begin());
		for(int i = 0; i < 4; i++){
			xx = x + xcombo[i];
			yy = y + ycombo[i];
			if(xx>=0 && xx < r && yy>=0 && yy<c){
				if(!visit[xx][yy]){
					visit[xx][yy] = true;
					dist[xx][yy] = dist[x][y] + 1;
					vector<int> temp;
					temp.push_back(xx);
					temp.push_back(yy);
					if(temp==end){
						edist = dist[xx][yy];
					}
					q.push_back(temp);
				}
			}
		}
	}
	cout << max(edist-tdist,0);
}