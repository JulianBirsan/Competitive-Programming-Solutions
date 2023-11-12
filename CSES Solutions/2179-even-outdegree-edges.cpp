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

vector<int> graph[mxN],tree[mxN];
int seen[mxN],want[mxN];
vector<pii> ans;

void dfs(int at,int p){
    seen[at]=1;
    for(int &i:graph[at]){
        if(i==p) continue;
        if(seen[i]==1){
            ans.pb({at,i});
            want[at]^=1;
        } else if(!seen[i]){
            tree[at].pb(i);
            dfs(i,at);
        }
    }
    seen[at]=2;
}

void dfs2(int at){
    for(int &i:tree[at]){
        dfs2(i);
        if(want[i]){
            ans.pb({i,at});
        } else{
            want[at]^=1;
            ans.pb({at,i});
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

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(!seen[i]){
            dfs(i,-1);
            dfs2(i);
            if(want[i]){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(auto &u:ans)
        cout<<u.first<<" "<<u.second<<"\n";
}
