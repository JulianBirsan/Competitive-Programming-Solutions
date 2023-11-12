#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

int Find(int i){
	if(parent[i]==-1){
		return i;
	}
	int result = Find(parent[i]);
	parent[i] = result;
	return result;
}

void Union(int x, int y){
	int xset = Find(x);
	int yset = Find(y);
	if(xset!=yset){
		parent[xset] = yset;
	}
}

int main(){
	int n,q,x,y;
	char c;
	scanf("%i %i",&n,&q);
	vector<int> temp;
	for(int i = 0; i <= n; i++){
		parent.push_back(-1);
	}
	for(int i = 0; i < q; i++){
		cin >> c;
		scanf("%i %i",&x,&y);
		if(c=='A'){
			Union(x,y);
		}
		else{
			if(Find(x)==Find(y)){
				printf("Y\n");
			}
			else{
				printf("N\n");
			}
		}
	}
}