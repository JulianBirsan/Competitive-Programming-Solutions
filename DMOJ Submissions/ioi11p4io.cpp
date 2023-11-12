#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e5+5,inf=1e9+10;

vector<pii> graph[mxN];

int dist[mxN][2],seen[mxN],n,m,k,a,b,w;

priority_queue<pii,vector<pii>, greater<pii> > q;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) dist[i][0]=dist[i][1]=inf;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        graph[a].push_back(pii(b,w));
        graph[b].push_back(pii(a,w));
    }
    for(int i=0;i<k;i++){
        cin>>a;
        q.push(pii(0,a));
        dist[a][1]=0;
    }
    while(!q.empty()){
        int at=q.top().second;
        q.pop();
        if(seen[at]) continue;
        seen[at]=true;
        for(pii &i:graph[at]){
            if(dist[at][1]+i.second < dist[i.first][1]){
                dist[i.first][1]=dist[at][1]+i.second;
                if(dist[i.first][1]<dist[i.first][0]) swap(dist[i.first][1],dist[i.first][0]);
                q.push(pii(dist[i.first][1],i.first));
            }
        }
    }
    cout<<dist[0][1]<<"\n";
}