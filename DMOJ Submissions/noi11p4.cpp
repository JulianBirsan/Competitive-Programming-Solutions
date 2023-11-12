#include <bits/stdc++.h>

using namespace std;

#define rng(x) x.begin(),x.end()
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

struct q{
	int a,b,c;
};

vi parent,sz;
vector<vi> graph;
ll num[1000001];
ll level[1000001];
bool seen[1000001];
q query[1000000];
ll ans=0;

void dfs(int cur, int pre){
    num[cur] = 1;
    for (int i : graph[cur]){
        if (i != pre){
            level[i] = level[cur] + 1;
            dfs(i, cur);
            num[cur] += num[i];
        }
    }
}


int main(){
	memset(seen,0,sizeof(seen));
	int n; scanf("%d",&n);
	vi temp;
	for(int i=0;i<=n;i++){
		num[i]=1;
		parent.push_back(i);
		sz.push_back(1);
		graph.push_back(temp);
	}
	for(int i=0;i<n-1;i++){
		q Q;
		scanf("%d%d%d",&Q.a,&Q.b,&Q.c);
		query[i]=Q;
		graph[Q.a].push_back(Q.b);
		graph[Q.b].push_back(Q.a);
	}
	dfs(1,-1);
	for(int i=0;i<n-1;i++){
		q Q=query[i];
		if(level[Q.a]>level[Q.b]){
			ans+=Q.c*(abs(num[Q.a]-(n-num[Q.a])));
		}
		else{
			ans+=Q.c*(abs(num[Q.b]-(n-num[Q.b])));
		}
	}
	cout<<ans<<"\n";
}