#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+5;

vector<int> graph[mxN];

ll dist[mxN],w,d,n,a,b,tots[mxN];

multiset<ll> all;

bool seen[mxN];

int arr[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>w>>d;
    
    for(int i=1;i<=n;i++) dist[i]=1e9;
    
    dist[n]=0;
    
    for(int i=0;i<w;i++){
        cin>>a>>b;
        graph[b].push_back(a);
    }
    priority_queue<pii,vector<pii>, greater<pii> > q;
    q.push(pii(0,n));
    
    while(!q.empty()){
        int at=q.top().second;
        q.pop();
        if(seen[at]) continue;
        seen[at]=true;
        for(int &i:graph[at]){
            if(dist[at]+1<dist[i]){
                dist[i]=dist[at]+1;
                q.push(pii(dist[i],i));
            }
        }
    }
    
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        tots[arr[i]]=dist[arr[i]]+i;
        all.insert(tots[arr[i]]);
    }
    
    // for(int i=1;i<=n;i++) cout<<tots[i]<<" ";
    // cout<<"\n";
    // for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    // cout<<"\n";
    
    while(d--){
        cin>>a>>b;
        a--; b--;
        all.erase(all.find(tots[arr[a]]));
        all.erase(all.find(tots[arr[b]]));
        tots[arr[a]]-=a;
        tots[arr[a]]+=b;
        tots[arr[b]]-=b;
        tots[arr[b]]+=a;
        all.insert(tots[arr[a]]);
        all.insert(tots[arr[b]]);
        // for(int i=1;i<=n;i++) cout<<tots[i]<<" ";
        // cout<<"\n";
        // for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
        // cout<<"\n";
        swap(arr[a],arr[b]);
        ll ans=*all.begin();
        cout<<ans<<"\n";
    }
}