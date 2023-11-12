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

const int mxN=4e5+5; //make sure this is right
const int mod=1e9+7;

vector<int> graph[mxN];

int st[mxN],en[mxN],cur,v[mxN];

struct BIT{
    ll bit[mxN]; 
    void upd(int x,int v){while(x<mxN){bit[x]+=v;x+=x&-x;}}
    ll sum(int x){ll res=0;while(x){res+=bit[x];x-=x&-x;}return res;} 
} bit;

void dfs(int at,int p){
    st[at]=++cur;
    for(int &i:graph[at]){
        if(i==p)
            continue;
        dfs(i,at);
    }
    en[at]=++cur;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=2;i<=n;i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)
        bit.upd(st[i],v[i]);
    while(q--){
        int op; cin>>op;
        if(op==1){
            int x,y; cin>>x>>y;
            bit.upd(st[x],y-v[x]);
            v[x]=y;
        } else{
            int x; cin>>x;
            cout<<bit.sum(en[x])-bit.sum(st[x]-1)<<"\n";
        }
    }
}
