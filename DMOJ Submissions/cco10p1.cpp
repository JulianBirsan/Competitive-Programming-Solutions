#include <bits/stdc++.h>

using namespace std;

vector<int> delay;
vector<vector<int> > graph;
vector<int> status;
vector<int> barkTime;
vector<set<int> > due;

int main(){
	int t,d,w,f,a,b;
	vector<int> temp;
	scanf("%i",&d);
	for(int i = 0; i <= d; i++){
		graph.push_back(temp);
		barkTime.push_back(0);
		delay.push_back(0);
		status.push_back(0);
	}
	for(int i = 1; i <= d; i++){
		scanf("%i",&w); delay[i] = w;
	}
	scanf("%i",&f);
	for(int i = 0; i < f; i++){
		scanf("%i %i",&a,&b);
		graph[a].push_back(b);
	}
	scanf("%i",&t);
	set<int> ttemp;
	for(int i = 0; i <= t; i++){
		due.push_back(ttemp);
	}
	due[0].insert(1);
	for(int i = 0; i <= t; i++){
		for(auto u: due[i]){
			barkTime[u]++;
			status[u] = 0;
			for(auto j: graph[u]){
				if(status[j]==0 && due[i].count(j)==0){
					status[j]=-1;
					if(i+delay[j]<=t){
						due[i+delay[j]].insert(j);
					}
				}
			}
		}
	}
	for(int i = 1; i <= d; i++){
		cout << barkTime[i] << "\n";
	}
}