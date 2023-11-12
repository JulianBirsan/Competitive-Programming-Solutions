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
typedef long double ld;

const int mx=2e5+1;

vector<vi> graph(mx),rev(mx);

int n,a,u,v;
ll val[mx];
ll num[mx],totnum[mx],backwrds[mx];
bool seen[mx];
vi order;

void topsort(int at){
    seen[at]=true;
    for(int i:graph[at]){
        if(!seen[i]) topsort(i);
    }
    order.push_back(at);
}

void dfs(int at){
    seen[at]=true;
    for(int i:graph[at]){
        if(!seen[i]) dfs(i);
        totnum[at]+=totnum[i];
    }
    num[at]=val[at]*totnum[at]-val[at];
}

void getBack(int at){
    seen[at]=true;
    backwrds[at]=val[at];
    for(int i:rev[at]){
        if(!seen[i]) getBack(i);
        backwrds[at]+=backwrds[i];
    }
}

ll getval(int at){
    ll ret=0;
    for(int i:rev[at]){
        ret=max(ret,(backwrds[at]-backwrds[i])*(totnum[i]-totnum[at]));
    }
    return ret;
}

int main(){
    IOS;
    scan(n);
    FOR(i,1,n+1){
        scan(val[i]);
        totnum[i]=val[i];
    }
    FOR(i,0,n-1){
        scan(u,v);
        graph[u].push_back(v);
        rev[v].push_back(u);
    }
    FOR(i,1,n+1){
        if(!seen[i]) topsort(i);
    }
    reverse(rng(order));
    fill(seen);
    for(int i:order){
        if(!seen[i]) dfs(i);
    }
    ll ans=0;
    FOR(i,1,n+1) ans+=num[i];
    ll add=0;
    fill(seen);
    for(int i=order.size()-1;i>=0;i--){
        if(!seen[order[i]]) getBack(order[i]);
    }
    FOR(i,1,n+1) add=max(add,getval(i));
    cout<<add+ans<<"\n";
}