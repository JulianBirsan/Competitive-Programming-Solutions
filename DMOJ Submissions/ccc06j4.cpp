#include <bits/stdc++.h>

using namespace std;

vector<int> visitedNodes;
vector<bool> visitt;

void dfs(int at, vector<vector<int> > graph,int first){
	for(int i = 0; i < graph[at].size(); i++){
		if(graph[at][i]==first){
			cout << "Cannot complete these tasks. Going to bed.";
			exit(0);
		}
		if(!visitt[graph[at][i]]){
			visitt[graph[at][i]] = true;
			dfs(graph[at][i],graph,first);
		}
	}
	visitedNodes.push_back(at);
}

vector<int> topsort(vector<vector<int> > graph){
	vector<int> order;
	for(int i = 0; i <8; i++){
		order.push_back(0);
		visitt.push_back(false);
	}
	int index = 7;
	for(int i = 7; i >= 1; i--){
		if(!visitt[i]){
			visitt[i] = true;
			visitedNodes.clear();
			dfs(i,graph,i);
			for(int j = 0; j < visitedNodes.size(); j++){
				order[index] = visitedNodes[j];
				index--;
			}
		}
	}
	return order;
}

int main(){
	vector<vector<int> > graph;
	vector<int> temp;
	for(int i = 0; i < 8; i++){
		graph.push_back(temp);
	}
	graph[1].push_back(7);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	int x,y;
	cin >> x >> y;
	while(x!=0 && y!=0){
		graph[x].push_back(y);
		cin >> x >> y;
	}

	for(int i = 1; i <=7; i++){
		sort(graph[i].rbegin(),graph[i].rend());
	}
//
//	for(int i= 0; i < 8; i++){
//		cout << i << ": ";
//		for(int j = 0; j < graph[i].size(); j++){
//			cout << graph[i][j] << " ";
//		}
//		cout << "\n";
//	}

	vector<int> ordering = topsort(graph);
	for(int i = 0; i <= 7; i++){
		if(ordering[i]!=0){
			cout << ordering[i] << " ";
		}
	}
}