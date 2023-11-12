#include <bits/stdc++.h>

using namespace std;

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define SETALL(x,val) FOR(i,0,x.size()) x[i]=val
#define fill(x) memset(x,0,sizeof(x))
#define IOS cin.sync_with_stdio(0),cin.tie()
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef double d;
typedef long double ld;
ll mod=1000000007;

ll ans=0;
ll sum[100001];
ll num[100001];
int indeg[100001];
vector<vi> graph(100001);

int main(){
    IOS; fill(sum); fill(num); fill(indeg);
    int n,m; cin>>n>>m;
    int x,y;
    FOR(i,0,m){
        cin>>x>>y;
        graph[x].push_back(y);
        indeg[y]++;
    }
    priority_queue<int,vi,greater<int> > q;
    FOR(i,1,n+1){
        if(indeg[i]==0){
            num[i]=1; q.push(i);
        }
    }
    while(!q.empty()){
        int i=q.top(); q.pop();
        for(int u:graph[i]){
            num[u]=(num[i]+num[u])%mod;
            sum[u]=(sum[u]+sum[i]+num[i])%mod;
            indeg[u]--;
            if(indeg[u]==0) q.push(u);
        }
    }
    FOR(i,1,n+1){
        if(graph[i].size()==0){
            ans=(ans+sum[i])%mod;
        }
    }
    cout<<ans<<"\n";
}