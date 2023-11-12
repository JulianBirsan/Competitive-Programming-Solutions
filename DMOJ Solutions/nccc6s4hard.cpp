#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
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
typedef double d;
typedef long double ld;

const int MAX=1e7+1;
int dp[MAX];

int solve(int x,int a,int b,int c,int d){
    x=max(x,0);
    if(x==0) return dp[x]=1;
    if(x<MAX) {
        if(dp[x]) return dp[x];
        return dp[x]=solve(x/a-b,a,b,c,d)+solve(x/c-d,a,b,c,d);
    }
    return solve(x/a-b,a,b,c,d)+solve(x/c-d,a,b,c,d);
}

int main(){
    IOS; fill(dp);
    int a,b,c,d,q,x;
    scan(a,b,c,d,q);
    dp[0]=1;
    FOR(i,0,q){
        scan(x);
        cout<<solve(x,a,b,c,d)<<"\n";
    }
}