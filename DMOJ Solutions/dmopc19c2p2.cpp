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

const int MAX=501;

ll dp[MAX][MAX];

int main(){
    IOS;
    int n,m;
    scan(n,m);
    FOR(i,0,n+1) FOR(j,0,m+1) dp[i][j]=MAXN;
    dp[1][0]=dp[0][1]=0;
    FOR(i,1,n+1) FOR(j,1,m+1) scan(dp[i][j]);
    FOR(i,1,n+1) FOR(j,1,m+1) dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n][m]<<"\n";
}