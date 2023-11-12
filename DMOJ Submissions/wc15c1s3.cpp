#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mxN=1e5+5,inf=1e16;

vector<pll> graph[mxN]; 

ll n,m,k,a,b,d,c[mxN],dist[mxN][2],seen[mxN];

bool comp(pll x,pll y){return dist[x.first][0]-dist[x.first][1]<dist[y.first][0]-dist[y.first][1];}

void dijkstra(int t){
    memset(seen,0,sizeof(seen));
    priority_queue<pll,vector<pll>,greater<pll> > q;
    dist[1][0]=0; dist[2][1]=0;
    
    q.push(pll(0,t+1));
    while(!q.empty()){
        int at=q.top().second;
        q.pop();
        if(seen[at]) continue;
        seen[at]=true;
        // cout<<at<<"\n";
        for(pll &i:graph[at]){
            ll u=i.first;
            ll w=i.second;
            if(dist[at][t]+w<dist[u][t]){
                dist[u][t]=dist[at][t]+w;
                q.push(pll(dist[u][t],u));
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<m;i++){
        cin>>a>>b>>d;
        graph[b].push_back(pll(a,d));
    }
    for(int i=1;i<=n;i++) dist[i][0]=dist[i][1]=inf;
    dijkstra(0); dijkstra(1);
    ll ans=0;
    ll cnt=0;
    vector<pll> two;
    for(int i=1;i<=n;i++){
        if(dist[i][0]==inf && dist[i][1]==inf && c[i]>0){
            cout<<-1<<"\n";
            return 0;
        }
        if(dist[i][0]<=dist[i][1]) {
            ans+=c[i]*dist[i][0];
        } else{
            if(dist[i][0]!=inf) two.push_back(pll(i,c[i]));
            ans+=c[i]*dist[i][1];
            cnt+=c[i];
        }
    }
    sort(two.begin(),two.end(),comp);
    for(pll &i:two){
        if(cnt<=k) break;
        if(cnt-i.second<=k){
            ll amount=cnt-k;
            ans-=amount*dist[i.first][1];
            ans+=amount*dist[i.first][0];
            cnt=k;
            break;
        } else{
            ans-=i.second*dist[i.first][1];
            ans+=i.second*dist[i.first][0];
            cnt-=i.second;
        }
    }
    if(cnt>k){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
}