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
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ldb;

const int mx=30*1000+1;

bool dp[31][mx];

int n,w;

void solve(){
    fill(dp);
    scan(n);
    int tot=0;
    dp[0][0]=1;
    FOR(i,1,n+1){
        scan(w);
        tot+=w;
        FOR(j,0,mx){
            dp[i][j]=dp[i-1][j];
            if(j>=w) dp[i][j]=dp[i][j]|dp[i-1][j-w];
        }
    }
    int ans=MAXN;
    FOR(i,0,tot+1){
        if(dp[n][i]) ans=min(ans,abs(tot-2*i));
    }
    cout<<ans<<"\n";
}

int main(){
    IOS;
    FOR(i,0,5) solve();
}