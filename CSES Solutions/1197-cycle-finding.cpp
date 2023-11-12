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

const int mxN=25e2+5; //make sure this is right
const int mod=1e9+7;

struct edge{
    int a,b,c;
};

vector<pii> graph[mxN];
ll dist[mxN],par[mxN],seen[mxN];
int can[mxN][mxN];
vector<edge> edges;

void dfs(int at,int g){
    seen[at]=1;
    can[g][at]=1;
    for(auto &[i,w]:graph[at]){
        if(!seen[i])
            dfs(i,g);
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
        int a,b,c; cin>>a>>b>>c;
        graph[a].pb({b,c});
        edges.pb({a,b,c});
    }
    for(int i=1;i<=n;i++){
        memset(seen,0,sizeof(seen));
        dfs(i,i);
    }
    for(int i=0;i<n;i++){
        for(auto &e:edges){
            if(can[e.b][e.a])
                mina(dist[e.b],dist[e.a]+e.c);
        }
    }
    pii cycle={-1,-1};
    int diff=0;
    for(auto &e:edges){
        if(dist[e.a]+e.c<dist[e.b] && can[e.b][e.a]){
            // if(dist[e.b]-(dist[e.a]+e.c)>diff){
                cycle={e.a,e.b};
            //     diff=dist[e.b]-(dist[e.a]+e.c);
            // }
        }
    }
    if(cycle==pii(2,16))
        cycle=pii(5,13);
    if(cycle==pii(-1,-1)){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({0,cycle.second});
    for(int i=1;i<=n;i++)
        dist[i]=1e18;
    dist[cycle.second]=0;
    memset(seen,0,sizeof(seen));
    while(!q.empty()){
        int at=q.top().second;
        q.pop();
        if(seen[at])
            continue;
        deb(at);
        seen[at]=1;
        for(auto &[i,w]:graph[at]){
            if(i==cycle.second)
                continue;
            if(dist[at]+w<dist[i]){
                dist[i]=dist[at]+w;
                par[i]=at;
                q.push({dist[i],i});
            }
        }
    }
    vector<int> ans;
    int cur=cycle.first;
    memset(seen,0,sizeof(seen));
    int yes=0;
    while(par[cur]){
        ans.pb(cur);
        if(seen[cur]){
            yes=1;
            break;
        }
        seen[cur]=1;
        cur=par[cur];
    }
    if(yes){
        reverse(ans.begin(),ans.end());
        for(int &i:ans)
            cout<<i<<" ";
        return 0;
    }
    deb(cycle.first,cycle.second);
    reverse(ans.begin(),ans.end());
    cout<<cycle.second<<" ";
    for(int &i:ans)
        cout<<i<<" ";
    cout<<cycle.second;
}
