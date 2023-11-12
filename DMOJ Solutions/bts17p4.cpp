#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++) scan(v[i])
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef double db;
typedef long double ld;

const int MAX=1e5+5;

int dp[MAX],dist[MAX];
vector<pii> mud;
priority_queue<pii,vector<pii>,greater<pii> > q;

int n,m,j,p,ti;

int main(){
    IOS;
    scan(n,m,j);
    FOR(i,0,m){
        scan(p,ti);
        mud.push_back(pii(p,ti));
    }
    FOR(i,0,m+1) dp[i]=1e9;
    sort(rng(mud));
    for(int i=m;i>=0;i--){
        int loc=i==0 ? 0:mud[i-1].first;
        int tm=i==0 ? 0:mud[i-1].second;
        dist[i]=loc+j;
        while(!q.empty() && dist[i]<q.top().second) q.pop();
        if(n<dist[i]) dp[i]=tm;
        if(!q.empty()) dp[i]=min(dp[i],q.top().first);
        dp[i]=max(dp[i],tm);
        q.push(pii(dp[i],loc));
    }
    dp[0]=dp[0]==1e9 ? -1:dp[0];
    cout<<dp[0]<<"\n";
}