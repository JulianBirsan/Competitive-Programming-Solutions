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

vector<vi> edges;
vi parent,Size;

int find(int x){
	while(x!=parent[x]) x = parent[x];
	return x;
}

void unite(int x, int y){
	int xset = find(x);
	int yset = find(y);
	if(Size[xset]>Size[yset]){
		Size[xset]+=Size[yset];
		parent[yset] = xset;
	}
	else{
		Size[yset]+=Size[xset];
		parent[xset] = yset;
 	}
}

bool same(int x, int y){
	return find(x)==find(y);
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i <= n; i++){
		Size.push_back(1);
		parent.push_back(i);
	}
	vi temp;
	int a,b,c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d",&a,&b,&c);
		vi temp;
		temp.push_back(c); temp.push_back(a); temp.push_back(b);
		edges.push_back(temp);
	}
	sort(edges.rbegin(),edges.rend());
	LL out = 0;
	int total = 0;
	for(int i = 0; i < edges.size(); i++){
		int x = edges[i][1]; int y = edges[i][2]; int cost = edges[i][0];
		if(!same(x,y)){
			unite(x,y);
			out += cost;
			total++;
		}
		else if(cost>0){
			out += cost;
		}
	}
	if(total<n-1) cout << "Impossible\n";
	else cout << out << "\n";
}