#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=5e5+1;

struct path{
    int u,v,w;
} cindy[mxN];

vector<pii> graph[mxN],rev[mxN];
int n,m,a,b,w,d;
bool seen[mxN];

vector<ll> dijkstra(int s,vector<pii> adj[]){
    memset(seen,0,sizeof(seen));
    vector<ll> dist; dist.assign(mxN,1e15);
    priority_queue<pll> q; q.push(pll(0,s));
    dist[s]=0;
    while(!q.empty()){
        int at=q.top().second; q.pop();
        if(seen[at]) continue;
        seen[at]=true;
        for(pii i:adj[at]){
            if(dist[at]+i.second<dist[i.first]){
                dist[i.first]=dist[at]+i.second;
                q.push(pll(-dist[i.first],i.first));
            }
        }
    }
    return dist;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        graph[a].push_back(pii(b,w));
        rev[b].push_back(pii(a,w));
    }
    cin>>d;
    for(int i=0;i<d;i++){
        cin>>cindy[i].u>>cindy[i].v>>cindy[i].w;
    }
    vector<ll> forw=dijkstra(1,graph);
    vector<ll> back=dijkstra(n,rev);
    ll ans=forw[n];
    for(int i=0;i<d;i++){
        ans=min(ans,forw[cindy[i].u]+back[cindy[i].v]+cindy[i].w);
    }
    cout<<(ans==1e15?-1:ans)<<"\n";
}