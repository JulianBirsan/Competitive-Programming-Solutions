#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> Size;

int find(int x){
	while(x!=parent[x]) x = parent[x];
	return x;
}

void unite(int x, int y){
	int xset = find(x);
	int yset = find(y);
	if(Size[xset]>Size[yset]){
		parent[yset] = xset;
		Size[xset] += Size[yset];
	}
	else{
		parent[xset] = yset;
		Size[yset] += Size[xset];
	}

}

bool same(int x, int y){
	return find(x) == find(y);
}

int main(){
	int n,m;
	int x,y;
	cin >> n >> m;
	vector<int> out;
	for(int i = 0; i <= n; i++) {
		parent.push_back(i);
		Size.push_back(1);
	}
	for(int i = 1; i <= m; i++){
		scanf("%i %i",&x,&y);
		if(!same(x,y)){
			unite(x,y);
			out.push_back(i);
		}
	}
	for(int i = 2; i <= n; i++){
		if(!same(1,i)){
			cout << "Disconnected Graph\n";
			exit(0);
		}
	}
	for(int i = 0; i < out.size(); i++){
		printf("%i\n",out[i]);
	}
}