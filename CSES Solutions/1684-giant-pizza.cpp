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

vector<int> g[mxN][2];

int a[mxN],b[mxN],X[mxN],Y[mxN],ans[mxN];
vector<int> path;

bool dfs(int at,int t=-1){
    if((ans[a[at]]==(X[at]^1)) && (ans[b[at]]==(Y[at]^1))) return 0;
    if(ans[a[at]]==(X[at])) return 1;
    if(ans[b[at]]==(Y[at])) return 1;
    if(t==0){
        if(ans[a[at]]!=-1) return 0;
        path.pb(a[at]);
        ans[a[at]]=X[at];
        for(int &i:g[a[at]][X[at]^1]){
            if(!dfs(i)) return 0;
        }
        return 1;
    } else if(t==1){
        if(ans[b[at]]!=-1) return 0;
        path.pb(b[at]);
        ans[b[at]]=Y[at];
        for(int &i:g[b[at]][Y[at]^1]){
            if(!dfs(i)) return 0;
        }
        return 1;
    }
    if((ans[a[at]]==(X[at]^1)) && ans[b[at]]==-1){
        ans[b[at]]=Y[at];
        path.pb(b[at]);
        for(int &i:g[b[at]][Y[at]^1]){
            if(!dfs(i)) return 0;
        }
    } else if((ans[b[at]]==(Y[at]^1)) && ans[a[at]]==-1){
        ans[a[at]]=X[at];
        path.pb(a[at]);
        deb(at,X[at]);
        for(int &i:g[a[at]][X[at]^1]){
            if(!dfs(i)) return 0;
        }
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        char x,y;
        cin>>x>>a[i]>>y>>b[i];
        X[i]=(x=='+');
        Y[i]=(y=='+');
        g[a[i]][X[i]].pb(i);
        g[b[i]][Y[i]].pb(i);
    }
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<n;i++){
        if(ans[a[i]]==X[i]) continue;
        if(ans[b[i]]==Y[i]) continue;
        deb(i);
        if(!dfs(i,0)){
            deb(i);
            for(auto &u:path){
                deb(u);
                ans[u]=-1;
            }
            path.clear();
            if(!dfs(i,1)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
        path.clear();
    }
    for(int i=1;i<=m;i++){
        cout<<(ans[i]?'+':'-')<<" ";
    }
}
