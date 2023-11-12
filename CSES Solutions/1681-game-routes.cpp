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
int deg[mxN],dp[mxN],bad[mxN],go[mxN];

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
        deg[b]++;
    }
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(!deg[i])
            q.push(i);
    }
    while(!q.empty()){
        int at=q.front(); q.pop();
        for(int &i:graph[at]){
            deg[i]--;
            if(!deg[i] && i!=1){
                q.push(i);
            }
        }
    }
    q.push(1); dp[1]=1;
    while(!q.empty()){
        int at=q.front(); q.pop();
        for(int &i:graph[at]){
            dp[i]=(dp[i]+dp[at])%mod;
            deg[i]--;
            if(!deg[i])
                q.push(i);
        }
    }
    cout<<dp[n]<<"\n";
}
