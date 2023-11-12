#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m,a,b,x,y;
	cin >> n >> m >> a >> b;
	string out;
	if(a==b){
		out = "GO SHAHIR!";
	}
	else{
		out = "NO SHAHIR!";
	}

	int adj[n][n];

	memset(adj,0,sizeof(adj[0][0])* n * n);

	for(int i = 0; i < m; i++){
		cin >> x >> y;
		adj[x-1][y-1] = 1;
		adj[y-1][x-1] = 1;
	}

	vector<int> q;
	q.push_back(a-1);

	while(q.size()>0 && out == "NO SHAHIR!"){
		int at = q[0];
		for(int i = 0; i < n; i++){
			if(adj[at][i]==1){
				if(i==b-1){
					out = "GO SHAHIR!";
					break;
				}
				adj[q[0]][i]=0;
				q.push_back(i);
			}
		}
		q.erase(q.begin());
	}

	cout << out;
}