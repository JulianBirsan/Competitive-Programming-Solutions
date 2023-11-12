#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;

int low[101],id[101],num[101][101];
bool seen[101];
int out=0;
int cur=0;

void dfs(int at,int n,int prev){
	seen[at]=true; id[at]=low[at]=cur; cur++;
	for(int i=1;i<=n;i++){
		if(num[at][i]!=0){
			if(!seen[i]) dfs(i,n,at);
			if(i!=prev){
				low[at]=min(low[at],low[i]);
			}
		}
	}
}

void find(int at,int n){
	seen[at]=true;
	for(int i=1;i<=n;i++){
		if(!seen[i]&&low[i]!=low[at]){
			out+=num[i][at]==1;
		}
	}
}

void solve(){
	memset(low,0,sizeof(low));
	memset(id,0,sizeof(id));
	memset(num,0,sizeof(num));
	memset(seen,0,sizeof(seen));
	out=0;
	cur=0;
	int n,m;scanf("%d%d",&n,&m);
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		num[x][y]++;num[y][x]++;
	}
	for(int i=1;i<=n;i++){
		if(!seen[i]) dfs(i,n,0);
	}
	memset(seen,0,sizeof(seen));
	for(int i=1;i<=n;i++){
		if(!seen[i]) find(i,n);
	}
	cout<<out<<"\n";
}

int main(){
	int i=5;
	while(i--) solve();
}