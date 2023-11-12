#include <bits/stdc++.h>  

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=1e5+1;
const ll inf=1e12;

struct edge{
    ll to,w,t;  
};

vector<edge> graph[mxN];

int n,m,a,b,c;
ll dist[mxN],A,B,C;
bool seen[mxN];

bool check(int mx){
    for(int i=1;i<=n;i++) dist[i]=inf;
    memset(seen,0,sizeof(seen));
    
    priority_queue<pair<ll,ll> > q;
    q.push(pair<ll,ll>(0,A));
    dist[A]=0;
    while(!q.empty()){
        int at=q.top().second;
        q.pop();
        if(seen[at]) continue;
        seen[at]=true;
        for(edge i:graph[at]){
            if(i.t>mx) break;
            if(dist[at]+i.w<dist[i.to]){
                dist[i.to]=dist[at]+i.w;
                q.push(pair<ll,ll>(-dist[i.to],i.to));
            }
        }
    }
    if(dist[B]<C) return true;
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        graph[a].push_back((edge){b,c,i+1});
        graph[b].push_back((edge){a,c,i+1});
    }
    cin>>A>>B>>C;
    int l=1,r=m;
    if(A==B){
        cout<<0<<"\n";
        return 0;
    }
    ll ans=inf;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<(ans==inf?-1:ans)<<"\n";
}