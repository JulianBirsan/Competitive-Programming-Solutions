#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<double> dp;

void branch(int at){
	int it = graph[at].size();
	if(it > 0){
		for(int i = 0; i < it; i++){
			dp[graph[at][i]] += dp[at]/it;
		}
	}
	else{
		printf("%.10f\n",dp[at]);
	}
}

int main(){
	int n,m,x,y;
	scanf("%i %i",&n,&m);
	vector<int> temp;
	for(int i = 0; i <= n; i++){
		graph.push_back(temp);
		dp.push_back(0);

	}
	for(int i = 0; i < m; i++){
		scanf("%i %i", &x,&y);
		graph[x].push_back(y);
	}
	dp[1] = 1;
	for(int i = 1; i <= n; i++){
		branch(i);
	}
}