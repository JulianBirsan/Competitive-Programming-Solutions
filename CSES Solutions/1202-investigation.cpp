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

vector<pii> graph[mxN];

ll dist[mxN],dp[mxN],mnl[mxN],mxl[mxN],seen[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a].pb({b,c});
    }
    fill(dist+2,dist+2+n,1e18);
    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({0,1}); dp[1]=1; mxl[1]=0; mnl[1]=0;
    while(!q.empty()){
        int at=q.top().second;
        q.pop();
        if(seen[at])
            continue;
        seen[at]=1;
        deb(at,dist[at],dp[at],mnl[at],mxl[at]);
        for(auto &[i,w]:graph[at]){
            if(dist[at]+w<dist[i]){
                dist[i]=dist[at]+w;
                dp[i]=dp[at];
                mnl[i]=mnl[at]+1;
                mxl[i]=mxl[at]+1;
                q.push({dist[i],i});
            } else if(dist[at]+w==dist[i]){
                dp[i]=(dp[i]+dp[at])%mod;
                maxa(mxl[i],mxl[at]+1);
                mina(mnl[i],mnl[at]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<dp[n]<<" "<<mnl[n]<<" "<<mxl[n]<<"\n";
}
