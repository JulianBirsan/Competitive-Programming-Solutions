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

int id[4194306], low[4194306], high[4194306], maximum[4194306];
int arr[1048577];

void build(int at, int l, int h){
	if(l==h){
		maximum[at] = arr[h];
		id[at] = h;
		low[at] = l; high[at] = h;
	}
	else{
		int m = (l+h)/2;
		build(at*2,l,m);
		build(at*2+1,m+1,h);
		if(maximum[at*2+1]<maximum[at*2]){
			maximum[at] = maximum[at*2];
			id[at] = id[at*2];
		}
		else{
			maximum[at] = maximum[at*2+1];
			id[at] = id[at*2+1];
		}
		low[at] = l; high[at] = h;
	}
}

int sim(int at, int ind, int c){
	if(high[at]>=ind && low[at]<=ind){
		if(low[at]==high[at]){
			return c;
		}
		if(id[at]==ind){
			c = max(sim(at*2,ind,c+1),sim(at*2+1,ind,c+1));
		}
		else{
			c = max(sim(at*2,ind,c),sim(at*2+1,ind,c));
		}
	}
	return c;
}

void update(int at, int val, int ind){
	if(high[at]>=ind && low[at]<=ind){
		if(low[at]==high[at]){
			maximum[at] = val;
			return;
		}
		update(at*2,val,ind);
		update(at*2+1,val,ind);
		if(maximum[at*2]>maximum[at*2+1]){
			maximum[at] = maximum[at*2];
			id[at] = id[at*2];
		}
		else{
			maximum[at] = maximum[at*2+1];
			id[at] = id[at*2+1];
		}
	}
}

int main(){
	memset(maximum,0,sizeof(maximum));
	memset(low,0,sizeof(low));
	memset(high,0,sizeof(high));
	memset(id,0,sizeof(id));
	int n,m; scanf("%d %d",&n,&m);
	for(int i = 1; i <= pow(2,n); i++){
		scanf("%d",&arr[i]);
	}
	char inst;
	build(1,1,pow(2,n));
	for(int i = 0; i < m; i++){
		cin >> inst;
		if(inst=='S'){
			int x; cin >> x;
			cout << sim(1,x,0) << "\n";
		}
		else if(inst=='W'){
			cout << id[1] << "\n";
		}
		else{
			int v,x; cin >> x >> v;
			update(1,v,x);
		}
	}
}