#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++) scan(v[i])
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ldb;

const int mx=2e4+1;

vi graph[mx];
int sz[mx],par[mx],n,u,v;

void dfs(int at,int prev){
    sz[at]=1;
    for(int i:graph[at]){
        if(i==prev) continue;
        par[i]=at;
        dfs(i,at);
        sz[at]+=sz[i];
    }
}

int main(){
    IOS;
    scan(n);
    memset(par,-1,sizeof(par));
    FOR(i,0,n-1){
        scan(u,v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,-1);
    int ans=MAXN,node=0;
    FOR(i,1,n+1){
        int cur=0;
        for(int u:graph[i]){
            if(u==par[i]) continue;
            cur=max(cur,sz[u]);
        }
        if(par[i]!=-1){
            cur=max(cur,n-sz[i]);
        }
        if(cur<ans){
            ans=cur;
            node=i;
        }
    }
    cout<<node<<" "<<ans<<"\n";
}