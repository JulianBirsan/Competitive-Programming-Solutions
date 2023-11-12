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
typedef double d;
typedef long double ld;

const int MAX=1e6+1;

int dp[MAX],arr[MAX];

int main(){
    IOS;
    int n,d; scan(n,d);
    FOR(i,1,n+1) dp[i]=MAXN;
    FOR(i,1,n+1) scan(arr[i]);
    dp[1]=0;
    FOR(i,1,n+1){
        dp[i]+=arr[i];
        for(int j=min(n,i+d);j>=i+1;j--){
            if(dp[i]<dp[j]) dp[j]=dp[i];
            else break;
        }
    }
    cout<<dp[n]<<"\n";
}