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

vector<int> graph[mxN],condense[mxN];
ll val[mxN],dp[mxN],deg[mxN];

struct TARJAN{
    ll id[mxN],onStk[mxN],seen[mxN],low[mxN],comp[mxN],cc=0,cur=0,compsz[mxN];
    stack<int> stk;
    void tarjan(int at){
        onStk[at]=1; seen[at]=1;
        id[at]=low[at]=++cur;
        stk.push(at);
        for(int &i:graph[at]){
            if(!seen[i]){
                tarjan(i);
                mina(low[at],low[i]);
            } else if(onStk[i]){
                mina(low[at],id[i]);
            }
        }
        if(low[at]==id[at]){
            int node; cc++;
            do{
                node=stk.top();
                stk.pop();
                comp[node]=cc;
                onStk[node]=0;
                compsz[cc]+=val[node];
            } while(node!=at);
        }
    }  
    void transpose(int n){
        for(int i=1;i<=n;i++){
            for(int &j:graph[i]){
                if(comp[i]!=comp[j]){
                    deg[comp[i]]++;
                    condense[comp[j]].pb(comp[i]);
                }
            }
        }
    }
} scc;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        if(!scc.seen[i]) scc.tarjan(i);
    }
    scc.transpose(n);
    queue<int> q;
    for(int i=1;i<=scc.cc;i++){
        if(!deg[i]) q.push(i);
    }
    ll ans=0;
    while(!q.empty()){
        int at=q.front();
        q.pop();
        dp[at]+=scc.compsz[at];
        for(int &i:condense[at]){
            deg[i]--;
            maxa(dp[i],dp[at]);
            if(!deg[i]) q.push(i);
        }
        maxa(ans,dp[at]);
    }
    cout<<ans<<"\n";
}
