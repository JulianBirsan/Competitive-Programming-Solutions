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

const int mxN=1e5+5; //make sure this is right
const int mod=1e9+7;

vector<int> graph[mxN];
int seen[mxN],par[mxN],yes;

void dfs(int at){
    if(yes)
        return;
    seen[at]=1;
    for(int &i:graph[at]){
        if(yes)
            return;
        if(!seen[i]){
            par[i]=at;
            dfs(i);
        } else if(seen[i]==1){
            par[i]=at;
            yes=i;
            return;
        }
    }
    seen[at]=2;
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
        graph[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        if(!seen[i])
            dfs(i);
    }
    if(!yes){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    int f=yes;
    while(par[f]!=yes){
        ans.pb(f);
        f=par[f];
    }
    ans.pb(f);
    ans.pb(yes);
    reverse(ans.begin(),ans.end());
    cout<<sz(ans)<<"\n";
    for(int &i:ans)
        cout<<i<<" ";
}
