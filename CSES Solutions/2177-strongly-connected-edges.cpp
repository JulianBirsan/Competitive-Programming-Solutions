#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr<<vars<<" = ";
    string delim="";
    (...,(cerr<<delim<<values,delim=", "));
    cerr<<"\n";
}
#else
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {}
#endif

#define pb push_back
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=2e5+5; //make sure this is right
const int mod=1e9+7;

vector<pii> graph[mxN];
vector<int> strong[mxN];

int seen[mxN],A[mxN],B[mxN],id[mxN],low[mxN],cur;

void dfs(int at){
    seen[at]=1;
    for(auto &[v,i]:graph[at]){
        if(A[i]) continue;
        A[i]=at; B[i]=v;
        strong[at].pb(v);
        if(!seen[v]) dfs(v);
    }
}

void check(int at){
    id[at]=++cur; low[at]=id[at];
    for(int &i:strong[at]){
        if(!id[i]) check(i);
        if(low[i]>id[at]){
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
        mina(low[at],low[i]);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        graph[a].pb({b,i});
        graph[b].pb({a,i});
    }
    for(int i=1;i<=n;i++){
        if(!seen[i]) dfs(i);
    }
    check(1);
    for(int i=1;i<=n;i++){
        if(!id[i]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    for(int i=0;i<m;i++){
        cout<<A[i]<<" "<<B[i]<<"\n";
    }
}
