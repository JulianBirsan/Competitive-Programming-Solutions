#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
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
typedef double d;
typedef long double ld;

template<int MAX>
struct Graph{
    int n,m;
    int A[MAX],B[MAX],W[MAX];
    vector<pii> adj[MAX];
    void init(int N,int M) {n=N;m=M;}
    inline void addEdge(int x,int y,int w){adj[x].push_back(pii(y,w));}
    inline vector<pii>& root(int x) { return adj[x]; }
    Graph& operator=(const Graph o) { n = o.n; m = o.m; copy(o.adj, o.adj + n + 1, adj); return *this; }
    void input(bool type){
        FOR(i,0,m){
            scan(A[i],B[i],W[i]);
            addEdge(A[i],B[i],W[i]);
            if(type) addEdge(B[i],A[i],W[i]);
        }
    }
};

const int MAX=100001;
Graph<MAX> g;
ll totDist=0;
ll largestDist=0;
ll dist[MAX];

void dfs(int at,int prev){
    if(g.root(at).size()==1){
        largestDist=max(largestDist,dist[at]);
    }
    for(pii u:g.root(at)){
        if(u.first!=prev){
            dist[u.first]=dist[at]+u.second;
            totDist+=2*u.second;
            dfs(u.first,at);
        }
    }
}

int main(){
    IOS; fill(dist);
    int n; scan(n);
    g.init(n+1,n);
    g.input(1);
    dfs(0,-1);
    cout<<totDist-largestDist<<"\n";
}