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
        graph[b].pb(a);
        deg[a]++;
    }
    queue<int> q;
    for(int i=1;i<n;i++){
        if(!deg[i])
            q.push(i);
    }
    while(!q.empty()){
        int at=q.front(); q.pop();
        bad[at]=1;
        for(int &i:graph[at]){
            deg[i]--;
            if(!deg[i] && i!=n)
                q.push(i);
        }
    }
    int ans=0;
    q.push(n);
    while(!q.empty()){
        int at=q.front(); q.pop();
        dp[at]++;
        for(int &i:graph[at]){
            deg[i]--;
            if(dp[at]>dp[i]){
                go[i]=at;
                dp[i]=dp[at];
            }
            if(!deg[i])
                q.push(i);
        }
    }
    if(bad[1]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<dp[1]<<"\n";
    int at=1;
    while(at){
        cout<<at<<" ";
        at=go[at];
    }
}
