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

ll sub[mxN],up[mxN],down[mxN],sub2[mxN];

void dfs(int at,int p){
    sub[at]=1;
    for(int &i:graph[at]){
        if(i==p)
            continue;
        dfs(i,at);
        sub[at]+=sub[i];
        down[at]+=down[i]+sub[i];
    }
}

void dfs2(int at,int p){
    for(int &i:graph[at]){
        if(i==p)
            continue;
        sub2[i]=sub2[at]+sub[at]-sub[i];
        up[i]=up[at]+sub2[at]+down[at]-down[i]-sub[i]+sub[at]-sub[i];
        dfs2(i,at);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    for(int i=2;i<=n;i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        deb(down[i],up[i]);
        cout<<up[i]+down[i]<<" ";
    }
}