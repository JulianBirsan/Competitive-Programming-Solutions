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

vector<int> graph[mxN];

int up[mxN][20],ht[mxN];

void dfs(int at,int p){
    up[at][0]=~p?p:at;
    for(int i=1;i<20;i++)
        up[at][i]=up[up[at][i-1]][i-1];
    for(int &i:graph[at]){
        if(i==p)
            continue;
        ht[i]=ht[at]+1;
        dfs(i,at);
    }
}

int jump(int a,int k){
    for(int i=0;i<20;i++){
        if(k&(1<<i))
            a=up[a][i];
    }
    return a;
}

int lca(int a,int b){
    if(ht[b]<ht[a])
        swap(a,b);
    b=jump(b,ht[b]-ht[a]);
    if(a==b)
        return a;
    for(int i=19;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;
    for(int i=2;i<=n;i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1,-1);
    while(q--){
        int a,b; cin>>a>>b;
        int p=lca(a,b);
        cout<<ht[a]+ht[b]-2*ht[p]<<"\n";
    } 
}
