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

const int mxN=5e2+5; //make sure this is right
const int mod=1e9+7;

vector<pll> graph[mxN];
ll dist[mxN][mxN],seen[mxN],n;
ll adj[mxN][mxN];

void dik(int src){
    memset(seen,0,sizeof(seen));
    for(int i=1;i<=n;i++)
        dist[src][i]=1e18;
    dist[src][src]=0;
    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({0,src});
    while(!q.empty()){
        int at=q.top().second;
        q.pop();
        if(seen[at])
            continue;
        seen[at]=1;
        for(auto &[i,w]:graph[at]){
            if(dist[src][at]+w<dist[src][i]){
                dist[src][i]=dist[src][at]+w;
                q.push({dist[src][i],i});
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j]=1e12;
        }
    }
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        mina(adj[a][b],c);
        mina(adj[b][a],c);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adj[i][j]==1e12)
                continue;
            graph[i].pb({j,(int)adj[i][j]});
        }
    }
    for(int i=1;i<=n;i++)
        dik(i);
    while(q--){
        int a,b; cin>>a>>b;
        cout<<(dist[a][b]==1e18?-1:dist[a][b])<<"\n";
    }
}
